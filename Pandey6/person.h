// File:    Person.h
// Author:  Sushil Pandey
// Program: prog6
// Date:    04/25/2019

// Description: 
// This file contains the specification for a Person class
#ifndef _PERSON_H_
#define _PERSON_H_

#include <iostream>
#include "date.h"
//using namespace std;
using namespace DateNameSpace;
class Person
{
    public:
        //method - parametarized constructor
        //description-  construct constructor with argument
        //preconditions - none
        //Postcondition: Person object created
        //method input - string name, date object and string ssn; 
        //method output -none; 
        Person(const string& name,Date&,string ssn);

        // method - getName 
        // description - returns the string name
        // preconditions - person object has been initilized 
        // postconditions -  name has been returned 
        // method input -none
        // method output -none
        string getName() const;

        // method - getBirthDay()
        // description - returns the date object 
        // preconditions -Date object has been initilized 
        // postconditions -  Date object  has been returned
        // method input -date of  Date
        // method output -none
        Date getBirthDay()const;

        // method - getSSN 
        // description - returns the string ssn
        // preconditions - person object has been initilized 
        // postconditions -  ssn has been returned 
        // method input -none
        // method output -none
        string getSSN() const;
    private:
        string personName; // attribute that store person name
        string SSN;    //stores SSN 
        Date bthDay;   // stores birth day
        
        
};




#endif
