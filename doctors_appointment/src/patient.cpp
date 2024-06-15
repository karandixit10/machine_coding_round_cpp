#include "../include/patient.hpp"
#include "../include/appointment.hpp"

Patient::Patient() noexcept : id (0), name("") {}

Patient::Patient(int id, const std::string &name) : id(id), name(name) {}

void Patient::bookAppointment(int doctorId, std::string timeSlot)
{
    appointments.push_back(Appointment(doctorId, id, timeSlot));
}

void Patient::cancelAppointment(std::string timeSlot)
{
    appointments.erase(
        std::remove_if(appointments.begin(), appointments.end(),
                       [timeSlot](const Appointment &a)
                       { return a.timeSlot == timeSlot; }),
        appointments.end());
}

void Patient::viewAppointments(){
    std::cout << "Appointments for " << name << "\n";
    for (const auto &appointment : appointments) {
        std::cout << appointment.timeSlot << " - Doctor ID:" << appointment.doctorId << "\n";
    }

}