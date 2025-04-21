#ifndef STAND_H
#define STAND_H

#include <string>

struct Stand {
    char type;
    int year;
    std::string partner1FirstName;
    std::string partner1LastName;
    int partner1BirthYear;
    std::string partner2FirstName;
    std::string partner2LastName;
    int partner2BirthYear;

    Stand(char t, int y, const std::string &p1f, const std::string &p1l, int p1b,
          const std::string &p2f, const std::string &p2l, int p2b);
};

#endif
