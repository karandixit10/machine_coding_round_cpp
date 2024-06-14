#ifndef MENUITEM_HPP
#define MENUITEM_HPP

#include <string>

class MenuItem {
public:
                    MenuItem        (); 
                    MenuItem        (const std::string& name, double price);
    std::string     getName         () const;
    double          getPrice        () const;
    void            setPrice        (double newPrice);

private:
    std::string name; 
    double      price;
};
#endif