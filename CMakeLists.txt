cmake_minimum_required(VERSION 3.10)

project(tuntaptcpip)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(SANITIZERS_FLAGS
    -fsanitize=address
    -fsanitize=leak
    -fsanitize=undefined
    -fsanitize=shift
    -fsanitize=null
    )

include_directories(src test)

set(SRC 
    src/Math.cc
    )

add_executable(main src/main.cc ${SRC})
#Test
add_executable(test test/tests.cc ${SRC})
target_link_libraries(test -lgtest)

#Sanitizers
add_executable(main.san src/main.cc ${SRC})
add_executable(test.san test/tests.cc ${SRC})
target_link_libraries(main.san 
    ${SANITIZERS_FLAGS}
    )
target_link_libraries(test.san
    ${SANITIZERS_FLAGS}
    -lgtest)
