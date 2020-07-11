// File:    hashfunctions.cpp
// Author:  Sushil Pandey
// Program: Assignment7
// Date:    05/07/2019

//Description: This file contains implementation of the hash functions

#include <iostream>
#include "symbol.h"
#include <string>
#include "constants.h"

using namespace std;

int hash1(const Symbol& value)
{
    string stringValue=value.getSymbol();
    int intValue=0;
     for(int i=0;i<static_cast<int>(stringValue.length());i++)
    {
    
        intValue+=stringValue[i];
    } 
    intValue%= TABLE_SIZE;
    return intValue;

}


int hash2( const int& value )
{
    return ( value % TABLE_SIZE);
}