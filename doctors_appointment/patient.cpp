#include "patient.hpp"
#include "appointment.hpp"

// Default constructor
Patient::Patient() noexcept : id(0), name("") {}

// Parameterized constructor
Patient::Patient(int id, const std::string& name) : id(id), name(name) {}

// Add an appointment to the patient's list
void Patient::bookAppointment(int doctorId, std::string timeKey) {
    appointments.push_back(Appointment(doctorId, id, timeKey));
}

// Cancel an appointment by removing it from the patient's list
void Patient::cancelAppointment(std::string timeKey) {
    appointments.erase(
        std::remove_if(appointments.begin(), appointments.end(),
                       [timeKey](const Appointment &a) { return a.timeKey == timeKey; }),
        appointments.end()
    );
}

// Display all appointments for the patient
void Patient::viewAppointments() {
    std::cout << "Appointments for " << name << ":\n";
    for (const auto &appointment : appointments) {
        std::cout << appointment.timeKey << " - Doctor ID: " << appointment.doctorId << "\n";
    }
}