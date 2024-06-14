#include "../include/restaurant.hpp"

Restaurant::Restaurant(const std::string& name, int maxOrders, double rating)
    : name(name), maxOrders(maxOrders), rating(rating), currentOrders(0) {}

// Returns the name of the restaurant.
std::string Restaurant::getName() const {
    return name;
}

// Returns the rating of the restaurant.
double Restaurant::getRating() const {
    return rating;
}

// Adds a menu item to the restaurant's menu.
void Restaurant::addMenuItem(const MenuItem& item) {
    menu[item.getName()] = item;
}

// Updates the price of a menu item in the restaurant's menu.
void Restaurant::updateMenuItemPrice(const std::string& itemName, double price) {
    auto it = menu.find(itemName);
    if (it != menu.end()) {
        it->second.setPrice(price);
    } else {
        // Handle the case where the item doesn't exist
        // For example, add the item with the new price
        menu[itemName] = MenuItem(itemName, price);
    }
}

// Returns the price of a menu item.
double Restaurant::getMenuItemPrice(const std::string& itemName) const {
    if (menu.find(itemName) != menu.end()) {
        return menu.at(itemName).getPrice();
    }
    return -1; // Indicating the item doesn't exist.
}

// Checks if the restaurant can accept more orders.
bool Restaurant::canAcceptOrder() const {
    return currentOrders < maxOrders;
}

// Accepts a new order.
void Restaurant::acceptOrder() {
    if (canAcceptOrder()) {
        ++currentOrders;
    }
}

// Completes an ongoing order.
void Restaurant::completeOrder() {
    if (currentOrders > 0) {
        --currentOrders;
    }
}

// Checks if the restaurant can fulfill the given items.
bool Restaurant::canFulfillOrder(const std::unordered_map<std::string, int>& items) const {
    for (const auto& item : items) {
        if (menu.find(item.first) == menu.end()) {
            return false;
        }
    }
    return true;
}