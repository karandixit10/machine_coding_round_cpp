#include "Ride.hpp"

// Constructor: Initialize ride with vehicle, origin, destination, and available seats
Ride::Ride(Vehicle vehicle, std::string origin, std::string destination, int seats)
    : vehicle(vehicle), origin(origin), destination(destination), available_seats(seats) {}

// Getter for ride's vehicle
Vehicle Ride::get_vehicle() const {
    return vehicle;
}

// Getter for ride's origin
std::string Ride::get_origin() const {
    return origin;
}

// Getter for ride's destination
std::string Ride::get_destination() const {
    return destination;
}

// Getter for available seats in the ride
int Ride::get_available_seats() const {
    return available_seats;
}

// Reduce available seats when passengers are added
void Ride::reduce_seats(int num) {
    available_seats -= num;
}

// Implementation of equality operator for Ride class
bool Ride::operator==(const Ride& other) const {
    return vehicle == other.vehicle &&
           origin == other.origin &&
           destination == other.destination &&
           available_seats == other.available_seats;
}