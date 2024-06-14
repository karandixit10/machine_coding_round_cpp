#ifndef ORDER_HPP
#define ORDER_HPP

#include <string>
#include <unordered_map>
#include "orderStatus.hpp"

class Order {
public:
                                            Order       (const std::string& user, const std::unordered_map<std::string, int>& items);
    std::unordered_map<std::string, int>    getItems    () const;
    OrderStatus                             getStatus   () const;
    void                                    setStatus   (OrderStatus status);


private:
    std::string user;
    std::unordered_map<std::string, int> items;
    OrderStatus status;
};


#endif