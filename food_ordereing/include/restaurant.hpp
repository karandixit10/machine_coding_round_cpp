#ifndef RESTAURANT_HPP
#define RESTAURANT_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include "../include/menuItem.hpp"
#include "../include/order.hpp"

class Restaurant {
public:
                    Restaurant              (const std::string& name, int maxOrders, double rating);
    std::string     getName                 () const;
    double          getRating               () const;
    void            addMenuItem             (const MenuItem& item);
    void            updateMenuItemPrice     (const std::string& itemName, double price);
    double          getMenuItemPrice        (const std::string& itemName) const;
    bool            canAcceptOrder          () const;
    void            acceptOrder             ();
    void            completeOrder           ();
    bool            canFulfillOrder          (const std::unordered_map<std::string, int>& items) const;

private:
    std::string                                 name; 
    int                                         maxOrders; 
    double                                      rating; 
    int                                         currentOrders; 
    std::unordered_map<std::string, MenuItem>   menu; 
};


#endif