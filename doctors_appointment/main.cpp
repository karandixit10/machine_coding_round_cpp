#include "system.hpp"

int main() {
    // Create a system instance
    System system;

    // Register doctors
    system.registerDoctor(1, "Dr. Mehta", "Cardiologist");
    system.registerDoctor(2, "Dr. Aggarwal", "Dermatologist");
    
    // Register patients
    system.registerPatient(1, "Binod");
    system.registerPatient(2, "Mukesh");
    
    // Declare availability for doctors
    system.declareAvailability(1, 9, 0);
    system.declareAvailability(1, 9, 30);
    system.declareAvailability(2, 10, 0);
    
    // Book appointments
    system.bookAppointment(1, 1, "9:00");
    system.bookAppointment(2, 1, "9:00"); // This will go to the waitlist
    system.bookAppointment(2, 2, "10:00");
    
    // View appointments for doctors and patients
    system.viewDoctorAppointments(1);
    system.viewPatientAppointments(1);
    
    // Cancel an appointment
    system.cancelAppointment(1, 1, "9:00");
    
    // View appointments again after cancellation
    system.viewDoctorAppointments(1);
    system.viewPatientAppointments(2);
    
    return 0;
}
