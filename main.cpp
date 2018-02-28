#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
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
        temp.setDeparture(Time(token));
        in >> token;
        temp.setArrival(Time(token));
        in >> token;
        services.push_back(temp);
    }
    return services;
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
        out << obj << endl;
    }
    out << endl;
    for (const Service &obj : grotty) {
        out << obj << endl;
    }
    out.close();
}