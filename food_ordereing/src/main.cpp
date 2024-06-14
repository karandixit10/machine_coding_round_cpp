// Main.cpp

#include <iostream>
#include "../include/restaurantManager.hpp"
#include "../include/lowestCostStrategy.hpp"
#include "../include/highestRatingStrategy.hpp"
#include "../include/orderStatus.hpp"

int main() {
    RestaurantManager manager;

    // Onboard restaurants
    manager.addRestaurant("R1", 5, 4.5);
    manager.addMenuItem("R1", "Veg Biryani", 100);
    manager.addMenuItem("R1", "Paneer Butter Masala", 150);

    manager.addRestaurant("R2", 5, 4.0);
    manager.addMenuItem("R2", "Paneer Butter Masala", 175);
    manager.addMenuItem("R2", "Idli", 10);
    manager.addMenuItem("R2", "Dosa", 50);
    manager.addMenuItem("R2", "Veg Biryani", 80);

    manager.addRestaurant("R3", 1, 4.9);
    manager.addMenuItem("R3", "Gobi Manchurian", 150);
    manager.addMenuItem("R3", "Idli", 15);
    manager.addMenuItem("R3", "Paneer Butter Masala", 175);
    manager.addMenuItem("R3", "Dosa", 30);

    // Update menu
    manager.addMenuItem("R1", "Chicken65", 250);
    manager.updateMenuItemPrice("R2", "Paneer Butter Masala", 150);

    // Place orders using LowestCostStrategy
    LowestCostStrategy lowestCostStrategy;
    Order order1("Ashwin", {{"Idli", 3}, {"Dosa", 1}});
    Restaurant* r1 = manager.placeOrder(order1, lowestCostStrategy);
    if (r1) {
        std::cout << "Order1 assigned to " << r1->getName() << std::endl;
    } else {
        std::cout << "Order1 can't be fulfilled" << std::endl;
    }

    Order order2("Harish", {{"Idli", 3}, {"Dosa", 1}});
    Restaurant* r2 = manager.placeOrder(order2, lowestCostStrategy);
    if (r2) {
        std::cout << "Order2 assigned to " << r2->getName() << std::endl;
    } else {
        std::cout << "Order2 can't be fulfilled" << std::endl;
    }

    // Place order using HighestRatingStrategy
    HighestRatingStrategy highestRatingStrategy;
    Order order3("Shruthi", {{"Veg Biryani", 3}});
    Restaurant* r3 = manager.placeOrder(order3, highestRatingStrategy);
    if (r3) {
        std::cout << "Order3 assigned to " << r3->getName() << std::endl;
    } else {
        std::cout << "Order3 can't be fulfilled" << std::endl;
    }

    // Complete order
    manager.completeOrder(r1, order1);

    Order order4("Harish", {{"Idli", 3}, {"Dosa", 1}});
    Restaurant* r4 = manager.placeOrder(order4, lowestCostStrategy);
    if (r4) {
        std::cout << "Order4 assigned to " << r4->getName() << std::endl;
    } else {
        std::cout << "Order4 can't be fulfilled" << std::endl;
    }

    Order order5("xyz", {{"Paneer Tikka", 1}, {"Idli", 1}});
    Restaurant* r5 = manager.placeOrder(order5, lowestCostStrategy);
    if (!r5) {
        std::cout << "Order5 can't be fulfilled" << std::endl;
    } else {
        std::cout << "Order5 assigned to " << r5->getName() << std::endl;
    }

    return 0;
}