cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
project(RobustFractionTest)

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_EXTENSIONS OFF )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

set( APP_EXECUTABLE RobustFractionTest )

include_directories( inc )

ADD_EXECUTABLE(RobustFraction "src/RobustFraction.cpp")

ADD_EXECUTABLE( ${APP_EXECUTABLE} "src/RobustFractionTest.cpp"  "src/RobustFraction.cpp")

target_compile_definitions(RobustFractionTest PRIVATE TESTING)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

set_property( DIRECTORY PROPERTY VS_STARTUP_PROJECT ${APP_EXECUTABLE} )

include (CTest)
add_test(${APP_EXECUTABLE}_testAddition ${APP_EXECUTABLE} 1)
add_test(${APP_EXECUTABLE}_testSubtraction ${APP_EXECUTABLE} 2)
add_test(${APP_EXECUTABLE}_testMultiplication ${APP_EXECUTABLE} 3)
add_test(${APP_EXECUTABLE}_testDivision ${APP_EXECUTABLE} 4)
add_test(${APP_EXECUTABLE}_testPreIncrement ${APP_EXECUTABLE} 5)
add_test(${APP_EXECUTABLE}_testPostIncrement ${APP_EXECUTABLE} 6)
add_test(${APP_EXECUTABLE}_testPostIncrementFinal ${APP_EXECUTABLE} 7)
add_test(${APP_EXECUTABLE}_testPreDecrement ${APP_EXECUTABLE} 8)
add_test(${APP_EXECUTABLE}_testPostDecrement ${APP_EXECUTABLE} 9)
add_test(${APP_EXECUTABLE}_testPostDecrementFinal ${APP_EXECUTABLE} 10)
add_test(${APP_EXECUTABLE}_testValidInput ${APP_EXECUTABLE} 11)
add_test(${APP_EXECUTABLE}_testInvalidInput ${APP_EXECUTABLE} 12)

find_program(VALGRIND "valgrind")
if(VALGRIND)
	add_custom_target(valgrind
    COMMAND "${VALGRIND}" --tool=memcheck --leak-check=yes --show-reachable=yes --error-exitcode=1 $<TARGET_FILE:${APP_EXECUTABLE}>)
endif()