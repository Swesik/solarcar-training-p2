#include "LinearSearchOptimizer.h"

#include <limits>

#include "Optimizer/Optimizer.h"
#include "RaceRunner/RaceRunner.h"

std::optional<Optimizer::OptimizationOutput> LinearSearchOptimizer::optimize_race() const {
    Optimizer::OptimizationOutput best = { std::numeric_limits<double>::infinity(), minimum_speed };
    for (double speed = minimum_speed; speed <= maximum_speed; speed += speed_step) {
        std::optional<double> race_time = RaceRunner::calculate_racetime(car, route, weather, schedule, speed);
        if (!race_time) {
            continue;
        }
        if (*race_time < best.racetime) {
            best = { *race_time, speed };
        }
    }
    return best;
}