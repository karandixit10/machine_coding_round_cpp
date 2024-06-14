// RestaurantManager.hpp

#pragma once
#include <vector>
#include "restaurant.hpp"
#include "order.hpp"
#include "selectionStrategy.hpp"

// The RestaurantManager class manages the list of restaurants and handles orders.
class RestaurantManager {
public:
    void        addRestaurant       (const std::string& name, int maxOrders, double rating);
    void        updateMenuItemPrice (const std::string& restaurantName, const std::string& itemName, double price);
    void        addMenuItem         (const std::string& restaurantName, const std::string& itemName, double price);
    Restaurant* placeOrder          (Order& order, SelectionStrategy& strategy);
    void        completeOrder       (Restaurant* restaurant, Order& order);

private:
    std::vector<Restaurant*> restaurants; 
};