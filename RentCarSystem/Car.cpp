#include "Car.h"
#include <fstream>

Car::Car(int carId, const std::string& carMake, const std::string& carModel)
        : id(carId), make(carMake), model(carModel), available(true) {}

int Car::getId() const {
    return id;
}

std::string Car::getMake() const {
    return make;
}

std::string Car::getModel() const {
    return model;
}

bool Car::isAvailable() const {
    return available;
}

void Car::setAvailability(bool status) {
    available = status;
}

void Car::save(std::ofstream& outFile) const {
    outFile.write(reinterpret_cast<const char*>(&id), sizeof(id));

    std::size_t makeSize = make.size();
    std::size_t modelSize = model.size();

    outFile.write(reinterpret_cast<const char*>(&makeSize), sizeof(makeSize));
    outFile.write(make.c_str(), makeSize);

    outFile.write(reinterpret_cast<const char*>(&modelSize), sizeof(modelSize));
    outFile.write(model.c_str(), modelSize);

    outFile.write(reinterpret_cast<const char*>(&available), sizeof(available));
}

void Car::load(std::ifstream& inFile) {
    inFile.read(reinterpret_cast<char*>(&id), sizeof(id));

    std::size_t makeSize;
    inFile.read(reinterpret_cast<char*>(&makeSize), sizeof(makeSize));
    make.resize(makeSize);
    inFile.read(&make[0], makeSize);

    std::size_t modelSize;
    inFile.read(reinterpret_cast<char*>(&modelSize), sizeof(modelSize));
    model.resize(modelSize);
    inFile.read(&model[0], modelSize);

    inFile.read(reinterpret_cast<char*>(&available), sizeof(available));
}
