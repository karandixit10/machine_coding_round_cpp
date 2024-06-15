#include "../include/system.hpp"

int main()
{
    System system;

    system.registerDoctor(1, "Dr. Curious", "Cardiologist");
    system.registerDoctor(2, "Dr. Dreadful", "Dermatologist");

    system.registerPatient(1, "Patient A");
    system.registerPatient(2, "Patient B");

    system.declareAvailability(1, 9, 0);
    system.declareAvailability(1, 9, 30);
    system.declareAvailability(2, 9, 30);
    system.declareAvailability(2, 10, 0);

    system.bookAppointment(1, 1, "9:00");
    system.bookAppointment(2, 1, "9:00"); // waitingList
    system.bookAppointment(2, 2, "10:00");

    system.viewDoctorAppointment(1);
    system.viewPatientAppointment(1);
    //system.viewDoctorAppointment(2);
    
    system.cancelAppointment(1, 1, "9:00");
    std::cout<<"After Cancelling\n";
    system.viewDoctorAppointment(1);
    system.viewPatientAppointment(2);

    return 0;
}