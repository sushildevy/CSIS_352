// File:    calculation.cpp
// Author:  Sushil Pandey
// Program: Assignment1
// Date:    1/31/2019

//Description: This file contins the function calculation
#include "function.h"
#include <iostream>

void calculation(double& numer, double& denom)
{
    //int tmpNum=1;
    //static_cast<int>(numer);
    //static_cast<int>(denom);
    if(numer < 0)
    {
        numer *=-1;
        
    }
    int tmpGCD=commonFactor(numer,denom);
    while(!(tmpGCD==1))
    {
        numer=numer/tmpGCD;
        denom=denom/tmpGCD;
        tmpGCD=commonFactor(numer,denom);
        
    }
    
    
}

