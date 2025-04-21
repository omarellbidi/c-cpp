CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

SOURCES = main.cpp Person.cpp PersonList.cpp Stand.cpp StandList.cpp Polygamy.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = programm

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Explizite Abhängigkeitsverfolgung

main.o: main.cpp PersonList.h StandList.h Polygamy.h
Person.o: Person.cpp Person.h
PersonList.o: PersonList.cpp PersonList.h Person.h
Stand.o: Stand.cpp Stand.h
StandList.o: StandList.cpp StandList.h Stand.h PersonList.h
Polygamy.o: Polygamy.cpp Polygamy.h StandList.h PersonList.h

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(TARGET) $(OBJECTS)
