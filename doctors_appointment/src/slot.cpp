#include "../include/slot.hpp"

//Constructor
Slot::Slot(int startHour, int startMinute)
    : startHour(startHour), startMinute(startMinute), slotAvailable(true){}


//Get slot's time in string format
std::string Slot::getTime() const {
    return std::to_string(startHour) + ':' + (startMinute == 0 ? "00" : std::to_string(startMinute));
}