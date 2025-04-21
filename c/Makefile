CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRC = main.c person.c stand.c polygamy.c
OBJ = $(SRC:.c=.o)
OUTPUT = programm

all: $(OUTPUT)

$(OUTPUT): $(OBJ)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OUTPUT)

