#make all compile each src/*cpp file and create an individual executable in bin/

#make staircase   will compile staircase.cpp and create bin/staircase 

# file Makefile
CC= g++
RM= rm -vf
SRC= ./src/
CFLAGS= -Wall -g
CPPFLAGS= -I.
SRCFILES= $(wildcard ./src/*.cpp)
OBJFILES= $(patsubst ./src/%.cpp, %.o, $(SRCFILES))
PROGFILES= $(patsubst ./src/%.cpp, %, $(SRCFILES))
BIN=./bin/
.PHONY: all clean

all: $(PROGFILES)

$(PROGFILES): $(OBJ)
	$(CC) -o $(BIN)$@ $^ $(CFLAGS) $(SRC)$@.cpp

clean:
	$(RM) $(BIN)* $(SRC)*~
## eof Makefile