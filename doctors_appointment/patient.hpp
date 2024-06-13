#ifndef PATIENT_HPP
#define PATIENT_HPP

#include <iostream>
#include <vector>
#include <string>
#include "appointment.hpp"

class Patient {
public:
    int                         id;                                     // ID of the patient
    std::string                 name;                                   // Name of the patient
    std::vector<Appointment>    appointments;                           // Vector of booked appointments

            Patient() noexcept;
            Patient(int id, const std::string& name);
            Patient(const Patient& other) = default;
            
            Patient& operator=(const Patient& other) = default;
            ~Patient() = default;
    void    bookAppointment     (int doctorId, std::string timeKey);      // Book an appointment with a doctor
    void    cancelAppointment   (std::string timeKey);                    // Cancel an appointment
    void    viewAppointments    ();                                       // View all appointments for the patient
};

#endif // PATIENT_HPP
