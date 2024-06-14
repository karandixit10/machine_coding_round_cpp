#include "../include/menuItem.hpp"

MenuItem::MenuItem() : name(""), price(0.0) {}

// Constructor implementation to initialize a menu item with a name and price.
MenuItem::MenuItem(const std::string& name, double price) : name(name), price(price) {}

// Returns the name of the menu item.
std::string MenuItem::getName() const {
    return name;
}

// Returns the price of the menu item.
double MenuItem::getPrice() const {
    return price;
}

// Sets the price of the menu item.
void MenuItem::setPrice(double price) {
    this->price = price;
}