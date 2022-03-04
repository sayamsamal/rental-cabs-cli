cmake_minimum_required(VERSION 3.16.3)
project(main)

find_package(cpprestsdk REQUIRED)

add_executable(main src/main.cpp src/Account.cpp src/Vehicle.cpp src/Travel.cpp)

target_link_libraries(main PRIVATE cpprestsdk::cpprest)