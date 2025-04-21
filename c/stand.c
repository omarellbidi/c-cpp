/* stand.c
 * Manages marriage and divorce records.
 * Loads relationship status data from file.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stand.h"
#include "person.h"

// Load marriage and divorce records from file
void loadStands(const char *filename, Stand **stands, int *count, const Person *persons, int personCount) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening stand.dat");
        exit(EXIT_FAILURE);
    }
    
    *count = 0;
    *stands = NULL;
    char line[256];
    
    // Process each record in the file
    while (fgets(line, sizeof(line), file)) {
        // Allocate memory for new record
        *stands = realloc(*stands, (*count + 1) * sizeof(Stand));
        if (!(*stands)) {
            perror("Error reallocating memory");
            fclose(file);
            exit(EXIT_FAILURE);
        }
        
        Stand stand;
        // Parse relationship data
        sscanf(line, "%c %d %49s %49s %d %49s %49s %d",
               &stand.type,
               &stand.year,
               stand.partner1FirstName,
               stand.partner1LastName,
               &stand.partner1BirthYear,
               stand.partner2FirstName,
               stand.partner2LastName,
               &stand.partner2BirthYear);
        
        // Verify both partners exist in the person records
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
