#ifndef DUOLABSTEST_TIME_H
#define DUOLABSTEST_TIME_H

#include <string>
#include <ostream>

using std::string;

/**
 * Represents time. Contains day, hours and minutes.
 */
class Time {
    unsigned int day;
    unsigned int hour;
    unsigned int minute;
public:
    Time() : hour{0}, minute{0}, day{0} {}

    Time(unsigned int day, unsigned int hour, unsigned int minute)
            : hour{hour}, minute{minute}, day{day} {}

    unsigned int getHour() const {
        return hour;
    }

    void setHour(unsigned int hour) {
        Time::hour = hour;
    }

    unsigned int getMinute() const {
        return minute;
    }

    void setMinute(unsigned int minute) {
        Time::minute = minute;
    }

    unsigned int getDay() const {
        return day;
    }

    void setDay(unsigned int day) {
        Time::day = day;
    }

    /**
     * Computes time passed since 00:00 in minutes
     * @return time since 00:00 in minutes
     */
    unsigned int minutes() const;

    bool operator==(const Time &rhs) const;

    bool operator!=(const Time &rhs) const;

    bool operator<(const Time &rhs) const;

    bool operator>(const Time &rhs) const;

    bool operator<=(const Time &rhs) const;

    bool operator>=(const Time &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Time &time1);
};

#endif //DUOLABSTEST_TIME_H
