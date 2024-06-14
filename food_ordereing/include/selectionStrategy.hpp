#pragma once
#include <vector>
#include "restaurant.hpp"
#include "order.hpp"

// Abstract base class for selection strategies.
class SelectionStrategy {
public:
    // Pure virtual function to select a restaurant based on the strategy.
    virtual Restaurant* selectRestaurant(const std::vector<Restaurant*>& restaurants, const Order& order) = 0;
};