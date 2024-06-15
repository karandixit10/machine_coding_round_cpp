#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "doctor.hpp"
#include "patient.hpp"
#include <map>
#include <string>

class System
{
private:
    std::map<int, Doctor>   doctors;
    std::map<int, Patient>  patients;

public:
            System                  ();
    void    registerDoctor          (int id, std::string name, std::string speciality);
    void    registerPatient         (int id, std::string name);
    void    declareAvailability     (int doctorId, int startHour, int startMinute);
    void    bookAppointment         (int patientId, int doctorId, std::string timeSlot);
    void    cancelAppointment       (int patientId, int doctorId, std::string timeSlot);
    void    viewDoctorAppointment   (int doctorId);
    void    viewPatientAppointment  (int patientId);
};

#endif