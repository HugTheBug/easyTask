#include "Time.h"
#include <iomanip>

using std::setw;
using std::setfill;

Time::Time(string str) {
    int delim = str.find(":");
    hour = stoi(str.substr(0, delim));
    minute = stoi(str.substr(delim + 1));
}

unsigned int Time::minutes() const {
    return hour * 60 + minute;
}

bool Time::operator==(const Time &obj) const {
    return hour == obj.hour && minute == obj.minute;
}

bool Time::operator!=(const Time &obj) const {
    return !(*this == obj);
}

bool Time::operator<(const Time &rhs) const {
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

std::ostream &operator<<(std::ostream &os, const Time &time1) {
    os << setw(2) << setfill('0') << time1.hour << ":" << setw(2) << setfill('0') << time1.minute;
    return os;
}
