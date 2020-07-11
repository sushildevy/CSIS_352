// File:    hourlyEmployee.cpp
// Author:  Sushil Pandey
// Program: prog6
// Date:    04/25/2019

// Description: 
// This file contains the implementation for a hourlyEmployee class

#include <iostream>
#include <iomanip>
#include "person.h"
#include "date.h"
#include "employee.h"
#include "hourlyEmployee.h"
using namespace std;
using namespace DateNameSpace;

HourlyEmployee::HourlyEmployee(string& name, Date& obj, string ssn,int id, int h, double wR):Employee(name,obj,ssn,id),hour(h),wageRate(wR)
{

    Salary = getSalary();
}

 
int HourlyEmployee::getHour() const
{
    return hour;
}

double HourlyEmployee::getWageRate()const
{
    return wageRate;
}

double HourlyEmployee::getSalary() const
          {
              double x;
            if ( hour <= 40 )


              {x = hour *  wageRate;}

                else

               { x = 40.0 * wageRate + ( hour - 40 ) * wageRate * 1.5;}
                return x;
          }

void HourlyEmployee::Display(ofstream& x)
{
  
    x<<setw(15)<<getSalary()<<setw(10)<<getHour()<<setw(15)<<getWageRate();
     

}
