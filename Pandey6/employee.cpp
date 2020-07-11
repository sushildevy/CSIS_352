// File:    employee.cpp
// Author:  Sushil Pandey
// Program: prog6
// Date:    04/25/2019

// Description: 
// This file contains the implementation for a employee class

#include <iostream>
#include "person.h"
#include "date.h"
#include "employee.h"
//#include <string>
using namespace std;
using namespace DateNameSpace;


// method - parametarized constructor 
// description - construct the Employee object
// preconditions - none
// postconditions - Employee object has been initialized
// method input -none
// method output -none
Employee::Employee(const string& name, Date& obj, string ssn, int id) :Person (name, obj,ssn) , ID(id)
{
   
}

// method - getID() 
// description - returns the employee id
// preconditions - Employee object has been initilized 
// postconditions - id has been returned
// method input -none
// method output -none
int Employee::getID() const
{
    return ID;   //attribute to store id 
}



