 # File:     makefile
# Author:   Sushil pandey
# program: Assignment7
# Date:    05/07/2019

# Description
# This makefile will make the example $(EXE) program of a Hashtable class

CC=g++
OBJECTS=main.o symbol.o hashfunctions.o
EXE=prog7
CFLAGS=-fno-diagnostics-color
LFLAGS=

$(EXE):		$(OBJECTS)
		$(CC) -o $(EXE) $(OBJECTS) $(LFLAGS)

main.o:		main.cpp hashtable.h constants.h  
		$(CC) $(CFLAGS) -c main.cpp
symbol.o:	symbol.cpp symbol.h 
		$(CC) $(CFLAGS) -c symbol.cpp
hashfunctions.o:	hashfunctions.cpp  symbol.h
		$(CC) $(CFLAGS) -c hashfunctions.cpp 
clean:
		rm -rf prog7 *~$(OBJECTS) 
