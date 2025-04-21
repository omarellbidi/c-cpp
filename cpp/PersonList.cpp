#include "PersonList.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>

// Generates a unique key for identifying a person using first name, last name, and birth year.
std::string PersonList::generateKey(const std::string &firstName, const std::string &lastName, int birthYear) {
    return firstName + "_" + lastName + "_" + std::to_string(birthYear);
}

// Loads persons from a file and stores them in the unordered_map.
void PersonList::loadFromFile(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Error opening " + filename);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string firstName, lastName;
        char gender;
        int birthYear, deathYear;

        if (!(iss >> firstName >> lastName >> gender >> birthYear >> deathYear)) {
            throw std::runtime_error("Error parsing line in " + filename);
        }

        std::string key = generateKey(firstName, lastName, birthYear);
        persons.try_emplace(key, firstName, lastName, gender, birthYear, deathYear);
    }
}
// Checks if a person exists in the dataset by looking up their unique key.
bool PersonList::personExists(const std::string &firstName, const std::string &lastName, int birthYear) const {
    return persons.find(generateKey(firstName, lastName, birthYear)) !=
     persons.end();
}

// Retrieves the death year of a person, or returns -1 if the person is not found.
int PersonList::getDeathYear(const std::string &firstName, const std::string &lastName, int birthYear) const {
    auto it = persons.find(generateKey(firstName, lastName, birthYear));
    return (it != persons.end() && it->second.getDeathYear() > 0) ? it->second.getDeathYear() : -1;
}
