#include <iostream>
#include "PersonList.h"
#include "StandList.h"
#include "Polygamy.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " personen.dat stand.dat\n";
        return EXIT_FAILURE;
    }

    // Load persons and marriages 
    PersonList persons;
    StandList stands;
    persons.loadFromFile(argv[1]);  
    stands.loadFromFile(argv[2]);  


    // Detect and write polygamous 
    detectPolygamy(stands, persons, "./polygam.dat");

    std::cout << "Polygamous persons have been written to polygam.dat\n";
    return EXIT_SUCCESS;
}
