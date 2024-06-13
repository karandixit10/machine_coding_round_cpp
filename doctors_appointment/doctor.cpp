#include "doctor.hpp"
#include "appointment.hpp"

Doctor::Doctor() noexcept : id(0), name(""), speciality("") {}

// Parameterized constructor
Doctor::Doctor(int id, const std::string& name, const std::string& speciality)
    : id(id), name(name), speciality(speciality) {}

// Declare availability for a specific time slot
void Doctor::declareAvailability(int startHour, int startMinute)
{
    std::string timeKey = std::to_string(startHour) + ":" + (startMinute == 0 ? "00" : std::to_string(startMinute));
    availability[timeKey] = Slot(startHour, startMinute);
}

// Book a slot for a patient, or add the patient to the waitlist if the slot is taken
void Doctor::bookSlot(std::string timeKey, int patientId)
{
    if (availability[timeKey].available)
    {
        availability[timeKey].available = false;
        appointments.push_back(Appointment(id, patientId, timeKey));
    }
    else
    {
        waitlist.push(patientId);
    }
}

// Cancel a slot and reassign it to the next patient in the waitlist if available
void Doctor::cancelSlot(std::string timeKey)
{
    availability[timeKey].available = true;
    appointments.erase(
        std::remove_if(appointments.begin(), appointments.end(),
                       [timeKey](const Appointment &a)
                       { return a.timeKey == timeKey; }),
        appointments.end());
    if (!waitlist.empty())
    {
        int nextPatientId = waitlist.front();
        waitlist.pop();
        bookSlot(timeKey, nextPatientId);
    }
}

// Display all appointments for the doctor
void Doctor::viewAppointments()
{
    std::cout << "Appointments for Dr. " << name << " (" << speciality << "):\n";
    for (const auto &appointment : appointments)
    {
        std::cout << appointment.timeKey << " - Patient ID: " << appointment.patientId << "\n";
    }
}
