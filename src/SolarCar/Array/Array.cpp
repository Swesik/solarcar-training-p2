#include "Array.h"

double Array::power_in(double irradiance) const {
    return array_efficiency * array_area * irradiance / 100;
}