cmake_minimum_required(VERSION 2.6)
project(cpp_execise)


add_definitions(-std=c++11)

add_executable(cpp_execise main.cpp strngbad.h strngbad.cpp mytime0.h mytime0.cpp string1.h string1.cpp brass.h brass.cpp acctabc.h acctABC.cpp)

install(TARGETS cpp_execise RUNTIME DESTINATION bin)
