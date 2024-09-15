#include "Aerobody.h"

#include <numbers>   // 2π = std::numbers::pi * 2

ApparentWindVector Aerobody::get_wind(const VelocityVector& reported_wind, const VelocityVector& car_velocity) {
    VelocityVector relative_wind = -reported_wind - car_velocity;
    return { relative_wind.get_magnitude(), (-car_velocity).angle_between(relative_wind) };
}

double Aerobody::aerodynamic_drag(const ApparentWindVector& apparent_wind, double air_density) const {
    return 0.5 * air_density * apparent_wind.speed * std::cos(apparent_wind.yaw) * apparent_wind.speed
         * std::cos(apparent_wind.yaw) * drag_coefficient * frontal_area;
}