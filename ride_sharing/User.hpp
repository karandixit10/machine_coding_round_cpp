#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <vector>
#include "Vehicle.hpp"

class User {
private:
    std::string             name;               // User's name
    int                     user_id;            // Unique user ID
    std::vector<Vehicle>    vehicles;           // Vehicles owned by the user

public:
                                User        (std::string name, int user_id);        // Constructor
    void                        add_vehicle (Vehicle vehicle);                      // Add a vehicle to user's collection
    std::string                 get_name    () const;                               // Getter for user's name
    int                         get_user_id () const;                               // Getter for user's ID
    const std::vector<Vehicle>& get_vehicles() const;                               // Getter for user's vehicles
};

#endif /* USER_HPP */