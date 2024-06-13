#include "system.hpp"

// Constructor
System::System() {}

// Register a new doctor with given ID, name, and speciality
void System::registerDoctor(int id, std::string name, std::string speciality) {
    doctors[id] = Doctor(id, name, speciality);
}

// Register a new patient with given ID and name
void System::registerPatient(int id, std::string name) {
    patients[id] = Patient(id, name);
}

// Declare a doctor's availability for a specific time slot
void System::declareAvailability(int doctorId, int startHour, int startMinute) {
    doctors[doctorId].declareAvailability(startHour, startMinute);
}

// Book an appointment for a patient with a doctor if available, or add the patient to the waitlist
void System::bookAppointment(int patientId, int doctorId, std::string timeKey) {
    if (patients.find(patientId) != patients.end() && doctors.find(doctorId) != doctors.end()) {
        Doctor &doctor = doctors[doctorId];
        Patient &patient = patients[patientId];
        if (doctor.availability.find(timeKey) != doctor.availability.end() && doctor.availability[timeKey].available) {
            doctor.bookSlot(timeKey, patientId);
            patient.bookAppointment(doctorId, timeKey);
        } else {
            std::cout << "Slot not available. Adding to waitlist.\n";
            doctor.waitlist.push(patientId);
        }
    }
}

// Cancel an appointment and handle the waitlist
void System::cancelAppointment(int patientId, int doctorId, std::string timeKey) {
    if (patients.find(patientId) != patients.end() && doctors.find(doctorId) != doctors.end()) {
        Doctor &doctor = doctors[doctorId];
        Patient &patient = patients[patientId];
        doctor.cancelSlot(timeKey);
        patient.cancelAppointment(timeKey);
    }
}

// Display all appointments for a specific doctor
void System::viewDoctorAppointments(int doctorId) {
    if (doctors.find(doctorId) != doctors.end()) {
        doctors[doctorId].viewAppointments();
    }
}

// Display all appointments for a specific patient
void System::viewPatientAppointments(int patientId) {
    if (patients.find(patientId) != patients.end()) {
        patients[patientId].viewAppointments();
    }
}
