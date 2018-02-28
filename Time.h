#ifndef DUOLABSTEST_TIME_H
#define DUOLABSTEST_TIME_H

#include <string>
#include <ostream>

using std::string;

/**
 * Represents time. Contains hours and minutes.
 */
class Time {
    unsigned int hour;
    unsigned int minute;
public:
    Time() : hour{0}, minute{0} {}

    /**
     * Constructs object from "hh:mm" string
     * @param str "hh:mm" string
     */
    explicit Time(string str);

    Time(unsigned int hour, unsigned int minute)
            : hour{hour}, minute{minute} {}

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

    /**
     * Computes time passed since 00:00 in minutes
     * @return time since 00:00 in minutes
     */
    unsigned int minutes() const;

    bool operator==(const Time &obj) const;

    bool operator!=(const Time &obj) const;

    bool operator<(const Time &rhs) const;

    bool operator>(const Time &rhs) const;

    bool operator<=(const Time &rhs) const;

    bool operator>=(const Time &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Time &time1);
};

#endif //DUOLABSTEST_TIME_H
