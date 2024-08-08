#include "interview.hpp"
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <stdexcept>

bool Slot::operator==(const Slot &other) const {
    return time == other.time;
}

void Interviewer::addSlot(TimePoint slot) {
    availableSlots.push_back(slot);
}

void Interviewer::addInterviewType(const string& type) {
    interviewTypes.push_back(type);
}

void Interviewee::addSlot(TimePoint slot) {
    preferredSlots.push_back(slot);
}

void Interviewee::addInterviewType(const string& type) {
    interviewTypes.push_back(type);
}

TimePoint make_time_point(int year, int month, int day, int hour, int minute) {
    std::tm tm = {};
    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;
    tm.tm_hour = hour;
    tm.tm_min = minute;
    return std::chrono::system_clock::from_time_t(std::mktime(&tm));
}

vector<Slot> findMatchingSlots(const vector<Slot>& interviewerSlots, const vector<Slot>& intervieweeSlots) {
    vector<Slot> matchingSlots;
    for (const auto& slot : interviewerSlots) {
        if (std::find(intervieweeSlots.begin(), intervieweeSlots.end(), slot) != intervieweeSlots.end()) {
            matchingSlots.push_back(slot);
        }
    }
    return matchingSlots;
}

vector<Interview> scheduleInterviews(vector<Interviewer>& interviewers, vector<Interviewee>& interviewees) {
    vector<Interview> scheduledInterviews;
    int interviewId = 1;

    for (auto& interviewee : interviewees) {
        for (auto& interviewer : interviewers) {
            vector<string> commonTypes;
            std::set_intersection(interviewer.interviewTypes.begin(), interviewer.interviewTypes.end(),
                                  interviewee.interviewTypes.begin(), interviewee.interviewTypes.end(),
                                  std::back_inserter(commonTypes));

            if (!commonTypes.empty()) {
                vector<Slot> matchingSlots = findMatchingSlots(interviewer.availableSlots, interviewee.preferredSlots);
                if (!matchingSlots.empty()) {
                    Interview interview = {interviewId++, interviewer.id, interviewee.id, commonTypes[0], matchingSlots[0]};
                    scheduledInterviews.push_back(interview);

                    interviewer.availableSlots.erase(std::remove(interviewer.availableSlots.begin(), interviewer.availableSlots.end(), matchingSlots[0]), interviewer.availableSlots.end());
                    interviewee.preferredSlots.erase(std::remove(interviewee.preferredSlots.begin(), interviewee.preferredSlots.end(), matchingSlots[0]), interviewee.preferredSlots.end());
                    break;
                }
            }
        }
    }
    return scheduledInterviews;
}

void printTimePoint(const TimePoint& tp) {
    std::time_t time = std::chrono::system_clock::to_time_t(tp);
    std::tm* tm = std::localtime(&time);
    std::cout << std::put_time(tm, "%Y-%m-%d %H:%M") << "\n";
}
