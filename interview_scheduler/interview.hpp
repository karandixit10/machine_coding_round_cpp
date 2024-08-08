#ifndef INTERVIEW_HPP
#define INTERVIEW_HPP

#include <vector>
#include <string>
#include <chrono>

using namespace std;

using TimePoint = chrono::system_clock::time_point;

struct Slot {
    TimePoint time;
    Slot(TimePoint t) : time(t) {}
    bool operator==(const Slot &other) const;
};

struct Interviewer {
    int id;
    string name;
    string email;
    vector<Slot> availableSlots;
    vector<string> interviewTypes;

    void addSlot(TimePoint slot);
    void addInterviewType(const string& type);
};

struct Interviewee {
    int id;
    string name;
    string email;
    vector<Slot> preferredSlots;
    vector<string> interviewTypes;

    void addSlot(TimePoint slot);
    void addInterviewType(const string& type);
};

struct Interview {
    int id;
    int interviewerId;
    int intervieweeId;
    string interviewType;
    Slot scheduledTime;
};

TimePoint make_time_point(int year, int month, int day, int hour, int minute);
vector<Slot> findMatchingSlots(const vector<Slot>& interviewerSlots, const vector<Slot>& intervieweeSlots);
vector<Interview> scheduleInterviews(vector<Interviewer>& interviewers, vector<Interviewee>& interviewees);
void printTimePoint(const TimePoint& tp);

#endif // INTERVIEW_HPP
