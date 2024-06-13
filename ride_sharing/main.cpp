#include "User.hpp"
#include "Vehicle.hpp"
#include "Ride.hpp"
#include "RideManager.hpp"
#include <iostream>

int main()
{
    // Create instances of users
    User rohan("Rohan", 36);
    User shashank("Shashank", 29);
    User nandini("Nandini", 29);
    User shipra("Shipra", 27);
    User gaurav("Gaurav", 29);
    User rahul("Rahul", 35);

    // Add vehicles to users
    Vehicle swift("Swift", "KA-01-12345", 5);
    rohan.add_vehicle(swift);

    Vehicle baleno("Baleno", "TS-05-62395", 5);
    shashank.add_vehicle(baleno);

    Vehicle polo("Polo", "KA-05-41491", 5);
    shipra.add_vehicle(polo);

    Vehicle activa("Activa", "KA-12-12332", 2);
    shipra.add_vehicle(activa);

    Vehicle xuv("XUV", "KA-05-1234", 7);
    rahul.add_vehicle(xuv);

    // Create a RideManager instance
    RideManager rideManager;

    // Add users to RideManager
    rideManager.add_user(rohan);
    rideManager.add_user(shashank);
    rideManager.add_user(nandini);
    rideManager.add_user(shipra);
    rideManager.add_user(gaurav);
    rideManager.add_user(rahul);

    // Offer rides
    rideManager.offer_ride(Ride(swift, "Hyderabad", "Bangalore", 1));
    rideManager.offer_ride(Ride(activa, "Bangalore", "Mysore", 1));
    rideManager.offer_ride(Ride(polo, "Bangalore", "Mysore", 2));
    rideManager.offer_ride(Ride(baleno, "Hyderabad", "Bangalore", 2));
    rideManager.offer_ride(Ride(xuv, "Hyderabad", "Bangalore", 5));
    // This should fail since rohan has already offered a ride with the same vehicle and destination.
    rideManager.offer_ride(Ride(swift, "Bangalore", "Pune", 1));

    // Find rides for users
    std::vector<Ride> ridesNandini = rideManager.select_ride("Bangalore", "Mysore", 1, "MostVacant");
    std::cout << "Nandini: " << ridesNandini.size() << " Taken, 0 Offered" << std::endl;

    std::vector<Ride> ridesGaurav = rideManager.select_ride("Bangalore", "Mysore", 1, "PreferredVehicle=Activa");
    std::cout << "Gaurav: " << ridesGaurav.size() << " Taken, 0 Offered" << std::endl;

    std::vector<Ride> ridesShashank = rideManager.select_ride("Mumbai", "Bangalore", 1, "MostVacant");
    std::cout << "Shashank: " << ridesShashank.size() << " Taken, 0 Offered" << std::endl;

    std::vector<Ride> ridesRohan = rideManager.select_ride("Hyderabad", "Bangalore", 1, "PreferredVehicle=Baleno");
    std::cout << "Rohan: " << ridesRohan.size() << " Taken, 0 Offered" << std::endl;

    std::vector<Ride> ridesShipra = rideManager.select_ride("Hyderabad", "Bangalore", 1, "PreferredVehicle=Polo");
    std::cout << "Shipra: " << ridesShipra.size() << " Taken, 0 Offered" << std::endl;

    // End rides
    if (!ridesNandini.empty())
    {
        rideManager.end_ride(ridesNandini[0]);
    }
    if (!ridesGaurav.empty())
    {
        rideManager.end_ride(ridesGaurav[0]);
    }
    if (!ridesShashank.empty())
    {
        rideManager.end_ride(ridesShashank[0]);
    }
    if (!ridesRohan.empty())
    {
        rideManager.end_ride(ridesRohan[0]);
    }

    // Print ride statistics
    rideManager.print_ride_stats();

    return 0;
}
