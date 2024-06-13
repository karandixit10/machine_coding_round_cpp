#include "User.hpp"

// Constructor: Initialize user with name and user ID
User::User(std::string name, int user_id) : name(name), user_id(user_id) {}

// Add a vehicle to the user's collection
void User::add_vehicle(Vehicle vehicle) {
    vehicles.push_back(vehicle);
}

// Getter for user's name
std::string User::get_name() const {
    return name;
}

// Getter for user's ID
int User::get_user_id() const {
    return user_id;
}

// Getter for user's vehicles
const std::vector<Vehicle>& User::get_vehicles() const {
    return vehicles;
}
