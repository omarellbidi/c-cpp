#ifndef POLYGAMY_H
#define POLYGAMY_H

#include "stand.h"
#include "person.h"

void detectPolygamy(const Stand *stands, int standCount, const Person *persons, int personCount, const char *outputFile);

#endif 
