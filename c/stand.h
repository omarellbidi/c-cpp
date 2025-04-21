#ifndef STAND_H
#define STAND_H

#include "person.h"

typedef struct {
    char type; // 'H' for marriage, 'S' for divorce
    int year;
    char partner1FirstName[50];
    char partner1LastName[50];
    int partner1BirthYear;
    char partner2FirstName[50];
    char partner2LastName[50];
    int partner2BirthYear;
} Stand;

void loadStands(const char *filename, Stand **stands, int *count, const Person *persons, int personCount);

#endif 
