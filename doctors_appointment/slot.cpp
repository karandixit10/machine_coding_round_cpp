#include "slot.hpp"

// Constructor initializes slot with given time and sets availability to true
Slot::Slot(int startHour, int startMinute) : startHour(startHour), startMinute(startMinute), available(true) {}

// Returns the slot's time as a formatted string
std::string Slot::getTime() const {
    return std::to_string(startHour) + ":" + (startMinute == 0 ? "00" : std::to_string(startMinute));
}
