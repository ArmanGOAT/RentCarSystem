#include <iostream>
#include "RentalSystem.h"

void displayMenu() {
    std::cout << "\nCar Rental System Menu\n";
    std::cout << "1. Add a car\n";
    std::cout << "2. Remove a car\n";
    std::cout << "3. Reserve a car\n";
    std::cout << "4. Cancel a reservation\n";
    std::cout << "5. Display cars\n";
    std::cout << "6. Display reservations\n";
    std::cout << "7. Save data to file\n";
    std::cout << "8. Load data from file\n";
    std::cout << "9. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    RentalSystem rentalSystem;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string make, model;
                std::cout << "Enter car make: ";
                std::cin >> make;
                std::cout << "Enter car model: ";
                std::cin >> model;
                rentalSystem.addCar(make, model);
                break;
            }
            case 2: {
                int carId;
                std::cout << "Enter car ID to remove: ";
                std::cin >> carId;
                rentalSystem.removeCar(carId);
                break;
            }
            case 3: {
                int carId;
                std::string customerName, startDate, endDate;
                std::cout << "Enter car ID to reserve: ";
                std::cin >> carId;
                std::cout << "Enter customer name: ";
                std::cin >> customerName;
                std::cout << "Enter start date (YYYY-MM-DD): ";
                std::cin >> startDate;
                std::cout << "Enter end date (YYYY-MM-DD): ";
                std::cin >> endDate;
                rentalSystem.reserveCar(carId, customerName, startDate, endDate);
                break;
            }
            case 4: {
                int reservationId;
                std::cout << "Enter reservation ID to cancel: ";
                std::cin >> reservationId;
                rentalSystem.cancelReservation(reservationId);
                break;
            }
            case 5:
                rentalSystem.displayCars();
                break;
            case 6:
                rentalSystem.displayReservations();
                break;
            case 7: {
                std::string filename;
                std::cout << "Enter filename to save data: ";
                std::cin >> filename;
                rentalSystem.saveDataToFile(filename);
                break;
            }
            case 8: {
                std::string filename;
                std::cout << "Enter filename to load data: ";
                std::cin >> filename;
                rentalSystem.loadDataFromFile(filename);
                break;
            }
            case 9:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice, please try again.\n";
                break;
        }
    } while (choice != 9);

    return 0;
}
