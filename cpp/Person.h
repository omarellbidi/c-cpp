#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
private:
    std::string firstName;
    std::string lastName;
    char gender;
    int birthYear;
    int deathYear;

public:
    Person(const std::string &fName, const std::string &lName, char g, int bYear, int dYear);

    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
    char getGender() const { return gender; }
    int getBirthYear() const { return birthYear; }
    int getDeathYear() const { return deathYear; }
};

#endif
