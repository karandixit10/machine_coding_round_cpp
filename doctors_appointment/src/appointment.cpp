#include "../include/appointment.hpp"

Appointment::Appointment(int doctorId, int patientId, std::string timeSlot)
    : doctorId(doctorId), patientId(patientId), timeSlot(timeSlot){}

int Appointment::getDoctorId(){
    return doctorId;
}

int Appointment::getPatientId(){
    return patientId;
}

std::string Appointment::getTimeSlot(){
    return timeSlot;
}