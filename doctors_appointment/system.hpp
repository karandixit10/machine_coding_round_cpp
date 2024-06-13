#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <map>
#include <string>
#include "doctor.hpp"
#include "patient.hpp"

class System {
private:
    std::map<int, Doctor>   doctors;                                                        // Map of doctor IDs to Doctor objects
    std::map<int, Patient>  patients;                                                       // Map of patient IDs to Patient objects

public:
            System                  ();                                                     // Constructor
    void    registerDoctor          (int id, std::string name, std::string speciality);     // Register a new doctor
    void    registerPatient         (int id, std::string name);                             // Register a new patient
    void    declareAvailability     (int doctorId, int startHour, int startMinute);         // Declare a doctor's availability
    void    bookAppointment         (int patientId, int doctorId, std::string timeKey);     // Book an appointment
    void    cancelAppointment       (int patientId, int doctorId, std::string timeKey);     // Cancel an appointment
    void    viewDoctorAppointments  (int doctorId);                                         // View all appointments for a specific doctor
    void    viewPatientAppointments (int patientId);                                        // View all appointments for a specific patient
};

#endif // SYSTEM_HPP
