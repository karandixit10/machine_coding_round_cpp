#include "../include/doctor.hpp"
#include "../include/appointment.hpp"

Doctor::Doctor() noexcept : id(0), name(""), speciality(""){}

Doctor::Doctor(int id, const std::string &name, const std::string &speciality)
    : id(id), name(name), speciality(speciality) {}

void Doctor::declareAvailability(int startHour, int startMinute)
{
    std::string timeSlot = std::to_string(startHour) + ':' + (startMinute == 0 ? "00" : std::to_string(startMinute));
    availablity[timeSlot] = Slot(startHour, startMinute);
}

void Doctor::bookSlot(std::string timeSlot, int patientId)
{
    if (availablity[timeSlot].slotAvailable)
    {
        availablity[timeSlot].slotAvailable = false;
        appointments.push_back(Appointment(id, patientId, timeSlot));
    }
}

void Doctor::cancelSlot(std::string timeSlot)
{
    availablity[timeSlot].slotAvailable = true;
    // remove the timeslot
    appointments.erase(
        std::remove_if(appointments.begin(), appointments.end(),
                       [timeSlot](const Appointment &a)
                       { return a.timeSlot == timeSlot; }),
        appointments.end());
    if (!waitlist.empty())
    {
        int nextPatientId = waitlist.front();
        waitlist.pop();
        std::cout<<"booking for next patient";
        bookSlot(timeSlot, nextPatientId);
    }
}

void Doctor::viewAppointments()
{
    std::cout << "Appointments for " << name << "(" << speciality << "):\n";
    for (const auto &appointment : appointments)
    {
        std::cout << appointment.timeSlot << " - Patient ID:" << appointment.patientId << "\n";
    }
}