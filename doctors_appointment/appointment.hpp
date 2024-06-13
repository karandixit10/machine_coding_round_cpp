#ifndef APPOINTMENT_HPP
#define APPOINTMENT_HPP

#include <string>

//Purpose: Represents an appointment between a patient and a doctor at a specific time slot.
class Appointment {
public:
    int         doctorId;         // ID of the doctor for the appointment
    int         patientId;        // ID of the patient for the appointment
    std::string timeKey;          // Time slot of the appointment as a string

                Appointment (int doctorId, int patientId, std::string timeKey);
    int         getDoctorId  ();
    int         getPatientId ();
    std::string getTimeKey();
};

#endif // APPOINTMENT_HPP
