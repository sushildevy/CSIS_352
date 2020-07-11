// File:    gretestCommonFactor.cpp
// Author:  Sushil Pandey
// Program: Assignment1
// Date:    1/31/2019

//Description:This file contains the main file.

#include <iostream>
#include <iomanip>
using namespace std;
#include "fraction.h"

int main()
{
   fraction f0;
   fraction f1;
   cin >> f0;              // input format numerator/denominator, ex 23/9
   cout << "input: " << f0 << endl;     // outputs what was input

// Note the << and >> operators should also work for file streams

//    cin >> f0 >> f1;     // reads 2 fractions, ex 8/5 12/16
   f1.setFraction(17,6);   // 17/6
   cout << f1.getNumerator() << '/' << f1.getDenominator() << endl; // 17/6
   f1.setFraction(-4.75);     // -19/4
   cout << f1.decimalValue() << endl; // outputs -4.75
   fraction f2(4,8);       // 4/8
   fraction f3(2.875);     // 2 7/8
   cout << f3 << endl;     // outputs 2 7/8 (the default output format is mixed)
   cout << f2 << endl;     // outputs 4/8
   fraction f4(16,8);
   cout << f4 << endl;     // outputs 2
   
   fraction::outputFormat(improper); // set output format to improper fraction
   cout << f4 << endl;     // outputs 16/8
   cout << f3 << endl;     // outputs 23/8
   cout << f1 << endl;     // outputs -19/4
   
   fraction::outputFormat(decimal); // set output format to decimal value
   cout << f3 << endl;     // outputs 2.875
   cout << f2 << endl;     // outputs 0.5
   cout << f1 << endl;     // outputs -4.75
   
   fraction::outputFormat(mixed); // set output format back to default mixed
   cout << f3 << endl;     // outputs 2 7/8
   f1.setFraction(-4.75);
   cout << f1 << endl;     // outputs -4 3/4
   cout << f2 << endl;     // outputs 4/8
   
   fraction f5(12,8);
   fraction::outputFormat(improper);
   cout << f5 << endl;     // outputs 12/8
   f2.reduce();            // convert to lowest terms
   f5.reduce();
   cout << f2 << endl;     // outputs 1/2
   cout << f5 << endl;     // outputs 3/2
   f5.setDenominator(16);  // change denominator and numerator
                           // error if numerator is not a whole number
   cout << f5 << endl;     // outputs 24/16
   f5.setDenominator(22);
   cout << f5 << endl;     // outputs 33/22
   f5.setDenominator(5);   // output error as numerator would have to be 7.5
   cout << f5 << endl;     // outputs 33/22 (fraction remained the same)
   
   f1 = f3+f2;             // f1 put in lowest terms
   cout << f1 << endl;     // outputs 27/8
   f1 = f3-f2;
   cout << f1 << endl;
   f1 = f3*f2;
   cout << f1 << endl;
   f1 = f3/f2;
   cout << f1 << endl;
   
   f1 = f3;
   cout << f1 << endl;      // outputs 23/8
   f1 = 7.75;
   f1 = f2 = 7.75;
   cout << f1 << endl;      // outputs 31/4
   cout << setw(6) << f1 << setw(6) << f2 << endl; // outputs  31/4  31/4
   
   f0.setFraction(31,4);
   if (f0 == f1)
      cout << "correct\n";
   else
      cout << "incorrect\n";
   // all relational operators should work for comparing 2 fractions
   
   if (f0 == 7.75)
      cout << "correct\n";
   else
      cout << "incorrect\n";
   // all relational operators should work for comparing fraction to double
   
   f0.setFraction(2);
   if (f0 < 3)
      cout << "correct\n";
   else
      cout << "incorrect\n";
   // all relational operators should work for comparing fraction to int 
   
   return 0;
}
