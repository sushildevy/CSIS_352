// File:    salaryEmployee.h
// Author:  Sushil Pandey
// Program: prog6
// Date:    04/25/2019

// Description: 
// This file contains the specification for a salaryEmployee class
#ifndef _SALARIEDEMPLOYEE_
#define _SALARIEDEMPLOYEE_
#include <iostream>
#include <fstream>
#include "date.h"
#include "person.h"
#include "employee.h"
using namespace DateNameSpace;

class SalaryEmployee: public Employee
{
    public:
        // method - constructor 
        // description - construct the salaryEmployee object
        // preconditions - 
        // postconditions - salaryEmployee object has been created 
        // method input -string name, date object, string ssn, int id and double salary
        // method output -none
        SalaryEmployee(string& , Date&, string, int ,double);

        // method - getSalary() 
        // description - returns the souble salary amount
        // preconditions - salary employee has been initialized
        // postconditions - salary has been returned
        // method input -none
        // method output -none
        double getSalary() const;

        // method - Display() 
        // description - method to print the required data
        // preconditions - none
        // postconditions -  none
        // method input -none
        // method output -output the data
        void Display(ofstream& x);
  //  private:
        double Salary; //attribute to store salary 
    
};

#endif
