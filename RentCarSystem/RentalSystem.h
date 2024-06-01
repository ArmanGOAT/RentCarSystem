#ifndef RENTALSYSTEM_H
#define RENTALSYSTEM_H

#include <vector>
#include "Car.h"
#include "Reservation.h"
#include <fstream>

class RentalSystem {
private:
    std::vector<Car> cars;
    std::vector<Reservation> reservations;
    int nextCarId;
    int nextReservationId;

public:
    RentalSystem();

    void addCar(const std::string& make, const std::string& model);
    void removeCar(int carId);

    void reserveCar(int carId, const std::string& customerName, const std::string& startDate, const std::string& endDate);
    void cancelReservation(int reservationId);

    void saveDataToFile(const std::string& filename);
    void loadDataFromFile(const std::string& filename);

    void displayCars() const;
    void displayReservations() const;
};

#endif // RENTALSYSTEM_H
