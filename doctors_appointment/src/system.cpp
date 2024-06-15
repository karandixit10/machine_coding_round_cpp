#include "../include/system.hpp"

System::System() {}

void System::registerDoctor(int id, std::string name, std::string speciality)
{
    std::cout<<"Welcome " <<  name << "\n";
    doctors[id] = Doctor(id, name, speciality);
}

void System::registerPatient(int id, std::string name)
{
    std::cout<<"Welcome " <<  name << "\n";
    patients[id] = Patient(id, name);
}

void System::declareAvailability(int doctorId, int startHour, int startMinute)
{
    doctors[doctorId].declareAvailability(startHour, startMinute);
}

void System::bookAppointment(int patientId, int doctorId, std::string timeSlot)
{
    if (patients.find(patientId) != patients.end() && doctors.find(doctorId) != doctors.end())
    {
        Doctor &doctor = doctors[doctorId];
        Patient &patient = patients[patientId];

        if (doctor.availablity.find(timeSlot) != doctor.availablity.end() &&
            doctor.availablity[timeSlot].slotAvailable)
        {
            doctor.bookSlot(timeSlot, patientId);
            patient.bookAppointment(doctorId, timeSlot);
        }
        else {
            std::cout<<"Slot not available, Adding " << patient.name <<" to waitlist.\n";
            doctor.waitlist.push(patientId);
        }
    }
}

void System::cancelAppointment(int patientId, int doctorId, std::string timeSlot) {
    if(patients.find(patientId) != patients.end() && doctors.find(doctorId) != doctors.end()){
        Doctor &doctor = doctors[doctorId];
        Patient &patient = patients[patientId];
        doctor.cancelSlot(timeSlot);
        patient.cancelAppointment(timeSlot);
    }
}


void System::viewDoctorAppointment(int doctorId){
    if(doctors.find(doctorId) != doctors.end()){
        doctors[doctorId].viewAppointments();
    }
}

void System::viewPatientAppointment(int patientId){
    if(patients.find(patientId) != patients.end()){
        patients[patientId].viewAppointments();
    }
}