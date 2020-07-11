// File:    fraction.h
// Author:  Sushil Pandey
// Program: Assignment2
// Date:    21/02/2019

//Description: This file contains specification of the Date class

#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>

using namespace std ;
 namespace DateNameSpace{

enum outOrderFormat{MiddleEndian,LittleEndian,BigEndian};
enum outDelimeterFormat{Dash,Space,Slash};
enum outMonthFormat{Text,Numeric};
enum outDayFormat{Weekday,NoWeekday};
enum Arithmetic_F{Years,Days};

class Date
{
    public:
            
        // method - default constructor
        // description - construct a default  Date
        // preconditions - none
        // postconditions - default  Date object has been created
        // method input -none
        // method output -none
        Date();
        // method - parameterized constructor  Date
        // description - construct a  Date
        // preconditions - date is correct
        // postconditions -  Date object is created
        // method input -date of  Date:int
        // method output -none
        Date(int month, int day, int year);
        
        // method - setToday()
        // description - sets the current date 
        // preconditions - date is correct
        // postconditions - object date set
        // method input -
        // method output -
        void setToday();
        
         // method - setDate()
        // description - sets the date 
        // preconditions - date is correct
        // postconditions -  Date object is set
        // method input -
        // method output -none
        void setDate(int month, int day, int year);
        
        // method - getMonth()
        // description - returns the month of the object  Date
        // preconditions - Date object has been initilized 
        // postconditions -  Date object month has been returned
        // method input -none
        // method output -month of the date:int        
        int getMonth() const;
        
        // method - getDay()
        // description - returns the day of the object  Date
        // preconditions -Date object has been initilized 
        // postconditions -  Date object day has been returned
        // method input -date of  Date:int
        // method output -none
        int getDay() const;
        
        // method - getYear 
        // description - returns the year of the object  Date
        // preconditions - Date object has been initilized 
        // postconditions -  Date object year has been returned 
        // method input -none
        // method output -year of the date has been returned
        int getYear() const;
        
        // method - daysUntil() 
        // description - calculates the days difference
        // preconditions - Date object has been initilized 
        // postconditions - difference of days is returned
        // method input -none
        // method output -difference of the dates has been returned
        int daysUntil();
        
        // method - until() 
        // description - calculates the days difference
        // preconditions - Date object has been initilized 
        // postconditions - difference of days is returned
        // method input -none
        // method output -difference of the dates has been returned
        int until();
        
        // method - Today() 
        // description - current date is constructed
        // preconditions - Date object has been initilized
        // postconditions - 
        // method input -none
        // method output -date of the date has been returned
        static Date Today();
        //int countLeapYears(int&, int&) const;
        static void outputFormat(outOrderFormat);
        static void outputFormat(outDelimeterFormat);
        static void outputFormat(outMonthFormat);
        static void outputFormat(outDayFormat);
        static void Arithmetic(Arithmetic_F);
        string getDelimeter() const;
        string getMonthName() const;
        string getWeekDay() const;
        string getDayOfWeek() const;
        
        // method - operator overload
        // description - returns boolean value 
        // preconditions - Date object has been initilized
        // postconditions - date of object Date has been returned
        // method input -none
        // method output -boolean value was returned
        bool operator==(const Date&) const;
        
        // method - operator overload
        // description - returns boolean value 
        // preconditions - Date object has been initilized
        // postconditions - date of object Date has been returned
        // method input -none
        // method output -boolean value was returned
        bool operator!=(const Date&) const;
        
        // method - operator overload
        // description - returns boolean value 
        // preconditions - Date object has been initilized
        // postconditions - date of object Date has been returned
        // method input -none
        // method output -boolean value was returned
        bool operator<(const Date&) const;
        
                
        // method - operator overload
        // description - returns boolean value 
        // preconditions - Date object has been initilized
        // postconditions - date of object Date has been returned
        // method input -none
        // method output -boolean value was returned
        bool operator<=(const Date&) const;
        
        
                
        // method - operator overload
        // description - returns boolean value 
        // preconditions - Date object has been initilized
        // postconditions - date of object Date has been returned
        // method input -none
        // method output -boolean value was returned
        bool operator>(const Date&) const;
        
                
        // method - operator overload
        // description - returns boolean value 
        // preconditions - Date object has been initilized
        // postconditions - date of object Date has been returned
        // method input -none
        // method output -boolean value was returned
        bool operator>=(const Date&) const;
        
                
        // method - operator overload
        // description - preIncrement
        // preconditions - Date object has been initilized
        // postconditions - 
        // method input -none
        // method output -returns incremented date
        const Date& operator++();
        
                
        // method - operator overload
        // description -preDecrement 
        // preconditions - Date object has been initilized
        // postconditions - date of object Date has been returned
        // method input -none
        // method output -returns date object
        const Date& operator--();
        
        // method - operator overload
        // description -postIncrement 
        // preconditions - Date object has been initilized
        // postconditions - date of object Date has been returned
        // method input -none
        // method output -returns date object
        Date operator++(int);
        
        // method - operator overload
        // description -preDecrement 
        // preconditions - Date object has been initilized
        // postconditions - date of object Date has been returned
        // method input -none
        // method output -returns date object
        Date operator--(int);
        
        int  operator-(const Date&) ;
        Date operator-(int);
        Date operator+(int);
        const Date& operator+=(int);
        const Date& operator-=(int);
        
    friend ostream& operator <<(ostream&, const Date&);
    private:
        int month;
        int day;
        int year;
        static outOrderFormat orderF;
        static outDelimeterFormat delimeterF;
        static outMonthFormat monthF;
        static outDayFormat dayF;
        static Arithmetic_F aF;
        
};

class DateException
{
   public:
      DateException(const string& m)
      { msg = m; }

      string what()
      { return msg; }

   private:
      string msg;
};

istream& operator>>(istream&,Date&);
 }
#endif
