// RestaurantManager.cpp

#include "../include/restaurantManager.hpp"

// Adds a new restaurant.
void RestaurantManager::addRestaurant(const std::string& name, int maxOrders, double rating) {
    restaurants.push_back(new Restaurant(name, maxOrders, rating));
}

// Updates the price of a menu item in a specific restaurant.
void RestaurantManager::updateMenuItemPrice(const std::string& restaurantName, const std::string& itemName, double price) {
    for (auto restaurant : restaurants) {
        if (restaurant->getName() == restaurantName) {
            restaurant->updateMenuItemPrice(itemName, price);
            break;
        }
    }
}

// Adds a new menu item to a specific restaurant.
void RestaurantManager::addMenuItem(const std::string& restaurantName, const std::string& itemName, double price) {
    for (auto restaurant : restaurants) {
        if (restaurant->getName() == restaurantName) {
            restaurant->addMenuItem(MenuItem(itemName, price));
            break;
        }
    }
}

// Places an order and assigns it to a restaurant based on the selection strategy.
Restaurant* RestaurantManager::placeOrder(Order& order, SelectionStrategy& strategy) {
    Restaurant* selectedRestaurant = strategy.selectRestaurant(restaurants, order);
    if (selectedRestaurant) {
        selectedRestaurant->acceptOrder();
        order.setStatus(OrderStatus::Accepted);
    }
    return selectedRestaurant;
}

// Marks an order as completed for a specific restaurant.
void RestaurantManager::completeOrder(Restaurant* restaurant, Order& order) {
    restaurant->completeOrder();
    order.setStatus(OrderStatus::Completed);
}