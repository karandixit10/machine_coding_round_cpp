#ifndef DOCTOR_HPP
#define DOCTOR_HPP
#include "../include/slot.hpp"
#include "../include/appointment.hpp"
#include<string>
#include<map>
#include<queue>
#include<iostream>

class Doctor{
public:
    int                         id;
    std::string                 name;
    std::string                 speciality;
    std::map<std::string, Slot> availablity;
    std::queue<int>             waitlist;
    std::vector<Appointment>    appointments;

            Doctor              () noexcept;
            Doctor              (int id, const std::string& name, const std::string& speciality);
            Doctor              (const Doctor& other) = default;
            ~Doctor             () = default;
    void    declareAvailability (int startHour, int startMinute);
    void    bookSlot            (std::string timeSlot, int patientId);
    void    cancelSlot          (std::string timeSlot);
    void    viewAppointments    ();
};

#endif