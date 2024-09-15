#include "VelocityVector.h"
#include <numbers>

double VelocityVector::get_heading() const {
    auto angle = std::atan2(east_west, north_south);
    if (angle < 0) {
        angle += 2 * std::numbers::pi;
    }
    return angle;
}

double VelocityVector::angle_between(const VelocityVector& other) const {
    if (get_magnitude() == 0.0 || other.get_magnitude() == 0.0) {
        return 0.0;
    }
    // cross = ad - bc

    double dot_product = north_south * other.north_south + east_west * other.east_west;
    double cross = north_south * other.east_west - east_west * other.north_south;
    if (cross < 0) {
        return std::acos(dot_product / (get_magnitude() * other.get_magnitude()));
    }
    return -std::acos(dot_product / (get_magnitude() * other.get_magnitude()));
}