// File:    employees.h
// Author:  Sushil Pandey
// Program: prog6
// Date:    04/25/2019

// Description: 
// This file contains the specification for a employees class
#ifndef _EMPLOYEES_H
#define _EMPLOYEES_H

#include <iostream>
#include "date.h"
#include "person.h"
#include "employee.h"
#include <list>
using namespace DateNameSpace;

class Employees
{
    public:

        // method - addToList() 
        // description - insert employee pointer
        // preconditions - Employee object has been initilized 
        // postconditions - value pointed by  employee pointer is inserted
        // method input -none
        // method output -none
        void addToList( Employee* emp);

        //  - iterator 
        list<Employee*>::iterator listIterator;

        // method - length() 
        // description - returns the length of the employee list. 
        // preconditions - Employee object has been initilized 
        // postconditions -  size of employee list has been returned 
        // method input -none
        // method output -none
        int length() const;

        // method - valueAt() 
        // description - returns the value at the given point
        // preconditions - Employee object has been initilized 
        // postconditions -  value at points has been returned 
        // method input -none
        // method output -none
        Employee* valueAt(int num);
    private:
        list<Employee*> empList;   //composition -Has-A relationship

};

#endif
