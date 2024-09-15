add_test( [==[VelocityVector Constructors: from_cartesian_components]==] /Users/swesikramineni/github/solarcar/solarcar-training-p2/build/src/SolarCar/Aerobody/aerobody_tests [==[VelocityVector Constructors: from_cartesian_components]==]  )
set_tests_properties( [==[VelocityVector Constructors: from_cartesian_components]==] PROPERTIES WORKING_DIRECTORY /Users/swesikramineni/github/solarcar/solarcar-training-p2/build/src/SolarCar/Aerobody)
add_test( [==[VelocityVector Constructors: from_polar_components]==] /Users/swesikramineni/github/solarcar/solarcar-training-p2/build/src/SolarCar/Aerobody/aerobody_tests [==[VelocityVector Constructors: from_polar_components]==]  )
set_tests_properties( [==[VelocityVector Constructors: from_polar_components]==] PROPERTIES WORKING_DIRECTORY /Users/swesikramineni/github/solarcar/solarcar-training-p2/build/src/SolarCar/Aerobody)
add_test( [==[VelocityVector Utilities: get_magnitude]==] /Users/swesikramineni/github/solarcar/solarcar-training-p2/build/src/SolarCar/Aerobody/aerobody_tests [==[VelocityVector Utilities: get_magnitude]==]  )
set_tests_properties( [==[VelocityVector Utilities: get_magnitude]==] PROPERTIES WORKING_DIRECTORY /Users/swesikramineni/github/solarcar/solarcar-training-p2/build/src/SolarCar/Aerobody)
add_test( [==[VelocityVector Utilities: get_heading]==] /Users/swesikramineni/github/solarcar/solarcar-training-p2/build/src/SolarCar/Aerobody/aerobody_tests [==[VelocityVector Utilities: get_heading]==]  )
set_tests_properties( [==[VelocityVector Utilities: get_heading]==] PROPERTIES WORKING_DIRECTORY /Users/swesikramineni/github/solarcar/solarcar-training-p2/build/src/SolarCar/Aerobody)
add_test( [==[VelocityVector Utilities: angle_between]==] /Users/swesikramineni/github/solarcar/solarcar-training-p2/build/src/SolarCar/Aerobody/aerobody_tests [==[VelocityVector Utilities: angle_between]==]  )
set_tests_properties( [==[VelocityVector Utilities: angle_between]==] PROPERTIES WORKING_DIRECTORY /Users/swesikramineni/github/solarcar/solarcar-training-p2/build/src/SolarCar/Aerobody)
add_test( [==[Aerobody: get_wind]==] /Users/swesikramineni/github/solarcar/solarcar-training-p2/build/src/SolarCar/Aerobody/aerobody_tests [==[Aerobody: get_wind]==]  )
set_tests_properties( [==[Aerobody: get_wind]==] PROPERTIES WORKING_DIRECTORY /Users/swesikramineni/github/solarcar/solarcar-training-p2/build/src/SolarCar/Aerobody)
add_test( [==[Aerobody: aerodynamic_drag]==] /Users/swesikramineni/github/solarcar/solarcar-training-p2/build/src/SolarCar/Aerobody/aerobody_tests [==[Aerobody: aerodynamic_drag]==]  )
set_tests_properties( [==[Aerobody: aerodynamic_drag]==] PROPERTIES WORKING_DIRECTORY /Users/swesikramineni/github/solarcar/solarcar-training-p2/build/src/SolarCar/Aerobody)
set( aerobody_tests_TESTS [==[VelocityVector Constructors: from_cartesian_components]==] [==[VelocityVector Constructors: from_polar_components]==] [==[VelocityVector Utilities: get_magnitude]==] [==[VelocityVector Utilities: get_heading]==] [==[VelocityVector Utilities: angle_between]==] [==[Aerobody: get_wind]==] [==[Aerobody: aerodynamic_drag]==])
