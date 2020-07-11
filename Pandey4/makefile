# File:     makefile
# Author:   Sushil pandey
# Program: Assignment4
# Date:    3/28/2019

# Description
# This makefile will make the example program of a sorted list


CC=g++
OBJECTS=main.o 
EXE=prog4
CFLAGS=-Wall
LFLAGS=

$(EXE):		$(OBJECTS)
		$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS) $(LFLAGS)

main.o:		main.cpp sortedList.h 
		$(CC) $(CFLAGS) -c main.cpp

clean:		
		rm -rf prog4 *~ $(OBJECTS)
