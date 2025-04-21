# Polygamy Detector - C and C++ Implementation

## Project Overview
This project includes two parallel implementations (C and C++) of a program that identifies individuals who were polygamous, meaning they were simultaneously married to multiple people. Both implementations read from the same data files:
- `personen.dat`: Contains personal information about individuals
- `stand.dat`: Contains records of marriages and divorces

Based on this data, the program identifies people who were married to more than one person at the same time, excluding cases where a person remarried after divorce or the death of their previous spouse.


## How It Works
1. The program loads personal data from `personen.dat`
2. It then loads marriage and divorce records from `stand.dat`
3. For each marriage record, it checks if a person was married to someone else while still being married to another person
4. It verifies that no divorce record exists between the marriages and that the first spouse was still alive
5. Results are written to `polygam.dat` with details of the polygamous individuals and their marriages


## How to Run

```
make
./programm personen.dat stand.dat
```

The output file `polygam.dat` will be created with information about any polygamous individuals found in the data.

## Example Output
```
Polygamous Person: Heribert Madlinger (1931)
Marriages:
1. Mara Jurcic (1934) in 1954
2. Monika Ablasser (1941) in 1963
---------------------------------
```
