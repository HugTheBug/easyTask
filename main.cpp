#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include "Service.h"

using namespace std;

vector<Service> readServices(const string &filename);

void writeServices(const string &filename, const vector<Service> &posh, const vector<Service> &grotty);

bool cmpEfficiency(const Service &a, const Service &b);

int main() {
    vector<Service> services = readServices("input.txt");
    vector<Service> posh, grotty;

    sort(services.begin(), services.end(), cmpEfficiency);

    Time lastArrival, lastDeparture;
    for (const Service &obj : services) {
        if (obj.getArrival() > lastArrival && obj.getDeparture() > lastDeparture && !obj.isLong()) {
            lastArrival = obj.getArrival();
            lastDeparture = obj.getDeparture();
            if (obj.getCompany() == "Posh") {
                posh.push_back(obj);
            } else {
                grotty.push_back(obj);
            }
        }
    }
    writeServices("output.txt", posh, grotty);

    return 0;
}

/**
 * Compares services according to their efficiency and arrival time.
 */
bool cmpEfficiency(const Service &a, const Service &b) {
    if (a.getArrival() < b.getArrival()) {
        return true;
    } else if (a.getArrival() == b.getArrival()) {
        if (a.getDeparture() > b.getDeparture()) {
            return true;
        } else if (a.getDeparture() == b.getDeparture()) {
            return a.getCompany() == "Posh";
        } else {
            return false;
        }
    } else {
        return false;
    }
}

/**
 * Reads services from file.
 * @param filename path to file
 * @return services from file
 */
vector<Service> readServices(const string &filename) {
    ifstream in(filename);
    vector<Service> services;
    string token;
    Service temp;
    in >> token;
    while (in) {
        temp.setCompany(token);
        in >> token;
        unsigned int delim = token.find(":");
        unsigned int hour = stoi(token.substr(0, delim));
        unsigned int minute = stoi(token.substr(delim + 1));
        temp.setDeparture(Time(1, hour, minute));
        in >> token;
        delim = token.find(":");
        hour = stoi(token.substr(0, delim));
        minute = stoi(token.substr(delim + 1));
        unsigned int day = 1;
        if (temp.getDeparture() > Time(1, hour, minute)) {
            day = 2;
        }
        temp.setArrival(Time(day, hour, minute));
        in >> token;
        services.push_back(temp);
    }
    return services;
}

/**
 * Writes only hour and minute of Time object
 * @param out stream to write
 * @param obj object to be written
 */
void writeHourMinute(ostream &out, const Time &obj) {
    out << setw(2) << setfill('0') << obj.getHour() << ":" << setw(2) << setfill('0') << obj.getMinute();
}

/**
 * Writes services to file
 * @param filename path to file
 * @param posh posh's services
 * @param grotty grotty's services
 */
void writeServices(const string &filename, const vector<Service> &posh, const vector<Service> &grotty) {
    ofstream out(filename);
    for (const Service &obj : posh) {
        out << obj.getCompany() << " ";
        writeHourMinute(out, obj.getDeparture());
        out << " ";
        writeHourMinute(out, obj.getArrival());
        out << endl;
    }
    out << endl;
    for (const Service &obj : grotty) {
        out << obj.getCompany() << " ";
        writeHourMinute(out, obj.getDeparture());
        out << " ";
        writeHourMinute(out, obj.getArrival());
        out << endl;
    }
    out.close();
}