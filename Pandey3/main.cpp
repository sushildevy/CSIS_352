// File:    main.cpp
// Author:  Sushil Pandey
// Program: program 3
// Date:    14/03/2019

//Description: This file contains sample main program 
#include <iostream>
#include "array.h"
using namespace std;
using namespace ArrayNameSpace;
const int startindex=-3;
const int endindex=2;

void func1(Array<int> n)   // pass by value, actual parameter not changed
{
   for (int i=startindex; i<=endindex; i++)
      n[i] = i;
}

void func2(Array<int>& n)  // pass by reference
{
   for (int i=startindex; i<=endindex; i++)
      n[i] = i;
}

void output(const Array<int>& n)  // const reference
{
   for (int i=n.getStartIndex(); i<n.getStartIndex()+n.Size(); i++)
      cout << "n[" << i << "] = " << n[i] << endl;
}

Array<int> func3(Array<int> n)  // returns an Array
{
   return n;
}

int main()
{
   Array<int> numbers(startindex,endindex); // indices -3 to 2
   for (int i=startindex; i<=endindex; i++) // initialize
      numbers[i] = i*10;
   for (int i=startindex; i<=endindex; i++) // dump the array
      cout << "numbers[" << i << "] = " << numbers[i] << endl;
   cout << "-------------\n";

//   numbers = 20;  // compiler error
   func1(numbers);    // numbers should be the same
   output(numbers);
   cout << "-------------\n";
   func2(numbers);    // numbers contents should change
   output(numbers);
   cout << "-------------\n";

   Array<int> numbers2;  // the array has no locations, but starting index 0
   try
   {
      numbers2[0] = 88;
   }
   catch (out_of_range error)
   {
      cout << error.what() << endl;
   }
   numbers2.Resize(10); // indices 0 through 9
   numbers2[0] = 88;
   output(numbers2);
   cout << "-------------\n";

   numbers2 = numbers;
   numbers2.setStartIndex(10); // indices 10 through 15
   output(numbers2);
   cout << "-------------\n";

   Array<int> numbers3(5);  // array indices 0 through 4
   numbers3 = func3(numbers);
   output(numbers3);
   cout << "-------------\n";
   numbers3.Resize(4); // numbers3 would be truncated
   output(numbers3);
   cout << "-------------\n";
   numbers3.setStartIndex(-8); // indices -8 through -5
   output(numbers3);
   cout << "-------------\n";
   numbers3.Resize(8); // indices -8 through -1
   output(numbers3);
   cout << "-------------\n";
   Array<int> numbers4; // no array locations
   numbers4 = numbers.Reverse(); // reverse contents, indices the same
   output(numbers4); // reverse of numbers
   cout << "-------------\n";
   output(numbers);  // same as before the reverse
   cout << "-------------\n";
   numbers4[-3] = 4;
   numbers4[-2] = 1;
   numbers4[-1] = 5;
   numbers4[0] = 6;
   numbers4[1] = 3;
   numbers4[2] = 2;
   numbers3 = numbers4.Descending(); // numbers3 descending, numbers4 unchanged
   output(numbers3);
   cout << "-------------\n";
   numbers3 = numbers3.Ascending();  // numbers3 ascending
   output(numbers3);
   cout << "-------------\n";

   if (numbers == numbers2) // equal despite different starting indices
      cout << "Equal\n";
   else
      cout << "If you see this, your program has problems!!!\n";

   numbers2[12]=99;
   if (numbers < numbers2)
      cout << "Less Than\n";
   else
      cout << "If you see this, your program has problems!!!\n";
   numbers2 = numbers;
   numbers2.Resize(7);
   if (numbers < numbers2) // less than since equal but numbers has 1 less item
      cout << "Less Than\n";
   else
      cout << "If you see this, your program has problems!!!\n";
// obviously you are to overload all the relational operators

   return 0;

}
