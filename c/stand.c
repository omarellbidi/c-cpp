#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stand.h"
#include "person.h"

void loadStands(const char *filename, Stand **stands, int *count, const Person *persons, int personCount) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening stand.dat");
        exit(EXIT_FAILURE);
    }

    *count = 0;
    *stands = NULL;

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        *stands = realloc(*stands, (*count + 1) * sizeof(Stand));
        if (!(*stands)) {
            perror("Error reallocating memory");
            fclose(file);
            exit(EXIT_FAILURE);
        }

        Stand stand;
        // Use %49s to prevent buffer overflow
        sscanf(line, "%c %d %49s %49s %d %49s %49s %d",
               &stand.type,
               &stand.year,
               stand.partner1FirstName,
               stand.partner1LastName,
               &stand.partner1BirthYear,
               stand.partner2FirstName,
               stand.partner2LastName,
               &stand.partner2BirthYear);

        // Verify that both partners exist in personen.dat
        if (!personExists(stand.partner1FirstName, stand.partner1LastName, stand.partner1BirthYear, persons, personCount) ||
            !personExists(stand.partner2FirstName, stand.partner2LastName, stand.partner2BirthYear, persons, personCount)) {
            fprintf(stderr, "Error: Person in stand.dat not found in personen.dat\n");
            continue;
        }

        (*stands)[*count] = stand;
        (*count)++;
    }
    fclose(file);
}
