// LowestCostStrategy.hpp

#pragma once
#include "selectionStrategy.hpp"

// The LowestCostStrategy class selects a restaurant based on the lowest cost strategy.
class LowestCostStrategy : public SelectionStrategy {
public:
    // Selects a restaurant that can fulfill the order with the lowest cost.
    Restaurant* selectRestaurant(const std::vector<Restaurant*>& restaurants, const Order& order) override;
};