/* main.c
 * Main entry point for the polygamy detection program.
 * Handles command-line arguments, coordinates loading data from files,
 * and calls the polygamy detection logic.
 */

#include <stdio.h>
#include <stdlib.h>
#include "person.h"
#include "stand.h"
#include "polygamy.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s personen.dat stand.dat\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *personenFile = argv[1];
    const char *standFile = argv[2];
    const char *outputFile = "./polygam.dat";

    Person *persons = NULL;
    Stand *stands = NULL;
    int personCount = 0, standCount = 0;

    
    FILE *test = fopen(outputFile, "w");
    if (!test) {
        perror("Manual test: Error opening output file");
        return EXIT_FAILURE;
    }
    fclose(test);

    // Load data
    loadPersons(personenFile, &persons, &personCount);
    loadStands(standFile, &stands, &standCount, persons, personCount);

    // Detect polygamy
    detectPolygamy(stands, standCount, persons, personCount, outputFile);

    // Clean up
    free(persons);
    free(stands);

    printf("Polygamous persons have been written to %s\n", outputFile);
    return EXIT_SUCCESS;
}
