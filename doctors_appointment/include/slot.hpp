#ifndef SLOT_HPP
#define SLOT_HPP

#include<string>

class Slot{
public:
    int     startHour;
    int     startMinute;
    bool    slotAvailable;
    
                    Slot        (int startHour = 0, int startMinute = 0);
    std::string     getTime     () const;
};

#endif