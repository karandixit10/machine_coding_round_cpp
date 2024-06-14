// HighestRatingStrategy.cpp

#include "../include/highestRatingStrategy.hpp"

// Selects a restaurant that can fulfill the order with the highest rating.
Restaurant* HighestRatingStrategy::selectRestaurant(const std::vector<Restaurant*>& restaurants, const Order& order) {
    Restaurant* bestRestaurant = nullptr;
    double highestRating = 0;

    for (auto restaurant : restaurants) {
        if (restaurant->canAcceptOrder() && restaurant->canFulfillOrder(order.getItems())) {
            if (restaurant->getRating() > highestRating) {
                highestRating = restaurant->getRating();
                bestRestaurant = restaurant;
            }
        }
    }

    return bestRestaurant;
}