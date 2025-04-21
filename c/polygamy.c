
/* polygamy.c
 * Core logic for detecting polygamous relationships.
 * Analyzes marriage and divorce records to find polygamous individuals.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "polygamy.h"

// Detect polygamous individuals and write results to output file
void detectPolygamy(const Stand *stands, int standCount, const Person *persons, int personCount, const char *outputFile) {
    FILE *out = fopen(outputFile, "w");
    if (!out) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }
    
    // Compare each marriage record with all other marriage records
    for (int i = 0; i < standCount; i++) {
        if (stands[i].type != 'H') continue;  // Skip non-marriage records
        
        for (int j = i + 1; j < standCount; j++) {
            if (stands[j].type != 'H') continue;  // Skip non-marriage records
            
            // Check if same person (partner1) appears in both marriages
            if (strcmp(stands[i].partner1FirstName, stands[j].partner1FirstName) == 0 &&
                strcmp(stands[i].partner1LastName, stands[j].partner1LastName) == 0 &&
                stands[i].partner1BirthYear == stands[j].partner1BirthYear) {
                
                int isPolygamous = 1;
                
                // Check if there was a divorce between the marriages
                for (int k = 0; k < standCount; k++) {
                    if (stands[k].type == 'S' &&
                        strcmp(stands[k].partner1FirstName, stands[i].partner1FirstName) == 0 &&
                        strcmp(stands[k].partner1LastName, stands[i].partner1LastName) == 0 &&
                        stands[k].partner1BirthYear == stands[i].partner1BirthYear &&
                        strcmp(stands[k].partner2FirstName, stands[i].partner2FirstName) == 0 &&
                        strcmp(stands[k].partner2LastName, stands[i].partner2LastName) == 0 &&
                        stands[k].partner2BirthYear == stands[i].partner2BirthYear &&
                        stands[k].year < stands[j].year) {
                        isPolygamous = 0;
                        break;
                    }
                }
                
                // Check if first spouse died before second marriage
                if (isPolygamous) {
                    for (int p = 0; p < personCount; p++) {
                        if (strcmp(persons[p].firstName, stands[i].partner2FirstName) == 0 &&
                            strcmp(persons[p].lastName, stands[i].partner2LastName) == 0 &&
                            persons[p].birthYear == stands[i].partner2BirthYear &&
                            persons[p].deathYear < stands[j].year) {
                            isPolygamous = 0;
                            break;
                        }
                    }
                }
                
                // If polygamous, write to output file
                if (isPolygamous) {
                    fprintf(out, "Polygamous Person: %s %s (%d)\n",
                            stands[i].partner1FirstName, stands[i].partner1LastName, stands[i].partner1BirthYear);
                    fprintf(out, "Marriages:\n");
                    fprintf(out, "1. %s %s (%d) in %d\n",
                            stands[i].partner2FirstName, stands[i].partner2LastName, stands[i].partner2BirthYear, stands[i].year);
                    fprintf(out, "2. %s %s (%d) in %d\n",
                            stands[j].partner2FirstName, stands[j].partner2LastName, stands[j].partner2BirthYear, stands[j].year);
                    fprintf(out, "---------------------------------\n");
                }
            }
        }
    }
    fclose(out);
}
