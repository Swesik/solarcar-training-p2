#include "Motor.h"

double Motor::power_consumed(double angular_speed, double torque) const {
    double p_loss = eddy_current_loss_coefficient * angular_speed + hysteresis_loss;
    return angular_speed * torque + p_loss;
}