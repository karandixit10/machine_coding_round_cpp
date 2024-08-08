#include "interview.hpp"
#include <iostream>
#include <unordered_map>

int main() {
    try {
        // Create some example interviewers
        Interviewer interviewer1 = {1, "Eve", "eve@example.com", 
            {Slot(make_time_point(2024, 6, 16, 9, 0)), Slot(make_time_point(2024, 6, 16, 13, 0))}, {"Technical"}};
        Interviewer interviewer2 = {2, "Frank", "frank@example.com", 
            {Slot(make_time_point(2024, 6, 16, 10, 0)), Slot(make_time_point(2024, 6, 16, 14, 0))}, {"HR"}};
        Interviewer interviewer3 = {3, "Grace", "grace@example.com", 
            {Slot(make_time_point(2024, 6, 16, 11, 0)), Slot(make_time_point(2024, 6, 16, 15, 0))}, {"Technical", "HR"}};

        vector<Interviewer> interviewers = {interviewer1, interviewer2, interviewer3};

        // Add more slots and interview types dynamically
        interviewer1.addSlot(make_time_point(2024, 6, 16, 16, 0));
        interviewer2.addInterviewType("Behavioral");

        // Create some example interviewees
        Interviewee interviewee1 = {1, "Hannah", "hannah@example.com", 
            {Slot(make_time_point(2024, 6, 16, 9, 0)), Slot(make_time_point(2024, 6, 16, 10, 0))}, {"Technical"}};
        Interviewee interviewee2 = {2, "Ian", "ian@example.com", 
            {Slot(make_time_point(2024, 6, 16, 13, 0)), Slot(make_time_point(2024, 6, 16, 14, 0))}, {"HR"}};
        Interviewee interviewee3 = {3, "Julia", "julia@example.com", 
            {Slot(make_time_point(2024, 6, 16, 15, 0)), Slot(make_time_point(2024, 6, 16, 9, 0))}, {"Technical", "HR"}};

        vector<Interviewee> interviewees = {interviewee1, interviewee2, interviewee3};

        // Add more slots and interview types dynamically
        interviewee3.addSlot(make_time_point(2024, 6, 16, 16, 0));
        interviewee2.addInterviewType("Behavioral");

        // Schedule interviews
        vector<Interview> scheduledInterviews = scheduleInterviews(interviewers, interviewees);

        // Create maps for quick lookup of names by ID
        unordered_map<int, string> interviewerNames;
        for (const auto& interviewer : interviewers) {
            interviewerNames[interviewer.id] = interviewer.name;
        }

        unordered_map<int, string> intervieweeNames;
        for (const auto& interviewee : interviewees) {
            intervieweeNames[interviewee.id] = interviewee.name;
        }

        // Print scheduled interviews with names
        for (const auto& interview : scheduledInterviews) {
            cout << "Interview ID: " << interview.id << "\n";
            cout << "Interviewer: " << interviewerNames[interview.interviewerId] << "\n";
            cout << "Interviewee: " << intervieweeNames[interview.intervieweeId] << "\n";
            cout << "Interview Type: " << interview.interviewType << "\n";
            cout << "Scheduled Time: ";
            printTimePoint(interview.scheduledTime.time);
            cout << "\n\n";
        }

        // Testing with invalid slot number (handling exception)
        int invalidSlotNumber = 9;
        if (invalidSlotNumber >= scheduledInterviews.size()) {
            throw std::out_of_range("Invalid slot number: " + std::to_string(invalidSlotNumber));
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
