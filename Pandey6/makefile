# File:     makefile
# Author:   Sushil pandey
# $(EXE)ram: Assignment6 
# Date:    04/11/2019

# Description
# This makefile will make the example $(EXE)ram of a Person and Employee classes

CC=g++
OBJECTS=main.o person.o employee.o date.o employees.o salaryEmployee.o hourlyEmployee.o
EXE=prog6
CFLAGS=-fno-diagnostics-color
LFLAGS=

$(EXE):		$(OBJECTS)
		$(CC) -o $(EXE) $(OBJECTS) $(LFLAGS)

main.o:		main.cpp person.o employee.o salaryEmployee.o hourlyEmployee.o employees.o date.o
		$(CC) $(CFLAGS) -c main.cpp
date.o:	date.cpp date.h
		$(CC) $(CFLAGS) -c date.cpp
person.o:	person.cpp person.h 
		$(CC) $(CFLAGS) -c person.cpp

employee.o:	employee.cpp employee.h person.h 
		$(CC) $(CFLAGS) -c employee.cpp
salaryEmployee.o:	salaryEmployee.cpp salaryEmployee.h employee.h 
		$(CC) $(CFLAGS) -c salaryEmployee.cpp

hourlyEmployee.o:	hourlyEmployee.cpp hourlyEmployee.h employee.h 
		$(CC) $(CFLAGS) -c hourlyEmployee.cpp
employees.o:	employees.cpp employees.h 
		$(CC) $(CFLAGS) -c employees.cpp
clean:
		rm -rf prog6 *~$(OBJECTS) 
