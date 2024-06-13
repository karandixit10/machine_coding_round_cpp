#include "appointment.hpp"

Appointment::Appointment(int doctorId, int patientId, std::string timeKey) :
    doctorId(doctorId), patientId(patientId), timeKey(timeKey) {}


int Appointment::getDoctorId() {
    return doctorId;
}

int Appointment::getPatientId() {
    return patientId;
}

std::string Appointment::getTimeKey() {
    return timeKey;
}

