cmake_minimum_required(VERSION 2.6)
project(cpp_execise)


#CHECK_CXX_COMPILER_FLAG("-std=c++17" COMPILER_SUPPORT_CXX17)
add_definitions(-std=c++17)

add_executable(cpp_execise main.cpp)

install(TARGETS cpp_execise RUNTIME DESTINATION bin)
