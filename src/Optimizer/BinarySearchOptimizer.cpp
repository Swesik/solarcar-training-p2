#include "BinarySearchOptimizer.h"

#include <limits>
#include <optional>

#include "Optimizer/Optimizer.h"
#include "RaceConfig/RaceSchedule/RaceSchedule.h"
#include "RaceConfig/Route/Route.h"
#include "RaceConfig/Weather/Weather.h"
#include "RaceRunner/RaceRunner.h"
#include "SolarCar/SolarCar.h"

Optimizer::OptimizationOutput binary_search_helper(Optimizer::OptimizationOutput& lower,
                                                   Optimizer::OptimizationOutput& higher, const SolarCar& car,
                                                   const Route& route, const Weather& weather,
                                                   const RaceSchedule& schedule, double precision) {
    if (higher.speed - lower.speed < precision) {
        return higher;
    }
    double speed = (lower.speed + higher.speed) / 2;
    std::optional<double> race_time = RaceRunner::calculate_racetime(car, route, weather, schedule, speed);
    Optimizer::OptimizationOutput med = { race_time.value_or(std::numeric_limits<double>::infinity()), speed };
    if (!race_time) {
        return binary_search_helper(lower, med, car, route, weather, schedule, precision);
    }
    return binary_search_helper(med, higher, car, route, weather, schedule, precision);
}

std::optional<Optimizer::OptimizationOutput> BinarySearchOptimizer::optimize_race() const {
    std::optional<double> min_time = RaceRunner::calculate_racetime(car, route, weather, schedule, minimum_speed);

    Optimizer::OptimizationOutput min = { min_time.value_or(std::numeric_limits<double>::infinity()), minimum_speed };

    std::optional<double> max_time = RaceRunner::calculate_racetime(car, route, weather, schedule, maximum_speed);
    Optimizer::OptimizationOutput max = { max_time.value_or(std::numeric_limits<double>::infinity()), maximum_speed };

    return std::make_optional(binary_search_helper(min, max, car, route, weather, schedule, precision));
}