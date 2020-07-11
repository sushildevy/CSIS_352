# File:     makefile
# Author:   Sushil pandey
# Program: Assignment2
# Date:    2/21/2019

# Description
# This makefile will make the example program of a date class

CC=g++
OBJECTS=main.o date.o
EXE=prog2
CFLAGS=-Wall
LFLAGS=

$(EXE):		$(OBJECTS)
		$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS) $(LFLAGS)
main.o: 	main.cpp date.h
		$(CC) $(CFLAGS) -c main.cpp
date.o:		date.cpp date.h 
		$(CC) $(CFLAGS) -c date.cpp	
clean:
		rm -rf prog *~ $(OBJECTS) $(EXE)
