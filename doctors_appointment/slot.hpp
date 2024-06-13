#ifndef SLOT_HPP
#define SLOT_HPP

#include <string>

//Purpose: Represents a 30-minute time slot during which a doctor might be available for an appointment.
class Slot {
public:
    int startHour;
    int startMinute;
    bool available;
    
    Slot(int startHour = 0, int startMinute = 0);
    std::string getTime() const;
};

#endif // SLOT_HPP
