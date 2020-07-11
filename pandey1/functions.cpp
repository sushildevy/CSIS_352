// File:    gretestCommonFactor.cpp
// Author:  Sushil Pandey
// Program: Assignment1
// Date:    1/31/2019

//Description: This file contins the functions commonFactor,decimalToFraction and calculation.
#include <iostream>
#include <sstream>
#include <math.h>
using namespace std;

int commonFactor(double num1,double num2)
{
    int tmpNum=1;
    int gcd=1;
    while(tmpNum<num1 && tmpNum< num2)
    {
        if(num1 < num2)
        {
            if(static_cast<int>(num1)%tmpNum==0 && static_cast<int> (num2)%tmpNum==0)
            {
                num1 =num1/tmpNum;
                num2=num2/tmpNum;
                gcd=tmpNum;
                tmpNum=2;
            }
            else
            {
                tmpNum++;
            }
              
        }
        else 
        {
            while(tmpNum <= num2)
            {
                if(static_cast<int>(num1)%tmpNum==0 && static_cast<int>(num2)%tmpNum==0)
                {
                    num1=num1/tmpNum;
                    num2=num2/tmpNum;
                    gcd=tmpNum;
                    tmpNum=2;
                }
                else
                {
                    tmpNum++;
                }
            }
        } 
        
    }
    return gcd;
    
}

void decimalToFraction(double decimalNum, double& numer, double& denom)
{
    string tmpString, newTmpString;
    int decimalPlace, positionOfPoint;
    int i=0;
    ostringstream convert;
    convert <<decimalNum;
    tmpString=convert.str();
    while(i < tmpString.size())
    {
        if(!(tmpString[i]=='.'))
        {
            newTmpString+=tmpString[i];
        }
        else
        {
            positionOfPoint=i;
        }
        i++;
    }
    decimalPlace=i-1-positionOfPoint;
    denom =pow(10,decimalPlace);
    istringstream strConvert(newTmpString);
    strConvert>>numer;
    
     
}


void calculation(double& numer, double& denom)
{
    int tmpNum=1;
    //static_cast<int>(numer);
    //static_cast<int>(denom);
    if(numer < 0)
    {
        tmpNum = numer;
        numer *=-1;
        
    }
    int tmpGCD=commonFactor(numer,denom);
    while(!(tmpGCD==1))
    {
        numer=numer/tmpGCD;
        denom=denom/tmpGCD;
        tmpGCD=commonFactor(numer,denom);
        
    }
    if (tmpNum < 0 )
        numer= numer * -1;
    
}

