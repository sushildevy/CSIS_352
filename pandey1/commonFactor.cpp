// File:    commonFactor.cpp
// Author:  Sushil Pandey
// Program: Assignment1
// Date:    1/31/2019

//Description: This file contins the function commonFactor
#include <iostream>
using namespace std;
int commonFactor(int a, int b) 
{ 
    if (b == 0) 
        return a; 
     int gcd=commonFactor(b, a % b);
    return gcd;
  
      
}

