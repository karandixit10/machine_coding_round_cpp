// HighestRatingStrategy.hpp

#pragma once
#include "selectionStrategy.hpp"

// The HighestRatingStrategy class selects a restaurant based on the highest rating strategy.
class HighestRatingStrategy : public SelectionStrategy {
public:
    // Selects a restaurant that can fulfill the order with the highest rating.
    Restaurant* selectRestaurant(const std::vector<Restaurant*>& restaurants, const Order& order) override;
};