#ifndef PATIENT_HPP
#define PATIENT_HPP

#include "appointment.hpp"
#include<string>
#include<vector>
#include<iostream>

class Patient {

public:
    int id;
    std::string name;
    std::vector<Appointment> appointments;

            Patient             () noexcept;
            Patient             (int id, const std::string& name);   
            Patient             (const Patient& other) = default;
           ~Patient             () = default;
    void    bookAppointment     (int doctorId, std::string timeSlot);
    void    cancelAppointment   (std::string timeSlot);
    void    viewAppointments    ();

};


#endif