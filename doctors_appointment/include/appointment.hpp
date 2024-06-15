#ifndef APPOINTMENT_HPP
#define APPOINTMENT_HPP

#include<string>

class Appointment{
public:
    int         doctorId;
    int         patientId;
    std::string timeSlot;

                Appointment     (int doctorId, int patientId, std::string timeSlot);
    int         getDoctorId     ();
    int         getPatientId    ();
    std::string getTimeSlot     ();
};

#endif