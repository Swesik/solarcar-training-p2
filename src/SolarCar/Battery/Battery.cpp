#include "Battery.h"

#include <optional>
#include <cmath>

double Battery::state_of_charge(double energy_remaining) const {
    return energy_remaining/energy_capacity;
}

double Battery::current_voltage(double state_of_charge) const {
    return (max_voltage - min_voltage) * state_of_charge + min_voltage;
}

std::optional<double> Battery::power_loss(double net_power_demanded, double state_of_charge) const {
    double voltage = current_voltage(state_of_charge);
    double det = voltage * voltage + 4 * pack_resistance * net_power_demanded;
    if (det < 0){
        return std::nullopt;
    }
    double current = (-voltage + std::sqrt(det)) / ( 2 * pack_resistance);
    return std::optional<double>{current * current * pack_resistance};
}