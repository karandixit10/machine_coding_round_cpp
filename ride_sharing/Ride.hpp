#ifndef RIDE_HPP
#define RIDE_HPP

#include "Vehicle.hpp"
#include <string>

class Ride {
private:
    Vehicle         vehicle;                    // Vehicle used for the ride
    std::string     origin;                     // Starting point of the ride
    std::string     destination;                // Destination of the ride
    int             available_seats;            // Number of available seats in the vehicle

public:
                    Ride                (Vehicle vehicle, std::string origin, std::string destination, int seats);  // Constructor
    Vehicle         get_vehicle         () const;                                                                   // Getter for ride's vehicle
    std::string     get_origin          () const;                                                                   // Getter for ride's origin
    std::string     get_destination     () const;                                                                   // Getter for ride's destination
    int             get_available_seats () const;                                                                   // Getter for available seats in the ride
    void            reduce_seats        (int num);                                                                  // Reduce available seats when passengers are added
    bool            operator==          (const Ride& other) const;                                                  // Equality operator

};

#endif /* RIDE_HPP */
