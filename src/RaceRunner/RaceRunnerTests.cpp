#include <cmath>
#include <numbers>

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include "RaceRunner.h"
#include "Tools/RootDirectory.h"

using Catch::Matchers::WithinAbs;
using Catch::Matchers::WithinRel;

constexpr double EPSILON = 0.001;   // %
constexpr double RT_DELTA = 500;    // seconds

namespace {
const std::string root_directory = get_root_directory();
const std::string route_file = root_directory + "/data/Route/route.csv";
const std::string weather_file = root_directory + "/data/Weather/Australia/August/2007.csv";
const std::string schedule_file = root_directory + "/data/Schedule/August/Schedule2007.toml";
const std::string weather_stations_file = root_directory + "/data/Stations/australia_stations.csv";
}   // namespace

TEST_CASE("RaceSegmentRunner: calculate_static_charging_gain", "[RaceSegmentRunner]") {
    const WeatherStations weather_stations(weather_stations_file);
    const RaceSchedule schedule((ConfigFile::from_path(schedule_file).value()));
    const Route route(route_file, weather_stations);
    const Weather weather(weather_file, weather_stations);
    SECTION("Random Test 0") {
        constexpr double drag_coefficient = 0.00439404;
        constexpr double frontal_area = 7.79174;
        constexpr double array_area = 6.93127;
        constexpr double array_efficiency = 23.6479;
        constexpr double energy_capacity = 5113.83;
        constexpr double min_voltage = 144.313;
        constexpr double max_voltage = 161.38;
        constexpr double resistance = 0.34488;
        constexpr double hysteresis_loss = 1.2205;
        constexpr double eddy_current_loss_coefficient = 0.00498847;
        constexpr double alpha = 2.43281;
        constexpr double beta = 3.40996;
        constexpr double a = -1.54353;
        constexpr double b = 3.22708e-06;
        constexpr double c = -0.701633;
        constexpr double pressure_at_stc = 154.621;
        constexpr double mass = 103.912;
        constexpr double wheel_radius = 0.118738;
        const auto aerobody = Aerobody(drag_coefficient, frontal_area);
        const auto array = Array(array_area, array_efficiency);
        const auto battery = Battery(energy_capacity, resistance, min_voltage, max_voltage);
        const auto motor = Motor(hysteresis_loss, eddy_current_loss_coefficient);
        const auto tire = Tire(SaeJ2452Coefficients { alpha, beta, a, b, c }, pressure_at_stc);
        const SolarCar car(aerobody, array, battery, motor, tire, mass, wheel_radius);
        constexpr double start_time = 1187940600.00000;
        constexpr double end_time = 1187955000.00000;
        constexpr double expected = 444.84;
        const double result = RaceRunner::calculate_static_charging_gain(
          car, weather, route.get_segment(12).weather_station, start_time, end_time);
        REQUIRE_THAT(result, WithinRel(expected, EPSILON));
    }
    SECTION("Random Test 1") {
        constexpr double drag_coefficient = 0.00080379;
        constexpr double frontal_area = 7.0252;
        constexpr double array_area = 8.0447;
        constexpr double array_efficiency = 24.814;
        constexpr double energy_capacity = 4632.5;
        constexpr double min_voltage = 108.55;
        constexpr double max_voltage = 131.66;
        constexpr double resistance = 0.10803;
        constexpr double hysteresis_loss = 1.4165;
        constexpr double eddy_current_loss_coefficient = 0.035928;
        constexpr double alpha = -2.1274;
        constexpr double beta = -4.9921;
        constexpr double a = 3.5717;
        constexpr double b = -7.1982e-06;
        constexpr double c = 0.32592;
        constexpr double pressure_at_stc = 177.93;
        constexpr double mass = 198.08;
        constexpr double wheel_radius = 0.10293;
        const auto aerobody = Aerobody(drag_coefficient, frontal_area);
        const auto array = Array(array_area, array_efficiency);
        const auto battery = Battery(energy_capacity, resistance, min_voltage, max_voltage);
        const auto motor = Motor(hysteresis_loss, eddy_current_loss_coefficient);
        const auto tire = Tire(SaeJ2452Coefficients { alpha, beta, a, b, c }, pressure_at_stc);
        const SolarCar car(aerobody, array, battery, motor, tire, mass, wheel_radius);
        constexpr double start_time = 1187940600.00000;
        constexpr double end_time = 1187955000.00000;
        constexpr double expected = 541.77;
        const double result = RaceRunner::calculate_static_charging_gain(
          car, weather, route.get_segment(12).weather_station, start_time, end_time);
        REQUIRE_THAT(result, WithinRel(expected, EPSILON));
    }
    SECTION("Random Test 2") {
        constexpr double drag_coefficient = 0.0099485;
        constexpr double frontal_area = 2.635;
        constexpr double array_area = 8.4038;
        constexpr double array_efficiency = 16.057;
        constexpr double energy_capacity = 6782.3;
        constexpr double min_voltage = 84.246;
        constexpr double max_voltage = 167.55;
        constexpr double resistance = 0.91089;
        constexpr double hysteresis_loss = 4.5293;
        constexpr double eddy_current_loss_coefficient = 0.015292;
        constexpr double alpha = 2.3686;
        constexpr double beta = 7.7977;
        constexpr double a = 9.08;
        constexpr double b = 3.9199e-06;
        constexpr double c = -0.68742;
        constexpr double pressure_at_stc = 111.2;
        constexpr double mass = 211.1;
        constexpr double wheel_radius = 0.449;
        const auto aerobody = Aerobody(drag_coefficient, frontal_area);
        const auto array = Array(array_area, array_efficiency);
        const auto battery = Battery(energy_capacity, resistance, min_voltage, max_voltage);
        const auto motor = Motor(hysteresis_loss, eddy_current_loss_coefficient);
        const auto tire = Tire(SaeJ2452Coefficients { alpha, beta, a, b, c }, pressure_at_stc);
        const SolarCar car(aerobody, array, battery, motor, tire, mass, wheel_radius);
        constexpr double start_time = 1187940600.00000;
        constexpr double end_time = 1187955000.00000;
        constexpr double expected = 366.21;
        const double result = RaceRunner::calculate_static_charging_gain(
          car, weather, route.get_segment(12).weather_station, start_time, end_time);
        REQUIRE_THAT(result, WithinRel(expected, EPSILON));
    }
    SECTION("Random Test 3") {
        constexpr double drag_coefficient = 0.0092253;
        constexpr double frontal_area = 9.6912;
        constexpr double array_area = 5.2805;
        constexpr double array_efficiency = 16.436;
        constexpr double energy_capacity = 4529.2;
        constexpr double min_voltage = 106.27;
        constexpr double max_voltage = 162.44;
        constexpr double resistance = 0.030115;
        constexpr double hysteresis_loss = 1.7568;
        constexpr double eddy_current_loss_coefficient = 0.0012791;
        constexpr double alpha = 4.1095;
        constexpr double beta = 1.4942;
        constexpr double a = 8.2659;
        constexpr double b = 8.7382e-06;
        constexpr double c = -0.19676;
        constexpr double pressure_at_stc = 178.64;
        constexpr double mass = 120.95;
        constexpr double wheel_radius = 0.34854;
        const auto aerobody = Aerobody(drag_coefficient, frontal_area);
        const auto array = Array(array_area, array_efficiency);
        const auto battery = Battery(energy_capacity, resistance, min_voltage, max_voltage);
        const auto motor = Motor(hysteresis_loss, eddy_current_loss_coefficient);
        const auto tire = Tire(SaeJ2452Coefficients { alpha, beta, a, b, c }, pressure_at_stc);
        const SolarCar car(aerobody, array, battery, motor, tire, mass, wheel_radius);
        constexpr double start_time = 1187940600.00000;
        constexpr double end_time = 1187955000.00000;
        constexpr double expected = 235.54;
        const double result = RaceRunner::calculate_static_charging_gain(
          car, weather, route.get_segment(12).weather_station, start_time, end_time);
        REQUIRE_THAT(result, WithinRel(expected, EPSILON));
    }
    SECTION("Random Test 4") {
        constexpr double drag_coefficient = 0.0094797;
        constexpr double frontal_area = 3.5055;
        constexpr double array_area = 8.5195;
        constexpr double array_efficiency = 28.267;
        constexpr double energy_capacity = 6206.4;
        constexpr double min_voltage = 83.625;
        constexpr double max_voltage = 98.049;
        constexpr double resistance = 0.89804;
        constexpr double hysteresis_loss = 3.5055;
        constexpr double eddy_current_loss_coefficient = 0.0089862;
        constexpr double alpha = -2.4396;
        constexpr double beta = -4.6381;
        constexpr double a = -3.4839;
        constexpr double b = -4.8519e-06;
        constexpr double c = -0.25802;
        constexpr double pressure_at_stc = 151.92;
        constexpr double mass = 240.04;
        constexpr double wheel_radius = 0.24571;
        const auto aerobody = Aerobody(drag_coefficient, frontal_area);
        const auto array = Array(array_area, array_efficiency);
        const auto battery = Battery(energy_capacity, resistance, min_voltage, max_voltage);
        const auto motor = Motor(hysteresis_loss, eddy_current_loss_coefficient);
        const auto tire = Tire(SaeJ2452Coefficients { alpha, beta, a, b, c }, pressure_at_stc);
        const SolarCar car(aerobody, array, battery, motor, tire, mass, wheel_radius);
        constexpr double start_time = 1187940600.00000;
        constexpr double end_time = 1187955000.00000;
        constexpr double expected = 653.56;
        const double result = RaceRunner::calculate_static_charging_gain(
          car, weather, route.get_segment(12).weather_station, start_time, end_time);
        REQUIRE_THAT(result, WithinRel(expected, EPSILON));
    }
    SECTION("Random Test 5") {
        constexpr double drag_coefficient = 0.003246;
        constexpr double frontal_area = 4.5961;
        constexpr double array_area = 9.2718;
        constexpr double array_efficiency = 28.86;
        constexpr double energy_capacity = 4324.3;
        constexpr double min_voltage = 90.91;
        constexpr double max_voltage = 165.35;
        constexpr double resistance = 0.22701;
        constexpr double hysteresis_loss = 2.3665;
        constexpr double eddy_current_loss_coefficient = 0.046719;
        constexpr double alpha = -5.0143;
        constexpr double beta = -7.3296;
        constexpr double a = -6.3048;
        constexpr double b = 4.5086e-06;
        constexpr double c = -0.92742;
        constexpr double pressure_at_stc = 139.33;
        constexpr double mass = 117.28;
        constexpr double wheel_radius = 0.2098;
        const auto aerobody = Aerobody(drag_coefficient, frontal_area);
        const auto array = Array(array_area, array_efficiency);
        const auto battery = Battery(energy_capacity, resistance, min_voltage, max_voltage);
        const auto motor = Motor(hysteresis_loss, eddy_current_loss_coefficient);
        const auto tire = Tire(SaeJ2452Coefficients { alpha, beta, a, b, c }, pressure_at_stc);
        const SolarCar car(aerobody, array, battery, motor, tire, mass, wheel_radius);
        constexpr double start_time = 1187940600.00000;
        constexpr double end_time = 1187955000.00000;
        constexpr double expected = 726.21;
        const double result = RaceRunner::calculate_static_charging_gain(
          car, weather, route.get_segment(12).weather_station, start_time, end_time);
        REQUIRE_THAT(result, WithinRel(expected, EPSILON));
    }
    SECTION("Random Test 6") {
        constexpr double drag_coefficient = 0.0054703;
        constexpr double frontal_area = 9.5351;
        constexpr double array_area = 7.8823;
        constexpr double array_efficiency = 24.808;
        constexpr double energy_capacity = 2803.6;
        constexpr double min_voltage = 100.85;
        constexpr double max_voltage = 102.53;
        constexpr double resistance = 0.22294;
        constexpr double hysteresis_loss = 2.7363;
        constexpr double eddy_current_loss_coefficient = 0.021545;
        constexpr double alpha = 9.3011;
        constexpr double beta = -5.2397;
        constexpr double a = -5.1174;
        constexpr double b = 5.6597e-06;
        constexpr double c = -0.85737;
        constexpr double pressure_at_stc = 190.53;
        constexpr double mass = 160.28;
        constexpr double wheel_radius = 0.19887;
        const auto aerobody = Aerobody(drag_coefficient, frontal_area);
        const auto array = Array(array_area, array_efficiency);
        const auto battery = Battery(energy_capacity, resistance, min_voltage, max_voltage);
        const auto motor = Motor(hysteresis_loss, eddy_current_loss_coefficient);
        const auto tire = Tire(SaeJ2452Coefficients { alpha, beta, a, b, c }, pressure_at_stc);
        const SolarCar car(aerobody, array, battery, motor, tire, mass, wheel_radius);
        constexpr double start_time = 1187940600.00000;
        constexpr double end_time = 1187955000.00000;
        constexpr double expected = 530.69;
        const double result = RaceRunner::calculate_static_charging_gain(
          car, weather, route.get_segment(12).weather_station, start_time, end_time);
        REQUIRE_THAT(result, WithinRel(expected, EPSILON));
    }
    SECTION("Random Test 7") {
        constexpr double drag_coefficient = 0.0096523;
        constexpr double frontal_area = 4.0483;
        constexpr double array_area = 4.9728;
        constexpr double array_efficiency = 18.43;
        constexpr double energy_capacity = 3510.4;
        constexpr double min_voltage = 135.41;
        constexpr double max_voltage = 166.53;
        constexpr double resistance = 0.14822;
        constexpr double hysteresis_loss = 4.1487;
        constexpr double eddy_current_loss_coefficient = 0.011827;
        constexpr double alpha = -0.69319;
        constexpr double beta = 0.17257;
        constexpr double a = -1.4139;
        constexpr double b = 7.6849e-06;
        constexpr double c = -0.52253;
        constexpr double pressure_at_stc = 150.7;
        constexpr double mass = 192.15;
        constexpr double wheel_radius = 0.24524;
        const auto aerobody = Aerobody(drag_coefficient, frontal_area);
        const auto array = Array(array_area, array_efficiency);
        const auto battery = Battery(energy_capacity, resistance, min_voltage, max_voltage);
        const auto motor = Motor(hysteresis_loss, eddy_current_loss_coefficient);
        const auto tire = Tire(SaeJ2452Coefficients { alpha, beta, a, b, c }, pressure_at_stc);
        const SolarCar car(aerobody, array, battery, motor, tire, mass, wheel_radius);
        constexpr double start_time = 1187940600.00000;
        constexpr double end_time = 1187955000.00000;
        constexpr double expected = 248.72;
        const double result = RaceRunner::calculate_static_charging_gain(
          car, weather, route.get_segment(12).weather_station, start_time, end_time);
        REQUIRE_THAT(result, WithinRel(expected, EPSILON));
    }
    SECTION("Random Test 8") {
        constexpr double drag_coefficient = 0.0070069;
        constexpr double frontal_area = 7.7258;
        constexpr double array_area = 2.9069;
        constexpr double array_efficiency = 20.534;
        constexpr double energy_capacity = 8035.9;
        constexpr double min_voltage = 98.358;
        constexpr double max_voltage = 146.66;
        constexpr double resistance = 0.57065;
        constexpr double hysteresis_loss = 3.949;
        constexpr double eddy_current_loss_coefficient = 0.03925;
        constexpr double alpha = -7.2196;
        constexpr double beta = -4.9317;
        constexpr double a = -9.748;
        constexpr double b = 2.1486e-06;
        constexpr double c = 0.16383;
        constexpr double pressure_at_stc = 112.83;
        constexpr double mass = 112.17;
        constexpr double wheel_radius = 0.44008;
        const auto aerobody = Aerobody(drag_coefficient, frontal_area);
        const auto array = Array(array_area, array_efficiency);
        const auto battery = Battery(energy_capacity, resistance, min_voltage, max_voltage);
        const auto motor = Motor(hysteresis_loss, eddy_current_loss_coefficient);
        const auto tire = Tire(SaeJ2452Coefficients { alpha, beta, a, b, c }, pressure_at_stc);
        const SolarCar car(aerobody, array, battery, motor, tire, mass, wheel_radius);
        constexpr double start_time = 1187940600.00000;
        constexpr double end_time = 1187955000.00000;
        constexpr double expected = 162;
        const double result = RaceRunner::calculate_static_charging_gain(
          car, weather, route.get_segment(12).weather_station, start_time, end_time);
        REQUIRE_THAT(result, WithinRel(expected, EPSILON));
    }
    SECTION("Random Test 9") {
        constexpr double drag_coefficient = 0.0043508;
        constexpr double frontal_area = 8.9898;
        constexpr double array_area = 7.5221;
        constexpr double array_efficiency = 29.503;
        constexpr double energy_capacity = 5526;
        constexpr double min_voltage = 118.77;
        constexpr double max_voltage = 132.19;
        constexpr double resistance = 0.17195;
        constexpr double hysteresis_loss = 4.8792;
        constexpr double eddy_current_loss_coefficient = 0.018749;
        constexpr double alpha = -9.6256;
        constexpr double beta = 1.4568;
        constexpr double a = 3.1441;
        constexpr double b = 3.6593e-06;
        constexpr double c = -0.77374;
        constexpr double pressure_at_stc = 164.1;
        constexpr double mass = 259.46;
        constexpr double wheel_radius = 0.11067;
        const auto aerobody = Aerobody(drag_coefficient, frontal_area);
        const auto array = Array(array_area, array_efficiency);
        const auto battery = Battery(energy_capacity, resistance, min_voltage, max_voltage);
        const auto motor = Motor(hysteresis_loss, eddy_current_loss_coefficient);
        const auto tire = Tire(SaeJ2452Coefficients { alpha, beta, a, b, c }, pressure_at_stc);
        const SolarCar car(aerobody, array, battery, motor, tire, mass, wheel_radius);
        constexpr double start_time = 1187940600.00000;
        constexpr double end_time = 1187955000.00000;
        constexpr double expected = 602.28;
        const double result = RaceRunner::calculate_static_charging_gain(
          car, weather, route.get_segment(12).weather_station, start_time, end_time);
        REQUIRE_THAT(result, WithinRel(expected, EPSILON));
    }
}
TEST_CASE("RaceSegmentRunner: calculate_racetime", "[RaceSegmentRunner]") {
    const WeatherStations weather_stations(weather_stations_file);
    const RaceSchedule schedule((ConfigFile::from_path(schedule_file).value()));
    const Route route(route_file, weather_stations);
    const Weather weather(weather_file, weather_stations);
    SECTION("Random Test 0") {
        constexpr double drag_coefficient = 0.0082399;
        constexpr double frontal_area = 2.6346;
        constexpr double array_area = 7.6277;
        constexpr double array_efficiency = 19.321;
        constexpr double energy_capacity = 4879.1;
        constexpr double min_voltage = 79.431;
        constexpr double max_voltage = 107.98;
        constexpr double resistance = 0.73248;
        constexpr double hysteresis_loss = 3.2971;
        constexpr double eddy_current_loss_coefficient = 0.047264;
        constexpr double alpha = -5.6806;
        constexpr double beta = -6.3072;
        constexpr double a = -8.8681;
        constexpr double b = -5.6908e-06;
        constexpr double c = -0.36554;
        constexpr double pressure_at_stc = 195.33;
        constexpr double mass = 191.27;
        constexpr double wheel_radius = 0.27089;
        const auto aerobody = Aerobody(drag_coefficient, frontal_area);
        const auto array = Array(array_area, array_efficiency);
        const auto battery = Battery(energy_capacity, resistance, min_voltage, max_voltage);
        const auto motor = Motor(hysteresis_loss, eddy_current_loss_coefficient);
        const auto tire = Tire(SaeJ2452Coefficients { alpha, beta, a, b, c }, pressure_at_stc);
        const SolarCar car(aerobody, array, battery, motor, tire, mass, wheel_radius);
        constexpr double speed = 15.332;
        const double expected = 213601.99643;
        const auto result = RaceRunner::calculate_racetime(car, route, weather, schedule, speed);
        REQUIRE_THAT(result.value(), WithinAbs(expected, RT_DELTA));
    }
    SECTION("Random Test 1") {
        constexpr double drag_coefficient = 0.0086139;
        constexpr double frontal_area = 1.1623;
        constexpr double array_area = 4.08;
        constexpr double array_efficiency = 16.888;
        constexpr double energy_capacity = 4168.3;
        constexpr double min_voltage = 82.705;
        constexpr double max_voltage = 90.75;
        constexpr double resistance = 0.39619;
        constexpr double hysteresis_loss = 4.165;
        constexpr double eddy_current_loss_coefficient = 0.0023906;
        constexpr double alpha = 0.85076;
        constexpr double beta = -9.5032;
        constexpr double a = 3.6329;
        constexpr double b = -6.9325e-06;
        constexpr double c = -0.57894;
        constexpr double pressure_at_stc = 132.75;
        constexpr double mass = 108.57;
        constexpr double wheel_radius = 0.15087;
        const auto aerobody = Aerobody(drag_coefficient, frontal_area);
        const auto array = Array(array_area, array_efficiency);
        const auto battery = Battery(energy_capacity, resistance, min_voltage, max_voltage);
        const auto motor = Motor(hysteresis_loss, eddy_current_loss_coefficient);
        const auto tire = Tire(SaeJ2452Coefficients { alpha, beta, a, b, c }, pressure_at_stc);
        const SolarCar car(aerobody, array, battery, motor, tire, mass, wheel_radius);
        constexpr double speed = 12.015;
        const auto result = RaceRunner::calculate_racetime(car, route, weather, schedule, speed);
        REQUIRE_FALSE(result.has_value());
    }
    SECTION("Random Test 2") {
        constexpr double drag_coefficient = 0.0046146;
        constexpr double frontal_area = 5.3157;
        constexpr double array_area = 3.6075;
        constexpr double array_efficiency = 27.327;
        constexpr double energy_capacity = 2299.6;
        constexpr double min_voltage = 74.958;
        constexpr double max_voltage = 109.12;
        constexpr double resistance = 0.75513;
        constexpr double hysteresis_loss = 4.2147;
        constexpr double eddy_current_loss_coefficient = 0.039989;
        constexpr double alpha = 7.9584;
        constexpr double beta = -9.8376;
        constexpr double a = 2.5132;
        constexpr double b = 6.1115e-06;
        constexpr double c = 0.037833;
        constexpr double pressure_at_stc = 155.04;
        constexpr double mass = 165.38;
        constexpr double wheel_radius = 0.47218;
        const auto aerobody = Aerobody(drag_coefficient, frontal_area);
        const auto array = Array(array_area, array_efficiency);
        const auto battery = Battery(energy_capacity, resistance, min_voltage, max_voltage);
        const auto motor = Motor(hysteresis_loss, eddy_current_loss_coefficient);
        const auto tire = Tire(SaeJ2452Coefficients { alpha, beta, a, b, c }, pressure_at_stc);
        const SolarCar car(aerobody, array, battery, motor, tire, mass, wheel_radius);
        constexpr double speed = 14.902;
        const double expected = 219287.86088;
        const auto result = RaceRunner::calculate_racetime(car, route, weather, schedule, speed);
        REQUIRE_THAT(result.value(), WithinAbs(expected, RT_DELTA));
    }
    SECTION("Random Test 3") {
        constexpr double drag_coefficient = 0.0047328;
        constexpr double frontal_area = 5.6051;
        constexpr double array_area = 3.419;
        constexpr double array_efficiency = 24.562;
        constexpr double energy_capacity = 3785.2;
        constexpr double min_voltage = 89.937;
        constexpr double max_voltage = 128.46;
        constexpr double resistance = 0.39297;
        constexpr double hysteresis_loss = 3.6796;
        constexpr double eddy_current_loss_coefficient = 0.010364;
        constexpr double alpha = 7.862;
        constexpr double beta = 5.828;
        constexpr double a = 9.8999;
        constexpr double b = 1.665e-06;
        constexpr double c = 0.45367;
        constexpr double pressure_at_stc = 145.36;
        constexpr double mass = 261.3;
        constexpr double wheel_radius = 0.43099;
        const auto aerobody = Aerobody(drag_coefficient, frontal_area);
        const auto array = Array(array_area, array_efficiency);
        const auto battery = Battery(energy_capacity, resistance, min_voltage, max_voltage);
        const auto motor = Motor(hysteresis_loss, eddy_current_loss_coefficient);
        const auto tire = Tire(SaeJ2452Coefficients { alpha, beta, a, b, c }, pressure_at_stc);
        const SolarCar car(aerobody, array, battery, motor, tire, mass, wheel_radius);
        constexpr double speed = 16.219;
        const auto result = RaceRunner::calculate_racetime(car, route, weather, schedule, speed);
        REQUIRE_FALSE(result.has_value());
    }
    SECTION("Random Test 4") {
        constexpr double drag_coefficient = 0.0052306;
        constexpr double frontal_area = 7.6301;
        constexpr double array_area = 2.7395;
        constexpr double array_efficiency = 25.263;
        constexpr double energy_capacity = 3761.8;
        constexpr double min_voltage = 70.599;
        constexpr double max_voltage = 158.49;
        constexpr double resistance = 0.24342;
        constexpr double hysteresis_loss = 1.6418;
        constexpr double eddy_current_loss_coefficient = 0.04589;
        constexpr double alpha = -6.3607;
        constexpr double beta = -8.9363;
        constexpr double a = -2.2596;
        constexpr double b = -6.9209e-06;
        constexpr double c = -0.98622;
        constexpr double pressure_at_stc = 178.23;
        constexpr double mass = 147.73;
        constexpr double wheel_radius = 0.15266;
        const auto aerobody = Aerobody(drag_coefficient, frontal_area);
        const auto array = Array(array_area, array_efficiency);
        const auto battery = Battery(energy_capacity, resistance, min_voltage, max_voltage);
        const auto motor = Motor(hysteresis_loss, eddy_current_loss_coefficient);
        const auto tire = Tire(SaeJ2452Coefficients { alpha, beta, a, b, c }, pressure_at_stc);
        const SolarCar car(aerobody, array, battery, motor, tire, mass, wheel_radius);
        constexpr double speed = 14.971;
        const double expected = 218350.88680;
        const auto result = RaceRunner::calculate_racetime(car, route, weather, schedule, speed);
        REQUIRE_THAT(result.value(), WithinAbs(expected, RT_DELTA));
    }
    SECTION("Random Test 5") {
        constexpr double drag_coefficient = 0.0026354;
        constexpr double frontal_area = 8.5655;
        constexpr double array_area = 7.147;
        constexpr double array_efficiency = 23.843;
        constexpr double energy_capacity = 5784.2;
        constexpr double min_voltage = 98.646;
        constexpr double max_voltage = 166.01;
        constexpr double resistance = 0.85924;
        constexpr double hysteresis_loss = 3.7834;
        constexpr double eddy_current_loss_coefficient = 0.040538;
        constexpr double alpha = 0.53107;
        constexpr double beta = 5.0968;
        constexpr double a = 4.3057;
        constexpr double b = 7.4981e-06;
        constexpr double c = 0.24024;
        constexpr double pressure_at_stc = 102.82;
        constexpr double mass = 264.61;
        constexpr double wheel_radius = 0.22605;
        const auto aerobody = Aerobody(drag_coefficient, frontal_area);
        const auto array = Array(array_area, array_efficiency);
        const auto battery = Battery(energy_capacity, resistance, min_voltage, max_voltage);
        const auto motor = Motor(hysteresis_loss, eddy_current_loss_coefficient);
        const auto tire = Tire(SaeJ2452Coefficients { alpha, beta, a, b, c }, pressure_at_stc);
        const SolarCar car(aerobody, array, battery, motor, tire, mass, wheel_radius);
        constexpr double speed = 10.813;
        const auto result = RaceRunner::calculate_racetime(car, route, weather, schedule, speed);
        REQUIRE_FALSE(result.has_value());
    }
    SECTION("Random Test 6") {
        constexpr double drag_coefficient = 0.0097938;
        constexpr double frontal_area = 6.5663;
        constexpr double array_area = 3.6906;
        constexpr double array_efficiency = 18.027;
        constexpr double energy_capacity = 7613.8;
        constexpr double min_voltage = 127.74;
        constexpr double max_voltage = 133.67;
        constexpr double resistance = 0.0022042;
        constexpr double hysteresis_loss = 1.193;
        constexpr double eddy_current_loss_coefficient = 0.024982;
        constexpr double alpha = -8.5403;
        constexpr double beta = 3.4293;
        constexpr double a = -3.0066;
        constexpr double b = 3.2337e-06;
        constexpr double c = -0.17913;
        constexpr double pressure_at_stc = 177.01;
        constexpr double mass = 200.14;
        constexpr double wheel_radius = 0.12754;
        const auto aerobody = Aerobody(drag_coefficient, frontal_area);
        const auto array = Array(array_area, array_efficiency);
        const auto battery = Battery(energy_capacity, resistance, min_voltage, max_voltage);
        const auto motor = Motor(hysteresis_loss, eddy_current_loss_coefficient);
        const auto tire = Tire(SaeJ2452Coefficients { alpha, beta, a, b, c }, pressure_at_stc);
        const SolarCar car(aerobody, array, battery, motor, tire, mass, wheel_radius);
        constexpr double speed = 14.075;
        const double expected = 231219.42339;
        const auto result = RaceRunner::calculate_racetime(car, route, weather, schedule, speed);
        REQUIRE_THAT(result.value(), WithinAbs(expected, RT_DELTA));
    }
    SECTION("Random Test 7") {
        constexpr double drag_coefficient = 0.0066439;
        constexpr double frontal_area = 1.4368;
        constexpr double array_area = 2.3688;
        constexpr double array_efficiency = 24.111;
        constexpr double energy_capacity = 4355.9;
        constexpr double min_voltage = 94.12;
        constexpr double max_voltage = 101.05;
        constexpr double resistance = 0.21671;
        constexpr double hysteresis_loss = 3.9719;
        constexpr double eddy_current_loss_coefficient = 0.0031852;
        constexpr double alpha = -1.9741;
        constexpr double beta = 9.2155;
        constexpr double a = -2.0787;
        constexpr double b = -1.4216e-06;
        constexpr double c = 0.049124;
        constexpr double pressure_at_stc = 178.62;
        constexpr double mass = 227.53;
        constexpr double wheel_radius = 0.48446;
        const auto aerobody = Aerobody(drag_coefficient, frontal_area);
        const auto array = Array(array_area, array_efficiency);
        const auto battery = Battery(energy_capacity, resistance, min_voltage, max_voltage);
        const auto motor = Motor(hysteresis_loss, eddy_current_loss_coefficient);
        const auto tire = Tire(SaeJ2452Coefficients { alpha, beta, a, b, c }, pressure_at_stc);
        const SolarCar car(aerobody, array, battery, motor, tire, mass, wheel_radius);
        constexpr double speed = 18.326;
        const auto result = RaceRunner::calculate_racetime(car, route, weather, schedule, speed);
        REQUIRE_FALSE(result.has_value());
    }
    SECTION("Random Test 8") {
        constexpr double drag_coefficient = 0.0041165;
        constexpr double frontal_area = 6.3056;
        constexpr double array_area = 2.9207;
        constexpr double array_efficiency = 26.46;
        constexpr double energy_capacity = 6732;
        constexpr double min_voltage = 130.85;
        constexpr double max_voltage = 168.41;
        constexpr double resistance = 0.053352;
        constexpr double hysteresis_loss = 2.9317;
        constexpr double eddy_current_loss_coefficient = 0.018643;
        constexpr double alpha = -5.7768;
        constexpr double beta = 2.3852;
        constexpr double a = 4.121;
        constexpr double b = -2.8707e-06;
        constexpr double c = -0.63385;
        constexpr double pressure_at_stc = 108.09;
        constexpr double mass = 172.52;
        constexpr double wheel_radius = 0.49564;
        const auto aerobody = Aerobody(drag_coefficient, frontal_area);
        const auto array = Array(array_area, array_efficiency);
        const auto battery = Battery(energy_capacity, resistance, min_voltage, max_voltage);
        const auto motor = Motor(hysteresis_loss, eddy_current_loss_coefficient);
        const auto tire = Tire(SaeJ2452Coefficients { alpha, beta, a, b, c }, pressure_at_stc);
        const SolarCar car(aerobody, array, battery, motor, tire, mass, wheel_radius);
        constexpr double speed = 18.486;
        const double expected = 179915.01068;
        const auto result = RaceRunner::calculate_racetime(car, route, weather, schedule, speed);
        REQUIRE_THAT(result.value(), WithinAbs(expected, RT_DELTA));
    }
    SECTION("Random Test 9") {
        constexpr double drag_coefficient = 0.001211;
        constexpr double frontal_area = 3.3298;
        constexpr double array_area = 8.8211;
        constexpr double array_efficiency = 27.252;
        constexpr double energy_capacity = 6633.9;
        constexpr double min_voltage = 77.671;
        constexpr double max_voltage = 148.4;
        constexpr double resistance = 0.34752;
        constexpr double hysteresis_loss = 3.3601;
        constexpr double eddy_current_loss_coefficient = 0.015343;
        constexpr double alpha = -1.981;
        constexpr double beta = 4.7986;
        constexpr double a = 4.9473;
        constexpr double b = -9.7289e-06;
        constexpr double c = 0.72583;
        constexpr double pressure_at_stc = 120.82;
        constexpr double mass = 273.61;
        constexpr double wheel_radius = 0.13321;
        const auto aerobody = Aerobody(drag_coefficient, frontal_area);
        const auto array = Array(array_area, array_efficiency);
        const auto battery = Battery(energy_capacity, resistance, min_voltage, max_voltage);
        const auto motor = Motor(hysteresis_loss, eddy_current_loss_coefficient);
        const auto tire = Tire(SaeJ2452Coefficients { alpha, beta, a, b, c }, pressure_at_stc);
        const SolarCar car(aerobody, array, battery, motor, tire, mass, wheel_radius);
        constexpr double speed = 18.281;
        const auto result = RaceRunner::calculate_racetime(car, route, weather, schedule, speed);
        REQUIRE_FALSE(result.has_value());
    }
}