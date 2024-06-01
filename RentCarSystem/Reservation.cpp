#include "Reservation.h"
#include <fstream>

Reservation::Reservation(int resId, int carId, const std::string& name, const std::string& start, const std::string& end)
        : id(resId), carId(carId), customerName(name), startDate(start), endDate(end) {}

int Reservation::getId() const {
    return id;
}

int Reservation::getCarId() const {
    return carId;
}

std::string Reservation::getCustomerName() const {
    return customerName;
}

std::string Reservation::getStartDate() const {
    return startDate;
}

std::string Reservation::getEndDate() const {
    return endDate;
}

void Reservation::save(std::ofstream& outFile) const {
    outFile.write(reinterpret_cast<const char*>(&id), sizeof(id));
    outFile.write(reinterpret_cast<const char*>(&carId), sizeof(carId));

    std::size_t nameSize = customerName.size();
    outFile.write(reinterpret_cast<const char*>(&nameSize), sizeof(nameSize));
    outFile.write(customerName.c_str(), nameSize);

    std::size_t startDateSize = startDate.size();
    outFile.write(reinterpret_cast<const char*>(&startDateSize), sizeof(startDateSize));
    outFile.write(startDate.c_str(), startDateSize);

    std::size_t endDateSize = endDate.size();
    outFile.write(reinterpret_cast<const char*>(&endDateSize), sizeof(endDateSize));
    outFile.write(endDate.c_str(), endDateSize);
}

void Reservation::load(std::ifstream& inFile) {
    inFile.read(reinterpret_cast<char*>(&id), sizeof(id));
    inFile.read(reinterpret_cast<char*>(&carId), sizeof(carId));

    std::size_t nameSize;
    inFile.read(reinterpret_cast<char*>(&nameSize), sizeof(nameSize));
    customerName.resize(nameSize);
    inFile.read(&customerName[0], nameSize);

    std::size_t startDateSize;
    inFile.read(reinterpret_cast<char*>(&startDateSize), sizeof(startDateSize));
    startDate.resize(startDateSize);
    inFile.read(&startDate[0], startDateSize);

    std::size_t endDateSize;
    inFile.read(reinterpret_cast<char*>(&endDateSize), sizeof(endDateSize));
    endDate.resize(endDateSize);
    inFile.read(&endDate[0], endDateSize);
}
