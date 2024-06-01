#ifndef CAR_H
#define CAR_H

#include <string>
#include <fstream>

class Car {
private:
    int id;
    std::string make;
    std::string model;
    bool available;

public:
    Car() = default;
    Car(int carId, const std::string& carMake, const std::string& carModel);

    int getId() const;
    std::string getMake() const;
    std::string getModel() const;
    bool isAvailable() const;
    void setAvailability(bool status);

    void save(std::ofstream& outFile) const;
    void load(std::ifstream& inFile);
};

#endif // CAR_H
