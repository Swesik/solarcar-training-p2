#include "RaceSegmentRunner.h"
#include <cmath>
#include <optional>

double RaceSegmentRunner::calculate_resistive_force(
		const RouteSegment& route_segment, const WeatherDataPoint& weather_data, double speed) const{

    double gravity = car.mass * route_segment.gravity_times_sine_road_incline_angle;

    auto car_velocity = VelocityVector::from_polar_components(speed,route_segment.heading);
    auto apparent_wind = Aerobody::get_wind(weather_data.wind, car_velocity);
    double drag = car.aerobody.aerodynamic_drag(apparent_wind, weather_data.air_density);

    double weight = car.mass * route_segment.gravity;
    double rr = car.tire.rolling_resistance(weight, speed);

    return drag + rr + gravity;
}

double RaceSegmentRunner::calculate_power_out(
		const RouteSegment& route_segment, const WeatherDataPoint& weather_data, double speed) const{
    double resistive_force = calculate_resistive_force(route_segment, weather_data, speed);
    double motor_demand = car.motor.power_consumed(speed/car.wheel_radius, resistive_force * car.wheel_radius);
    return motor_demand;
}
double RaceSegmentRunner::calculate_power_in([[maybe_unused]] const RouteSegment& route_segment, const WeatherDataPoint& weather_data) const{
    return car.array.power_in(weather_data.irradiance);
}

std::optional<double> RaceSegmentRunner::calculate_power_net(const RouteSegment& route_segment, const WeatherDataPoint& weather_data,
		double state_of_charge, double speed) const{
    
    double net_power_demanded =  calculate_power_in(route_segment, weather_data) - calculate_power_out(route_segment, weather_data, speed);
    auto battery_loss = car.battery.power_loss(-net_power_demanded, state_of_charge);
    return battery_loss ? std::make_optional(net_power_demanded - *battery_loss) : std::nullopt;
}