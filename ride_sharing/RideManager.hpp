#ifndef RIDE_MANAGER_HPP
#define RIDE_MANAGER_HPP

#include "Ride.hpp"
#include "User.hpp"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

class RideManager {
private:
    std::vector<Ride>   rides;    // Collection of all rides offered
    std::vector<User>   users;    // Collection of all users
public:

    void                add_user             (User user);                    // Method to add a new user
    void                add_vehicle_to_user (int user_id, Vehicle vehicle); // Method to add a vehicle to a user's collection
    void                offer_ride          (Ride ride);                    // Method to offer a new ride
    std::vector<Ride>   select_ride         (std::string source, std::string destination, int seats, std::string selection_strategy); // Method to select a ride based on source, destination, seats, and selection strategy
    void                end_ride            (Ride ride);                    // Method to end a ride
    void                print_ride_stats    () const;                       // Method to print statistics of rides offered
};

#endif /* RIDE_MANAGER_HPP */
