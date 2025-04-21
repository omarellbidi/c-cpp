#include "Polygamy.h"
#include <fstream>
#include <stdexcept>
#include <iostream>


// Detects polygamous persons and writes them to a file
void detectPolygamy(const StandList &stands, const PersonList &persons, const std::string &outputFile) {
    std::ofstream out(outputFile);
    if (!out.is_open()) {
        throw std::runtime_error("Error opening output file: " + outputFile);
    }

    // Iterate through all recorded marriages
    for (const auto &marriageList : stands.getMarriageRecords()) {
        const std::vector<Stand> &marriages = marriageList.second;
        if (marriages.size() < 2) continue;  // Not polygamous

        for (size_t i = 0; i < marriages.size(); ++i) {
            for (size_t j = i + 1; j < marriages.size(); ++j) {
                const Stand &m1 = marriages[i];
                const Stand &m2 = marriages[j];

                if (m1.year >= m2.year) continue;  // Ensure chronological order

                bool isPolygamous = true;

                // Check if a divorce occurred BEFORE the second marriage
                for (const auto &stand : stands.getDivorces()) {
                    if (stand.partner1FirstName == m1.partner1FirstName &&
                        stand.partner1LastName == m1.partner1LastName &&
                        stand.partner1BirthYear == m1.partner1BirthYear &&
                        stand.partner2FirstName == m1.partner2FirstName &&
                        stand.partner2LastName == m1.partner2LastName &&
                        stand.partner2BirthYear == m1.partner2BirthYear &&
                        stand.year < m2.year) {
                        isPolygamous = false;
                        break;
                    }
                }

                //Check if the first spouse DIED before the second marriage
                int deathYear = persons.getDeathYear(m1.partner2FirstName, m1.partner2LastName, m1.partner2BirthYear);
                if (deathYear != -1 && deathYear < m2.year) {
                    isPolygamous = false;
                }
 
                // Output polygamous persons and their marriages 
                if (isPolygamous) {
                    out << "Polygamous Person: " << m1.partner1FirstName << " " << m1.partner1LastName
                        << " (" << m1.partner1BirthYear << ")\n";
                    out << "Marriages:\n";
                    out << "1. " << m1.partner2FirstName << " " << m1.partner2LastName
                        << " (" << m1.partner2BirthYear << ") in " << m1.year << "\n";
                    out << "2. " << m2.partner2FirstName << " " << m2.partner2LastName
                        << " (" << m2.partner2BirthYear << ") in " << m2.year << "\n";
                    out << "---------------------------------\n";
                }
            }
        }
    }
}
