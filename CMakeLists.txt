cmake_minimum_required(VERSION 3.10)

project(tuntaptcpip)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(src test)

set(SRC 
    src/Math.cc
    )

add_executable(main src/main.cc ${SRC})
#Test
add_executable(test test/tests.cc ${SRC})
target_link_libraries(test -lgtest)
