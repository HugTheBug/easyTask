#ifndef DUOLABSTEST_SERVICE_H
#define DUOLABSTEST_SERVICE_H

#include "Time.h"
#include <string>
#include <ostream>

using std::string;

/**
 * Represents bus service. Contains company name, departure and arrival times.
 */
class Service {
    string company;
    Time departure;
    Time arrival;

public:

    Service() {}

    Service(const string &company, const Time &departure, const Time &arrival)
            : company{company}, departure{departure}, arrival{arrival} {}

    const string &getCompany() const;

    void setCompany(const string &company);

    const Time &getDeparture() const;

    void setDeparture(const Time &departure);

    const Time &getArrival() const;

    void setArrival(const Time &arrival);

    /**
     * @return duration of service in minutes
     */
    unsigned int minutesLength() const;

    /**
     * @return whether service is longer than 1 hour
     */
    bool isLong() const;

    bool operator==(const Service &rhs) const;

    bool operator!=(const Service &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Service &service);
};

#endif //DUOLABSTEST_SERVICE_H
