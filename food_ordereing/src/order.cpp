#include "../include/order.hpp"

// Constructor implementation to initialize an order with user information, ordered items, and status.
Order::Order(const std::string& user, const std::unordered_map<std::string, int>& items) 
    : user(user), items(items), status(OrderStatus::Created) {}

// Returns the list of ordered items.
std::unordered_map<std::string, int> Order::getItems() const {
    return items;
}

// Returns the status of the order.
OrderStatus Order::getStatus() const {
    return status;
}

// Sets the status of the order.
void Order::setStatus(OrderStatus status) {
    this->status = status;
}