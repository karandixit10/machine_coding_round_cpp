# FLIPMED (Low Level Design)

**Description**:

We are required to build an app that lets patients connect to doctors and book appointments. The day is divided into time slots of 30 mins each, starting from 9 am to 9 pm. Doctors can login to the portal and declare their availability for the given day in terms of slots.  Patients can book appointments/ cancel existing appointments. **For simplicity you can assume that the doctors’ availability is declared for that particular day only.**

**Features**:

- A new doctor should be able to register, and mention his/her speciality among (Cardiologist, Dermatologist, Orthopedic, General Physician)
- A doctor should be able to declare his/her availability in each slot for the day. For example, the slots will be of 30 mins like 9am-9.30am, 9.30am-10am..
- Patients should be able to register. Patients should be able to search available slots based on speciality.
- The slots should be displayed in a ranked fashion. Default ranking strategy should be to rank by start time. But we should be able to plugin more strategies like Doctor’s rating etc in future.
- Patients should be able to book appointments with a doctor for an available slot.A patient can book multiple appointments in a day. A patient cannot book two appointments with two different doctors in the same time slot.
- Patients can also cancel an appointment, in which case that slot becomes available for someone else to book.
- Build a waitlist feature:
- If the patient wishes to book a slot for a particular doctor that is already booked, then add this patient to the waitlist.
- If the patient with whom the appointment was booked originally cancels the appointment, then the first in the waitlist gets the appointment.
- A patient/doctor should be able to view his/her booked appointments for the day.

**Bonus** **requirements**:

- Trending Doctor: Maintain at any point of time which doctor has the most appointments.
- Different ranking strategy - use rating of doctor as a strategy to display a list of available doctors for a given specialization.

# **Expectations and guidelines:**

1. Time: 120mins
2. You are allowed to access the internet only for syntax purposes.
3. You are free to use any language of your choice.
4. Do not use any external libraries. All of the code should be your own.
5. Implement the code using only in-memory data structures or basic file handling. The use of databases is **not allowed**.
6. **Do not create** any UI for the application.
7. Write a driver class for demo purpose which will execute all the commands at one place in the code and test cases.
8. Create the sample data yourself. You can put it into a file, test cases or the main driver program itself.
9. Make sure that you can execute your code and show that it is working.
10. Please prioritize code compilation, execution and completion.
11. Make sure that code is functionally correct.
12. Work on the expected output first and then add good-to-have features of your own.
13. Code should be modular and readable.
14. Separation of concern should be addressed.
15. Code should easily accommodate new requirements with minimal changes.
16. Code should be modular and have the correct abstractions.
17. Code should be legible, readable, and DRY.
18. Code should be easily testable.
19. Please focus on the Bonus requirement only after ensuring the required features are complete and demoable. The bonus portion would not be evaluated if any of the required functionality is missing

**Sample Test cases:**

The input/output need not be exactly in this format but the functionality should remain intact

i: input

o: output

i:registerDoc -> Curious-> Cardiologist

o: Welcome Dr. Curious !!

i: markDocAvail: Curious 9:30-10:30

o: Sorry Dr. Curious slots are 30 mins only

i: markDocAvail: Curious 9:30-10:00, 12:30-13:00, 16:00-16:30

o: Done Doc!

i:registerDoc -> Dreadful-> Dermatologist

o: Welcome Dr. Dreadful !!

i: markDocAvail: Dreadful 9:30-10:00, 12:30-13:00, 16:00-16:30

o: Done Doc!

i: showAvailByspeciality: Cardiologist

o: Dr.Curious: (9:30-10:00)

o: Dr.Curious: (12:30-13:00)

o: Dr.Curious: (16:00-16:30)

i: registerPatient ->PatientA

o: PatientA registered successfully.

i:  bookAppointment: (PatientA, Dr.Curious, 12:30)

O: Booked. Booking id: 1234

i:showAvailByspeciality: Cardiologist

o: Dr.Curious: (9:30-10:00)

o: Dr.Curious: (16:00-16:30)

i: cancelBookingId: 1234

o: Booking Cancelled

i: showAvailByspeciality: Cardiologist

o: Dr.Curious: (9:30-10:00)

o: Dr.Curious: (12:30-13:00)

o: Dr.Curious: (16:00-16:30)

i: bookAppointment: (PatientB, Dr.Curious, 12:30)

o: Booked. Booking id: 5678

i:registerDoc -> Daring-> Dermatologist

o: Welcome Dr. Daring !!

i: markDocAvail: Daring 11:30-12:00 14:00-14:30

o: Done Doc!

i: showAvailByspeciality: Dermatologist

o: Dr.Dreadful: (9:30-10:00)

o: Dr.Daring: (11:30-12:00)

o: Dr.Dreadful: (12:30-13:00)

o:Dr.Daring:(14:00-14:30)

o: Dr.Dreadful: (16:00-16:30)

i: bookAppointment: (PatientF, Dr.Daring, 11:30)

o: Booked. Booking id: 5587

i: bookAppointment: (PatientA, Dr.Curious, 12:30)

o: Booked. Booking id: 5678

i: bookAppointment: (PatientF, Dr.Curious, 9:30)

o: Booked. Booking id: 5280

i: bookAppointment: (PatientC, Dr.Curious, 16:00)

o: Booked. Booking id: 5701

i: showAvailByspeciality: Cardiologist

o: Dr.Curious: No slots available

i: bookAppointment: (PatientD, Dr.Curious, 16:00, waitlist=true)

o: Added to the waitlist. Booking id: 5710

i: cancelBookingId: 5701

o: Booking Cancelled

o: Booking confirmed for Booking id: 5710

i: showAppointmentsBooked(PatientF)

o: Booking id: 5280, Dr Curious 9:30

o: Booking id: 5587 , Dr Daring 11:30