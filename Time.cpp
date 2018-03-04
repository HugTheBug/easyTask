#include "Time.h"
#include <iomanip>
#include <iostream>

using std::setw;
using std::setfill;

unsigned int Time::minutes() const {
    return ((day - 1) * 24 + hour) * 60 + minute;
}

bool Time::operator<(const Time &rhs) const {
    if (day < rhs.day)
        return true;
    if (rhs.day < day)
        return false;
    if (hour < rhs.hour)
        return true;
    if (rhs.hour < hour)
        return false;
    return minute < rhs.minute;
}

bool Time::operator>(const Time &rhs) const {
    return rhs < *this;
}

bool Time::operator<=(const Time &rhs) const {
    return !(rhs < *this);
}

bool Time::operator>=(const Time &rhs) const {
    return !(*this < rhs);
}

bool Time::operator==(const Time &rhs) const {
    return day == rhs.day &&
           hour == rhs.hour &&
           minute == rhs.minute;
}

bool Time::operator!=(const Time &rhs) const {
    return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &os, const Time &time1) {
    os << setw(2) << setfill('0') << time1.day << " "
       << setw(2) << setfill('0') << time1.hour << ":"
       << setw(2) << setfill('0') << time1.minute;
    return os;
}
