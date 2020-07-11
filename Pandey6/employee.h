// File:    employee.h
// Author:  Sushil Pandey
// Program: prog6
// Date:    04/25/2019

// Description: 
// This file contains the specification for a Employee class

#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#include <iostream>
#include <fstream>
#include "date.h"
#include "person.h"
//using namespace std;
using namespace DateNameSpace;
class Employee: public Person
{
    public:
        // method - parametarized constructor 
        // description - creates employee object
        // preconditions - none
        // postconditions - Employee object has been created
        // method input -string name, date object, sting ssn int Id
        // method output -none
        Employee(const string& , Date& , string , int );

        // method - getID() 
        // description - returns the employee id 
        // preconditions - Employee object has been initialized
        // postconditions - id has been returned
        // method input -none
        // method output -none
        int getID() const;

        // method - pure abstract Display() method
        // description - creates abstract display method
        // preconditions - none
        // postconditions - none
        // method input -none
        // method output -none
        virtual void Display(ofstream&)=0;
    private:
        int ID; // stores employee id
        
};



#endif
