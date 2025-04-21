#include "Person.h"

Person::Person(const std::string &fName, const std::string &lName, char g, int bYear, int dYear)
    : firstName(fName), lastName(lName), gender(g), birthYear(bYear), deathYear(dYear) {}
