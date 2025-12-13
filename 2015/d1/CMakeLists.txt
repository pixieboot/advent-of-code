cmake_minimum_required(VERSION 3.10)

project(d1)

add_executable(d1 main.cpp)

install(TARGETS d1 RUNTIME DESTINATION bin)
