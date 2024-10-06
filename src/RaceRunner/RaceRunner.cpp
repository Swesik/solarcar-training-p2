#include "RaceRunner.h"

#include <cassert>
#include <optional>

#include "RaceConfig/RaceSchedule/RaceSchedule.h"
#include "RaceConfig/Route/RouteSegment.h"
#include "RaceSegmentRunner/RaceSegmentRunner.h"
#include "SolarCar/Battery/Battery.h"
#include "SolarCar/Battery/BatteryState.h"
#include "SolarCar/SolarCar.h"

const double FIVE_MIN = 300.0;
const double SEC_PER_HOUR = 3600.0;
const double CHARGE_DURATION = 30 * 60;

double RaceRunner::calculate_static_charging_gain(const SolarCar& car, const Weather& weather, double weather_station,
                                                  double start_time, double end_time) {
    double total_gain = 0.0;
    for (double time = start_time; time < end_time; time += FIVE_MIN) {
        // total_gain += car.array.power_in(weather.get_weather_at(weather_station, time).irradiance);
        double weather_end_time = std::min(end_time, time + FIVE_MIN);
        total_gain += car.array.power_in(weather.get_weather_during(weather_station, time, weather_end_time).irradiance)
                    * (weather_end_time - time) / SEC_PER_HOUR;
    }
    return total_gain;
}

std::optional<double> RaceRunner::calculate_racetime(const SolarCar& car, const Route& route, const Weather& weather,
                                                     const RaceSchedule& schedule, double speed) {
    RaceSegmentRunner segment_runner(car);

    double stored_charge = car.battery.get_capacity();
    double total_time = 0.0;

    uint32_t curr_day = 0;
    double daily_time = 0.0;

    const std::vector<RouteSegment>* segment_vec_ptr = route.get_segments();

    for (auto i = segment_vec_ptr->begin(); i != segment_vec_ptr->end(); ++i) {
        // handle morning charge
        if (curr_day != 0 && daily_time < schedule[curr_day].morning_charging_end_time) {
            double power_gain = calculate_static_charging_gain(car, weather, i->weather_station,
                                                               schedule[curr_day].morning_charging_start_time,
                                                               schedule[curr_day].morning_charging_end_time);

            // if (!power_gain) {
            //     return std::nullopt;
            // }
            // stored_charge = std::min(power_gain + stored_charge, car.battery.get_capacity());
            stored_charge = power_gain + stored_charge;
            daily_time = schedule[curr_day].race_start_time;
        } else if (curr_day == 0 && daily_time < schedule[curr_day].morning_charging_end_time) {
            daily_time = schedule[curr_day].race_start_time;
        }

        // assume car can run for the whole segment
        if (schedule[curr_day].race_start_time <= daily_time && daily_time < schedule[curr_day].race_end_time) {
            // race the segment
            double elapsed_time = i->distance / speed;
            std::optional<double> net_power = segment_runner.calculate_power_net(
              *i, weather.get_weather_during(i->weather_station, daily_time, daily_time + elapsed_time),
              car.battery.state_of_charge(stored_charge), speed);
            if (!net_power) {
                return std::nullopt;
            }
            // stored_charge += *net_power * SEC_PER_HOUR;
            stored_charge += *net_power;
            daily_time += elapsed_time;

            // charge at checkpoint
            if (i->end_condition == SegmentEndCondition::CONTROL_STOP) {
                double power_gain = calculate_static_charging_gain(car, weather, i->weather_station, daily_time,
                                                                   daily_time + CHARGE_DURATION);

                // stored_charge = std::min(*power_gain + stored_charge, car.battery.get_capacity());
                stored_charge = power_gain + stored_charge;
                // remaining_charge_time = CHARGE_DURATION - charge_time;
                daily_time += CHARGE_DURATION;
            }

            // race is finished
            if (i->end_condition == SegmentEndCondition::FINISH_LINE) {
                std::cout << "curr day = " << curr_day << "\n";
                total_time += elapsed_time;
                return total_time;
            } else if (daily_time < schedule[curr_day].race_end_time) {
                total_time += elapsed_time;
                continue;   // go to next segment
            }
            daily_time = schedule[curr_day].evening_charging_start_time;
            total_time += elapsed_time;
            std::cout << "curr time = " << total_time;
            // total_time += schedule[curr_day].race_end_time - schedule[curr_day].race_start_time;
        }

        // handle evening charge
        if (schedule[curr_day].evening_charging_start_time <= daily_time
            && daily_time < schedule[curr_day].evening_charging_end_time) {
            double power_gain = calculate_static_charging_gain(car, weather, i->weather_station,
                                                               schedule[curr_day].evening_charging_start_time,
                                                               schedule[curr_day].morning_charging_end_time);

            stored_charge = std::min(power_gain + stored_charge, car.battery.get_capacity());

            daily_time = 0.0;
            curr_day++;
            if (curr_day >= schedule.size()) {
                return std::nullopt;
            }
        }
    }
    return std::nullopt;
}