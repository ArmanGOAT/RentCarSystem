cmake_minimum_required(VERSION 3.27)
project(RentCarSystem)

set(CMAKE_CXX_STANDARD 23)

add_executable(RentCarSystem main.cpp
        Car.h
        Car.cpp
        Reservation.h
        Reservation.cpp
        RentalSystem.h
        RentalSystem.cpp)
