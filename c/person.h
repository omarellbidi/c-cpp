#ifndef PERSON_H
#define PERSON_H

typedef struct {
    char firstName[50];
    char lastName[50];
    char gender;
    int birthYear;
    int deathYear;
} Person;

void loadPersons(const char *filename, Person **persons, int *count);
int personExists(const char *firstName, const char *lastName, int birthYear, const Person *persons, int personCount);

#endif 
