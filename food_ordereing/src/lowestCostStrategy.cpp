// LowestCostStrategy.cpp

#include "../include/lowestCostStrategy.hpp"

// Selects a restaurant that can fulfill the order with the lowest cost.
Restaurant* LowestCostStrategy::selectRestaurant(const std::vector<Restaurant*>& restaurants, const Order& order) {
    Restaurant* bestRestaurant = nullptr;
    double lowestCost = std::numeric_limits<double>::max();

    for (auto restaurant : restaurants) {
        if (restaurant->canAcceptOrder() && restaurant->canFulfillOrder(order.getItems())) {
            double cost = 0;
            for (const auto& item : order.getItems()) {
                cost += restaurant->getMenuItemPrice(item.first) * item.second;
            }
            if (cost < lowestCost) {
                lowestCost = cost;
                bestRestaurant = restaurant;
            }
        }
    }

    return bestRestaurant;
}