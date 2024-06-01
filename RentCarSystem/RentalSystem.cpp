#include "RentalSystem.h"
#include <iostream>

RentalSystem::RentalSystem() : nextCarId(1), nextReservationId(1) {}

void RentalSystem::addCar(const std::string& make, const std::string& model) {
    cars.emplace_back(nextCarId++, make, model);
    std::cout << "Car added: " << make << " " << model << std::endl;
}

void RentalSystem::removeCar(int carId) {
    for (auto it = cars.begin(); it != cars.end(); ++it) {
        if (it->getId() == carId) {
            cars.erase(it);
            std::cout << "Car removed: ID " << carId << std::endl;
            return;
        }
    }
    std::cout << "Car not found: ID " << carId << std::endl;
}

void RentalSystem::reserveCar(int carId, const std::string& customerName, const std::string& startDate, const std::string& endDate) {
    for (auto& car : cars) {
        if (car.getId() == carId && car.isAvailable()) {
            reservations.emplace_back(nextReservationId++, carId, customerName, startDate, endDate);
            car.setAvailability(false);
            std::cout << "Car reserved: ID " << carId << " for " << customerName << std::endl;
            return;
        }
    }
    std::cout << "Car not available or not found: ID " << carId << std::endl;
}

void RentalSystem::cancelReservation(int reservationId) {
    for (auto it = reservations.begin(); it != reservations.end(); ++it) {
        if (it->getId() == reservationId) {
            int carId = it->getCarId();

            for (auto& car : cars) {
                if (car.getId() == carId) {
                    car.setAvailability(true);
                    break;
                }
            }

            reservations.erase(it);
            std::cout << "Reservation cancelled: ID " << reservationId << std::endl;
            return;
        }
    }
    std::cout << "Reservation not found: ID " << reservationId << std::endl;
}

void RentalSystem::saveDataToFile(const std::string& filename) {
    std::ofstream outFile(filename, std::ios::binary);
    if (!outFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    // Сохраняем количество автомобилей и бронирований в файле
    std::size_t carCount = cars.size();
    std::size_t reservationCount = reservations.size();

    outFile.write(reinterpret_cast<const char*>(&carCount), sizeof(carCount));
    outFile.write(reinterpret_cast<const char*>(&reservationCount), sizeof(reservationCount));

    // Сохраняем каждый автомобиль в файле
    for (const auto& car : cars) {
        car.save(outFile);
    }

    // Сохраняем каждое бронирование в файле
    for (const auto& reservation : reservations) {
        reservation.save(outFile);
    }

    outFile.close();
    std::cout << "Data saved to file: " << filename << std::endl;
}

void RentalSystem::loadDataFromFile(const std::string& filename) {
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    // Загружаем количество автомобилей и бронирований из файла
    std::size_t carCount;
    std::size_t reservationCount;

    inFile.read(reinterpret_cast<char*>(&carCount), sizeof(carCount));
    inFile.read(reinterpret_cast<char*>(&reservationCount), sizeof(reservationCount));

    cars.clear();
    reservations.clear();

    // Загружаем каждый автомобиль из файла
    for (std::size_t i = 0; i < carCount; i++) {
        Car car;
        car.load(inFile);
        cars.push_back(car);
    }

    // Загружаем каждое бронирование из файла
    for (std::size_t i = 0; i < reservationCount; i++) {
        Reservation reservation;
        reservation.load(inFile);
        reservations.push_back(reservation);
    }

    inFile.close();
    std::cout << "Data loaded from file: " << filename << std::endl;
}

void RentalSystem::displayCars() const {
    std::cout << "Cars:" << std::endl;
    for (const auto& car : cars) {
        std::cout << "ID: " << car.getId() << ", Make: " << car.getMake() << ", Model: " << car.getModel() << ", Available: " << (car.isAvailable() ? "Yes" : "No") << std::endl;
    }
}

void RentalSystem::displayReservations() const {
    std::cout << "Reservations:" << std::endl;
    for (const auto& reservation : reservations) {
        std::cout << "ID: " << reservation.getId() << ", Car ID: " << reservation.getCarId() << ", Customer: " << reservation.getCustomerName() << ", Start Date: " << reservation.getStartDate() << ", End Date: " << reservation.getEndDate() << std::endl;
    }
}
