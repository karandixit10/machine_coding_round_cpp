#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <string>

class Vehicle {
private:
    std::string type;                       // Type of vehicle (e.g., Activa, Polo)
    std::string registration_number;        // Registration number of the vehicle
    int         capacity;                   // Capacity of the vehicle (number of seats)

public:
                    Vehicle                 (std::string type, std::string reg_num, int capacity);  // Constructor
    std::string     get_type                () const;                                               // Getter for vehicle type
    std::string     get_registration_number () const;                                               // Getter for vehicle registration number
    int             get_capacity            () const;                                               // Getter for vehicle capacity

    bool            operator==              (const Vehicle& other) const;                                                // Equivalent
};

#endif /* VEHICLE_HPP */
