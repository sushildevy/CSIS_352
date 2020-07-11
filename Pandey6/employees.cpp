// File:    employee.cpp
// Author:  Sushil Pandey
// Program: prog6
// Date:    04/25/2019

// Description: 
// This file contains the implementation for a employee class

#include <iostream>
#include "person.h"
#include "date.h"
#include "employees.h"
//#include <string>
using namespace std;
using namespace DateNameSpace;

void Employees::addToList( Employee* emp)
{
    empList.push_back(emp);
    
}
int Employees::length() const
{
    return empList.size();
}

Employee* Employees::valueAt(int num)
{
    list<Employee*>::iterator empPtr;
    empPtr = empList.begin();
    for(int i=0 ;i<num;i++)
        {
            empPtr++;
        }
    return *empPtr;
}

