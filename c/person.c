/* person.c
 * Manages person data structures and related functions.
 * Handles loading person data from file and checking if a person exists.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"

// Load person data from the specified file
void loadPersons(const char *filename, Person **persons, int *count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening personen.dat");
        exit(EXIT_FAILURE);
    }
    
    *count = 0;
    *persons = NULL;
    char line[256];
    
    // Read each line and parse person data
    while (fgets(line, sizeof(line), file)) {
        // Allocate memory for the new person
        *persons = realloc(*persons, (*count + 1) * sizeof(Person));
        if (!(*persons)) {
            perror("Error reallocating memory");
            fclose(file);
            exit(EXIT_FAILURE);
        }
        
        // Parse line into person struct fields
        // Use %49s to prevent buffer overflow 
        sscanf(line, "%49s %49s %c %d %d",
               (*persons)[*count].firstName,
               (*persons)[*count].lastName,
               &(*persons)[*count].gender,
               &(*persons)[*count].birthYear,
               &(*persons)[*count].deathYear);
        (*count)++;
    }
    fclose(file);
}

// Check if a person exists in the persons array
int personExists(const char *firstName, const char *lastName, int birthYear, const Person *persons, int personCount) {
    for (int i = 0; i < personCount; i++) {
        if (strcmp(firstName, persons[i].firstName) == 0 &&
            strcmp(lastName, persons[i].lastName) == 0 &&
            birthYear == persons[i].birthYear) {
            return 1;
        }
    }
    return 0;
}
