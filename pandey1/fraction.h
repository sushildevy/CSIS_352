// File:    fraction.h
// Author:  Sushil Pandey
// Program: Assignment1
// Date:    1/31/2019

//Description: This file contains specification of the fraction class

#ifndef _FRACTION_H
#define _FRACTION_H

#include <iostream>

using namespace std;


enum output_Format {mixed,improper,decimal};

class fraction
{
    public:
        // method - default constructor
        // description - construct a default fraction
        // preconditions - none
        // postconditions - default fraction object has been created
        // method input -none
        // method output -none 
        fraction();
        
        // method - parameterized constructor fraction
        // description - construct a fracion with numer and denom parameter
        // preconditions - both numer and denom are int.
        // postconditions - fraction object is created
        // method input -numer and denom of fracion:int
        // method output -none 
        fraction(int numer, int denom);
        
        
        // method - parameterized constructor fraction
        // description - construct a fracion with double number
        // preconditions - number should be double
        // postconditions - fraction object is created
        // method input -number of fraction:double
        // method output -none
        fraction(double num);
        
        //method-setFraction
        //description- sets the fraction 
        //preconditions-both parameters are of type int
        //postconditions-fraction is set 
        //method input: two numbers:int
        //method output:none
        void setFraction(int, int);
        
        //method-setFraction
        //description- sets the fraction 
        //preconditions-s ingle parameter of type double
        //postconditions-fraction is set 
        //method input:  number:double
        //method output:none
        void setFraction(double);
        
        //method-setNumerator
        //description- sets the Numerator 
        //preconditions-numerator of type int
        //postconditions-numerator is set 
        //method input: numerator:int
        //method output:none
        void setNumerator(int numer);
        
        //method-setDenominator
        //description- sets the denominator 
        //preconditions-demoninator of type 
        //postconditions-fraction is set 
        //method input: two numbers:int
        //method output:none
        void setDenominator(int denom);
        
        //method-getNumerator
        //description- returns the numerator of fracion
        //preconditions-fraction has been initialized
        //postconditions-fraction is set 
        //method input: fracion
        //method output:none
        int getNumerator() const;
        
        //method-getDenominator
        //description-  returns denominator
        //preconditions-both parameters are of type int
        //postconditions-fraction is set 
        //method input: two numbers:int
        //method output:none
        int getDenominator() const;
        
        //method-setValue
        //description-  sets the value of fraction
        //preconditions-parameter of type double
        //postconditions-fractional value is set 
        //method input: number:double
        //method output:none
        void setValue(double num);
        
        //method-decimalValue
        //description-  returns fraction
        //preconditions-
        //postconditions-
        //method input: 
        //method output:none
        double decimalValue() const;
        
        //method-reduce
        //description-  reduces fraction
        //preconditions-fraction has been set
        //postconditions-fracion get reduced
        //method input: 
        //method output:none
        void reduce();
        
        //method-outputFormat
        //description-  outputs the fraction
        //preconditions-
        //postconditions-
        //method input:s
        //method output:none
        static void outputFormat( );
        output_Format getFormat() const;
        
        // method -operator overload 
        // description - returns boolean value 
        // preconditions - fracion object has been initilized
        // postconditions - fraction has been returned
        // method input -none
        // method output - boolean value was returned 
        bool operator ==(double) const;
        
        // method -operator overload 
        // description - returns boolean value 
        // preconditions - fracion object has been initilized
        // postconditions - fraction has been returned
        // method input -none
        // method output - boolean value was returned 
        bool operator !=(double) const;
        
        // method -operator overload 
        // description - returns boolean value 
        // preconditions - fracion object has been initilized
        // postconditions - fraction has been returned
        // method input -none
        // method output - boolean value was returned 
        bool operator >(double) const;
        
        // method -operator overload 
        // description - returns boolean value 
        // preconditions - fracion object has been initilized
        // postconditions - fraction has been returned
        // method input -none
        // method output - boolean value was returned 
        bool operator >=(double) const;
        
        // method -operator overload 
        // description - returns boolean value 
        // preconditions - fracion object has been initilized
        // postconditions - fraction has been returned
        // method input -none
        // method output - boolean value was returned 
        bool operator <(double) const;
        
        // method -operator overload 
        // description - returns boolean value 
        // preconditions - fracion object has been initilized
        // postconditions - fraction has been returned
        // method input -none
        // method output - boolean value was returned 
        bool operator <=(double) const;
        
        // method -operator overload 
        // description - returns boolean value 
        // preconditions - fracion object has been initilized
        // postconditions - fraction has been returned
        // method input -none
        // method output - boolean value was returned 
        bool operator ==(const fraction&) const;
        
        // method -operator overload 
        // description - returns boolean value 
        // preconditions - fracion object has been initilized
        // postconditions - fraction has been returned
        // method input -none
        // method output - boolean value was returned 
        bool operator !=(const fraction&) const;
        
        // method -operator overload 
        // description - returns boolean value 
        // preconditions - fracion object has been initilized
        // postconditions - fraction has been returned
        // method input -none
        // method output - boolean value was returned 
        bool operator > (const fraction&) const;
        
        // method -operator overload 
        // description - returns boolean value 
        // preconditions - fracion object has been initilized
        // postconditions - fraction has been returned
        // method input -none
        // method output - boolean value was returned 
        bool operator >=(const fraction&) const;
        
        // method -operator overload 
        // description - returns boolean value 
        // preconditions - fracion object has been initilized
        // postconditions - fraction has been returned
        // method input -none
        // method output - boolean value was returned 
        bool operator < (const fraction&) const;
        
        // method -operator overload 
        // description - returns boolean value 
        // preconditions - fracion object has been initilized
        // postconditions - fraction has been returned
        // method input -none
        // method output - boolean value was returned 
        bool operator <=(const fraction&) const;
        
        
        // method -operator overload 
        // description - returns fractional sum 
        // preconditions - fracion object has been initilized
        // postconditions - fraction has been returned
        // method input -none
        // method output - fractional value was returned 
        fraction operator + (const fraction&) const;
        
        // method -operator overload 
        // description - returns fractional difference 
        // preconditions - fracion object has been initilized
        // postconditions - fraction has been returned
        // method input -none
        // method output - fractional value was returned 
        fraction operator - (const fraction&) const;
        
        // method -operator overload 
        // description - returns fractional product 
        // preconditions - fracion object has been initilized
        // postconditions - fraction has been returned
        // method input -none
        // method output - fractional value was returned 
        fraction operator * (const fraction&) const;
        
        // method -operator overload 
        // description - returns fractional division 
        // preconditions - fracion object has been initilized
        // postconditions - fraction has been returned
        // method input -none
        // method output - fractional value was returned 
        fraction operator / (const fraction&) const;
        friend ostream& operator <<(ostream&, const fraction&);
    private:
        int numerator;
        int denominator;
        static output_Format format;                
        
};

istream& operator >>(istream&, fraction&);

#endif
    
