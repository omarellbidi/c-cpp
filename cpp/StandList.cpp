#include "StandList.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>

// Generates a unique key for identifying a person using first name, last name, and birth year.
std::string StandList::generateKey(const std::string &firstName, const std::string &lastName, int birthYear) {
    return firstName + "_" + lastName + "_" + std::to_string(birthYear);
}

// Loads marriage and divorce records from a file and stores them in the list
void StandList::loadFromFile(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Error opening " + filename);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        char type;
        int year, p1BirthYear, p2BirthYear;
        std::string p1FirstName, p1LastName, p2FirstName, p2LastName;

        if (!(iss >> type >> year >> p1FirstName >> p1LastName >> p1BirthYear >> p2FirstName >> p2LastName >> p2BirthYear)) {
            throw std::runtime_error("Error parsing line in " + filename);
        }

        // Create a Stand object and store it in the list
        Stand stand(type, year, p1FirstName, p1LastName, p1BirthYear, p2FirstName, p2LastName, p2BirthYear);
        stands.push_back(stand);

        // Store marriages in the hash map
        if (type == 'H') { // Marriage
            marriageRecords[generateKey(p1FirstName, p1LastName, p1BirthYear)].push_back(stand);
        }
    }
}

// Returns a reference to the map of marriage records
const std::unordered_map<std::string, std::vector<Stand>>& StandList::getMarriageRecords() const {
    return marriageRecords;
}

// Returns a list of all recorded divorces
std::vector<Stand> StandList::getDivorces() const {
    std::vector<Stand> divorces;
    for (const auto &stand : stands) {
        if (stand.type == 'S') {  // Divorce record
            divorces.push_back(stand);
        }
    }
    return divorces;
}
