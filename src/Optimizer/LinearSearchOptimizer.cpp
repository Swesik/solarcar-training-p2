#include "LinearSearchOptimizer.h"

#include <limits>

#include "Optimizer/Optimizer.h"
#include "RaceRunner/RaceRunner.h"

LinearSearchOptimizer::LinearSearchOptimizer(SolarCar const& car, Weather const& weather, Route const& route,
                                             RaceSchedule const& race_schedule)
    : car(car)
    , weather(weather)
    , route(route)
    , schedule(race_schedule) {}

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