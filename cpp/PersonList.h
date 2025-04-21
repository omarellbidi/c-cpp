#ifndef PERSONLIST_H
#define PERSONLIST_H
#include "Person.h"
#include <unordered_map>
#include <vector>

class PersonList {
private:
    std::unordered_map<std::string, Person> persons;
   static std::string generateKey(const std::string &firstName, const std::string &lastName, int birthYear);


public:
    void loadFromFile(const std::string &filename);
    bool personExists(const std::string &firstName, const std::string &lastName, int birthYear) const;
    int getDeathYear(const std::string &firstName, const std::string &lastName, int birthYear) const;
};

#endif
