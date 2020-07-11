// File:    salaryEmployee.cpp
// Author:  Sushil Pandey
// Program: prog6
// Date:    04/25/2019

// Description: 
// This file contains the implementation for a hourlyEmployee class

#include <iostream>
#include <iomanip>
#include "person.h"
#include <fstream>
#include "date.h"
#include "employee.h"
#include "salaryEmployee.h"
using namespace std;
using namespace DateNameSpace;

SalaryEmployee::SalaryEmployee(string& name, Date& obj, string ssn, int id, double salary):Employee(name, obj, ssn,id),Salary(salary)
{

}

double SalaryEmployee::getSalary()const
{
    
    return Salary;
}

void SalaryEmployee::Display(ofstream& x)
{
    x<<setw(15)<<getSalary();
}
