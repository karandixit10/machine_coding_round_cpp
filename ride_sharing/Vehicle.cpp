#include "Vehicle.hpp"

// Constructor: Initialize vehicle with type, registration number, and capacity
Vehicle::Vehicle(std::string type, std::string reg_num, int capacity)
    : type(type), registration_number(reg_num), capacity(capacity) {}

// Getter for vehicle type
std::string Vehicle::get_type() const {
    return type;
}

// Getter for vehicle registration number
std::string Vehicle::get_registration_number() const {
    return registration_number;
}

// Getter for vehicle capacity
int Vehicle::get_capacity() const {
    return capacity;
}

// Overloaded equality operator
bool Vehicle::operator==(const Vehicle& other) const {
    return (type == other.type &&
            registration_number == other.registration_number &&
            capacity == other.capacity);
}