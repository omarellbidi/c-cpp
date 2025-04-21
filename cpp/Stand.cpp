#include "Stand.h"

Stand::Stand(char t, int y, const std::string &p1f, const std::string &p1l, int p1b,
             const std::string &p2f, const std::string &p2l, int p2b)
    : type(t), year(y), partner1FirstName(p1f), partner1LastName(p1l), partner1BirthYear(p1b),
      partner2FirstName(p2f), partner2LastName(p2l), partner2BirthYear(p2b) {}
