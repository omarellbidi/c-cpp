#ifndef STANDLIST_H
#define STANDLIST_H

#include "Stand.h"
#include <unordered_map>
#include <vector>

// Class to store and manage marriages/divorces
class StandList {
private:
    std::vector<Stand> stands;  // Stores all marriages/divorces
    std::unordered_map<std::string, std::vector<Stand>> marriageRecords;  // Maps a person to their marriages

    // Generates a unique key for each person using name and birth year
    static std::string generateKey(const std::string &firstName, const std::string &lastName, int birthYear);

public:
    void loadFromFile(const std::string &filename);  // Reads stand data from file
    const std::unordered_map<std::string, std::vector<Stand>>& getMarriageRecords() const;  // Returns all marriages
    std::vector<Stand> getDivorces() const;  // Returns all divorces
};

#endif
