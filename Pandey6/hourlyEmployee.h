// File:    hourlyEmployee.h
// Author:  Sushil Pandey
// Program: prog6
// Date:    04/25/2019

// Description: 
// This file contains the specification for a hourlyEmployee class
#ifndef _HOURLYEMPLOYEE_
#define _HOURLYEMPLOYEE_
#include <iostream>
#include <fstream>
#include "date.h"
#include "person.h"
#include "employee.h"
using namespace DateNameSpace;
class HourlyEmployee:public Employee
{ 
    public:
        // method - constructor 
        // description - constructs hourly employee object 
        // preconditions - none
        // postconditions -  hourly employee has been constructed
        // method input -string name, Date object, stinf ssn, int id , int hour , double wage rate
        // method output -none
        HourlyEmployee(string& , Date& , string , int , int, double );

        // method - getHour() 
        // description - returns the int hours worked
        // preconditions - hourly Eemployee object has been initilized 
        // postconditions -  hour has been returned 
        // method input -none
        // method output -none
        int getHour() const;

        // method - getWageRate() 
        // description - returns the double wage rate
        // preconditions - hourly object object has been initilized 
        // postconditions -  wageRate has been returned 
        // method input -none
        // method output -none
        double getWageRate()const;

        // method - getSalary() 
        // description - returns the double salary
        // preconditions - none
        // postconditions -  salary has been returned 
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
        double Salary; // public attribute to store salary of hourly worked employee
    private:
        int hour;  // private attribute to store hour worked 
        double wageRate; //private attribute to store the wage rate.
};

#endif
