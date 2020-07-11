

# File:     makefile
# Author:   Sushil pandey
# Program: Assignment3
# Date:    3/14/2019

# Description
# This makefile will make the example program of a Array class


CC=g++
OBJECTS=main.o 
EXE=prog3
CFLAGS=-Wall
LFLAGS=

$(EXE):		$(OBJECTS)
		$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS) $(LFLAGS)

main.o:		main.cpp array.h 
		$(CC) $(CFLAGS) -c main.cpp

clean:		
		rm -rf prog3 *~ $(OBJECTS)
