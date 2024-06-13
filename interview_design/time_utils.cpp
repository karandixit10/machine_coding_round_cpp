#include "time_utils.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

TimePoint make_time_point(int year, int month, int day, int hour, int minute) {
    std::tm t = {};
    t.tm_year = year - 1900;
    t.tm_mon = month - 1;
    t.tm_mday = day;
    t.tm_hour = hour;
    t.tm_min = minute;
    t.tm_sec = 0;
    t.tm_isdst = -1;

    std::time_t time = std::mktime(&t);
    return std::chrono::system_clock::from_time_t(time);
}

void printTimePoint(const TimePoint& tp) {
    std::time_t time = std::chrono::system_clock::to_time_t(tp);
    std::tm* tm = std::localtime(&time);
    std::cout << std::put_time(tm, "%Y-%m-%d %H:%M:%S") << std::endl;
}
