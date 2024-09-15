#include "Tire.h"

#include <optional>

#include "math.h"


double Tire::rolling_resistance(double tire_load, double vehicle_speed, std::optional<double> tire_pressure) const {
    // P^α * L^β * (a + bV + cV^2)
    vehicle_speed *= 3.6;   // convert to km/h
    return pow(tire_pressure.value_or(tire_pressure_at_stc), alpha) * pow(tire_load, beta)
         * (a + b * vehicle_speed + c * vehicle_speed * vehicle_speed);
}