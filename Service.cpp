#include "Service.h"

unsigned int Service::minutesLength() const {
    return arrival.minutes() - departure.minutes();
}

bool Service::isLong() const {
    return minutesLength() > 60;
}

bool Service::operator==(const Service &rhs) const {
    return company == rhs.company &&
           departure == rhs.departure &&
           arrival == rhs.arrival;
}

bool Service::operator!=(const Service &rhs) const {
    return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &os, const Service &service) {
    os << service.company << " " << service.departure << " " << service.arrival;
    return os;
}

const string &Service::getCompany() const {
    return company;
}

void Service::setCompany(const string &company) {
    Service::company = company;
}

const Time &Service::getDeparture() const {
    return departure;
}

void Service::setDeparture(const Time &departure) {
    Service::departure = departure;
}

const Time &Service::getArrival() const {
    return arrival;
}

void Service::setArrival(const Time &arrival) {
    Service::arrival = arrival;
}
