// File:    decimalToFraction.cpp
// Author:  Sushil Pandey
// Program: Assignment1
// Date:    1/31/2019

//Description: This file contins the function decimalToFraction

#include <iostream>
#include <sstream>
#include <math.h>
using namespace std;

void decimalToFraction(double decimalNum, double& numer, double& denom)
{

    string tmpString, newTmpString;
    int decimalPlace, positionOfPoint;
    int i=0;
    ostringstream convert;
    convert <<decimalNum;
    //cout<<"first decimal Num"<<decimalNum<<endl;
    tmpString=convert.str();
    //cout<<"Here:"<<tmpString<<endl;
    int j = tmpString.size();
    while(i < j)
    {
        if(!(tmpString[i]=='.'))
        {
            newTmpString+=tmpString[i];
            //cout<<"newTmpString:"<<newTmpString<<endl;
        }
        else
        {
            positionOfPoint=i;
        }
        i++;
    }
    decimalPlace=i-1-positionOfPoint;
    //cout<<"i ko position"<<i<<endl;
    //cout<<"positionOfPOint"<<positionOfPoint<<endl;
    //cout<<"decimal place:"<<decimalPlace<<endl;
    denom =pow(10,decimalPlace);
    //cout<<"aayako denom:"<<denom<<endl;
    istringstream strConvert(newTmpString);
    strConvert>>numer;
    //cout<<"aayako numer:"<<numer<<endl;
    
     
}
