#ifndef DOCTOR_HPP
#define DOCTOR_HPP

#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include "slot.hpp"
#include "appointment.hpp"

class Doctor {
public:
    int                         id;                     // ID of the doctor
    std::string                 name;                   // Name of the doctor
    std::string                 speciality;             // Speciality of the doctor
    std::map<std::string, Slot> availability;           // Map of time slots and their availability
    std::queue<int>             waitlist;               // Queue for managing waitlist of patient IDs
    std::vector<Appointment>    appointments;  // Vector of booked appointments

            Doctor              () noexcept;
            Doctor              (int id, const std::string& name, const std::string& speciality);
            Doctor              (const Doctor& other) = default;
            Doctor& operator=   (const Doctor& other) = default;
            ~Doctor             () = default;

    void    declareAvailability (int startHour, int startMinute);                   // Declare availability for a given time slot
    void    bookSlot            (std::string timeKey, int patientId);               // Book a slot for a patient
    void    cancelSlot          (std::string timeKey);                              // Cancel a slot
    void    viewAppointments    ();                                                 // View all appointments for the doctor
};

#endif // DOCTOR_HPP
