#include "RaceRunner.h"

#include <cassert>
#include <optional>

#include <sys/errno.h>

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
    BatteryState battery_state(car.battery.get_capacity());
    RaceSegmentRunner segment_runner(car);
    auto segment_iter = route.get_segments()->begin();
    double total_time = 0.0;

    for (size_t curr_day = 0; curr_day < schedule.size(); ++curr_day) {
        // morning charge
        if (curr_day != 0) {
            double power_gain = calculate_static_charging_gain(car, weather, segment_iter->weather_station,
                                                               schedule[curr_day].morning_charging_start_time,
                                                               schedule[curr_day].morning_charging_end_time);
            battery_state.update_energy_remaining(power_gain);
        }

        // race time
        double elapsed_time = 0;
        for (int time = schedule[curr_day].race_start_time; time < schedule[curr_day].race_end_time;
             time += elapsed_time) {
            elapsed_time = segment_iter->distance / speed;
            total_time += elapsed_time;

            // update power
            std::optional<double> net_power = segment_runner.calculate_power_net(
              *segment_iter, weather.get_weather_during(segment_iter->weather_station, time, time + elapsed_time),
              car.battery.state_of_charge(battery_state.get_energy_remaining()), speed);
            if (!net_power) {
                return std::nullopt;
            }
            battery_state.update_energy_remaining(*net_power * elapsed_time);

            //
            if (battery_state.get_energy_remaining() <= 0.0) {
                return std::nullopt;
            }
            if (segment_iter->end_condition == SegmentEndCondition::CONTROL_STOP) {
                double power_gain
                  = calculate_static_charging_gain(car, weather, segment_iter->weather_station, time + elapsed_time,
                                                   time + elapsed_time + CHARGE_DURATION);

                battery_state.update_energy_remaining(power_gain);
                total_time += CHARGE_DURATION;
                elapsed_time += CHARGE_DURATION;
            }
            segment_iter++;

            // race finished
            if (segment_iter == route.get_segments()->end()) {
                assert(segment_iter->end_condition == SegmentEndCondition::FINISH_LINE);
                return std::make_optional(total_time);
            }
        }

        // evening charge
        double power_gain = calculate_static_charging_gain(car, weather, segment_iter->weather_station,
                                                           schedule[curr_day].evening_charging_start_time,
                                                           schedule[curr_day].evening_charging_end_time);
        battery_state.update_energy_remaining(power_gain);
    }


    return std::nullopt;
}
