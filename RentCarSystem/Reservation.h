#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
#include <fstream>

class Reservation {
private:
    int id;
    int carId;
    std::string customerName;
    std::string startDate;
    std::string endDate;

public:
    Reservation() = default;
    Reservation(int resId, int carId, const std::string& name, const std::string& start, const std::string& end);

    int getId() const;
    int getCarId() const;
    std::string getCustomerName() const;
    std::string getStartDate() const;
    std::string getEndDate() const;

    void save(std::ofstream& outFile) const;
    void load(std::ifstream& inFile);
};

#endif // RESERVATION_H
