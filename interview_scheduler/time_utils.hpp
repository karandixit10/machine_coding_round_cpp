#ifndef TIME_UTILS_HPP
#define TIME_UTILS_HPP

#include <chrono>

// Define a type alias for convenience
using TimePoint = std::chrono::system_clock::time_point;

// Function to create a time_point
TimePoint make_time_point(int year, int month, int day, int hour, int minute);

// Function to print a time_point
void printTimePoint(const TimePoint& tp);

#endif // TIME_UTILS_HPP
