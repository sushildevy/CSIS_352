// File:    person.cpp
// Author:  Sushil Pandey
// Program: prog6 
// Date:    04/25/2019

// Description: 
// This file contains the implementation for a person class


#include <iostream>
#include "person.h"
#include "date.h"
#include <iomanip>
#include <string>
using namespace std;
using namespace DateNameSpace;
Person::Person(const string& name,Date& obj,string ssn ):personName(name),bthDay(obj), SSN(ssn)
{
    
}

string Person::getName() const
{
    return personName;
    
}

Date Person::getBirthDay() const
{
    return bthDay;
}

string Person::getSSN() const
{
    return SSN;
}




