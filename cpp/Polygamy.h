#ifndef POLYGAMY_H
#define POLYGAMY_H

#include "StandList.h"
#include "PersonList.h"
#include <string>

void detectPolygamy(const StandList &stands, const PersonList &persons, const std::string &outputFile);

#endif
