#include "RideManager.hpp"

// Method to add a new user
void RideManager::add_user(User user) {
    users.push_back(user);
}


// Method to add a vehicle to a user's collection
void RideManager::add_vehicle_to_user(int user_id, Vehicle vehicle) {
    auto it = std::find_if(users.begin(), users.end(), [user_id](const User& user) {
        return user.get_user_id() == user_id;
    });

    if (it != users.end()) {
        it->add_vehicle(vehicle);
    } else {
        std::cerr << "Error: User with ID " << user_id << " not found." << std::endl;
        // Handle error condition appropriately, e.g., throw an exception
        // throw std::runtime_error("User not found");
    }
}

// Method to offer a new ride
void RideManager::offer_ride(Ride ride) {
    rides.push_back(ride);
}


// Method to select a ride based on source, destination, seats, and selection strategy
std::vector<Ride> RideManager::select_ride(std::string source, std::string destination, int seats, std::string selection_strategy) {
    std::vector<Ride> selected_rides;

    // Check for PreferredVehicle selection strategy
    if (selection_strategy.find("PreferredVehicle=") == 0) {
        std::string preferred_vehicle = selection_strategy.substr(17); // Extract vehicle name after "PreferredVehicle="

        // Ensure rides vector is not empty before accessing
        if (!rides.empty()) {
            // Find rides matching preferred vehicle, source, destination, and seats requirement
            for (const auto& ride : rides) {
                if (ride.get_vehicle().get_type() == preferred_vehicle &&
                    ride.get_origin() == source &&
                    ride.get_destination() == destination &&
                    ride.get_available_seats() >= seats) {
                    selected_rides.push_back(ride);
                }
            }
        } else {
            std::cerr << "Error: Rides vector is empty." << std::endl;
        }
    } else if (selection_strategy == "MostVacant") {
        // Implement selection strategy (e.g., MostVacant)
        if (!rides.empty()) {
            std::sort(rides.begin(), rides.end(), [](const Ride& a, const Ride& b) {
                return a.get_available_seats() > b.get_available_seats();
            });

            // Find rides matching source, destination, and seats requirement after sorting
            for (const auto& ride : rides) {
                if (ride.get_origin() == source &&
                    ride.get_destination() == destination &&
                    ride.get_available_seats() >= seats) {
                    selected_rides.push_back(ride);
                }
            }
        } else {
            std::cerr << "Error: Rides vector is empty." << std::endl;
        }
    } else {
        // Unsupported selection strategy
        std::cerr << "Error: Unsupported selection strategy." << std::endl;
    }

    return selected_rides;
}

// Method to end a ride
void RideManager::end_ride(Ride ride) {
    std::cout << "Ending ride: " << ride.get_origin() << " to " << ride.get_destination() << std::endl;

    auto it = std::find(rides.begin(), rides.end(), ride);
    if (it != rides.end()) {
        rides.erase(it);
        std::cout << "Ride successfully ended." << std::endl;
    } else {
        std::cerr << "Error: Ride not found." << std::endl;
    }
}

// Method to print statistics of rides offered
void RideManager::print_ride_stats() const {
    std::cout << "Total rides offered: " << rides.size() << std::endl;
}

