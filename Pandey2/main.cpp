// File:      main.cpp
// Author:    Dan Brekke

// This file contains the main function that shows what should compile
// for program 2.

#include <iostream>
#include <iomanip>
#include <string>
#include "date.h"
using namespace std;
using namespace DateNameSpace;

int main()
{

/*************** AT MINIMUM, GET THIS STUFF TO WORK FIRST ******************/
/*************** IT CAN BE TURNED IN FOR 50% CREDIT ******************/


   Date d1;  // initialized to the current date
   cout << "Today: ";
   cout << d1.getMonth() << '/' << d1.getDay() << '/' << d1.getYear() << endl;
   /*
      output formatting - 4 categories (you need an enum and static
                                        attribute for each)
          order of the date
             LitteEndian - day month year
             MiddleEndian - month day year - default
             BigEndian - year month day
          delimeter for a numeric date
             Slash - '/' - default
             Dash - '-'
             Space - ' '
          month formatting
             Text - word for the month (January, February, etc.)
             Numeric - number for the month (1, 2, etc.) - default 
          day of the week
             Weekday - include the day of the week
             NoWeekday - do not include the day of the week - default

   */
   // default - MiddleEndian, Slash, Numeric, NoWeekday

   d1.setDate(2,5,2019);
   //Date::outputFormat(MiddleEndian);
   

   cout << "----------------- MiddleEndian -------------------\n";
   cout << "Date: " << d1 << endl;  // Date: 2/5/2019
   cout << "Date: " << left << setw(12) << d1 << '*' << endl;  
   cout << "Date: " << right << setw(12) << d1 << '*' << endl;  
   cout << "Date: " << d1 << endl;  // Date: 2/5/2019
   Date::outputFormat(Dash);
   cout << "Date: " << d1 << endl;  // Date: 2-5-2019
   Date::outputFormat(Space);
   cout << "Date: " << d1 << endl;  // Date: 2 5 2019
   Date::outputFormat(Slash);  // return to default
   cout << "Date: " << d1 << endl;  // Date: 2/5/2019
   Date::outputFormat(Weekday);
   cout << "Date: " << d1 << endl;  // Date: Tuesday, 2/5/2019
   Date::outputFormat(Text);  // delimeter is not used
   cout << "Date: " << d1 << endl;  // Date: Tuesday, February 5, 2019
   Date::outputFormat(NoWeekday);  // return to default
   cout << "Date: " << d1 << endl;  // Date: February 5, 2019
   cout << "----------------- LittleEndian -------------------\n";
   Date::outputFormat(Slash);  // default
   Date::outputFormat(Numeric);  // default
   Date::outputFormat(NoWeekday);  // default
   Date::outputFormat(LittleEndian);  
   cout << "Date: " << d1 << endl;  // Date: 5/2/2019
   Date::outputFormat(Dash);
   cout << "Date: " << d1 << endl;  // Date: 5-2-2019
   Date::outputFormat(Space);
   cout << "Date: " << d1 << endl;  // Date: 5 2 2019
   Date::outputFormat(Slash);  // return to default
   cout << "Date: " << d1 << endl;  // Date: 5/2/2019
   Date::outputFormat(Weekday);
   cout << "Date: " << d1 << endl;  // Date: Tuesday, 5/2/2019
   Date::outputFormat(Text);  // delimeter is not used
   cout << "Date: " << d1 << endl;  // Date: Tuesday, 5 February, 2019
   Date::outputFormat(NoWeekday);  // return to default
   cout << "Date: " << d1 << endl;  // Date: 5 February, 2019
   cout << "----------------- BigEndian -------------------\n";
   Date::outputFormat(Slash);  // default
   Date::outputFormat(Numeric);  // default
   Date::outputFormat(NoWeekday);  // default
   Date::outputFormat(BigEndian);  
   cout << "Date: " << d1 << endl;  // Date: 2019/2/5
   Date::outputFormat(Dash);
   cout << "Date: " << d1 << endl;  // Date: 2019-2-5
   Date::outputFormat(Space);
   cout << "Date: " << d1 << endl;  // Date: 2019 2 5
   Date::outputFormat(Slash);  // return to default
   cout << "Date: " << d1 << endl;  // Date: 2019/2/5
   Date::outputFormat(Weekday);
   cout << "Date: " << d1 << endl;  // Date: Tuesday, 2019/2/5
   Date::outputFormat(Text);  // delimeter is not used
   cout << "Date: " << d1 << endl;  // Date: Tuesday, 2019 February 5
   Date::outputFormat(NoWeekday);  // return to default
   cout << "Date: " << d1 << endl;  // Date: 2019 February 5
   cout << "-----------------------------------------------\n";

   Date::outputFormat(Slash);  // default
   Date::outputFormat(Numeric);  // default
   Date::outputFormat(NoWeekday);  // default
   Date::outputFormat(MiddleEndian);  // default

   
// Your Date class should throw exceptions whenever a possible error
// could occur.  Create your own DateException class.

   try
   {
      d1.setDate(13,5,2000);
   }
   catch (DateException error)
   {
      cout << error.what() << endl;
      cout << "    d1 is still " << d1 << endl;
   }

   try
   {
      d1.setDate(2,29,1999);
   }
   catch (DateException error)
   {
      cout << error.what() << endl;
      cout << "    d1 is still " << d1 << endl;
   }

   d1.setDate(4,15,2000);
   cout << d1 << endl;

   Date d2;  // initialized to current date
   Date d3(1,1,1);
   d3 = d2;
   d3.setDate(7,20,1969);
   cout << d3.getMonth() << '-' << d3.getDay() << '-' << d3.getYear() << endl;
   Date d4(11,11,2011);
   d3 = Date::Today();  // d3 set to current date
   d4.setToday();  // d4 set to current date
   if (d2==d3 && d2==d4 && d3==d4)
      cout << "That's right, they're all equal\n";
   else
      cout << "my program has problems";
// Overload all relational operators

   Date LincolnBirthday(2,12,1809);
   Date LincolnDeath;
   LincolnDeath.setDate(4,15,1865);
   cout << "Abraham Lincoln was born on a "
        << LincolnBirthday.getDayOfWeek() << " and died on a "
        << LincolnDeath.getDayOfWeek() <<".\n";

   Date myBirthday;
   try
   {
      cout << "enter your birthday: ";
      // input format: month/day/year (all ints including any char delimeter)
      // note that MiddleEndian, LittleEndian, BigEndian applies only to output
      cin >> myBirthday;  
      cout << "your birthday is " << myBirthday << endl;
   }
   catch (ios_base::failure error) // input state failed
   {
      cout << error.what() << endl;
   }
   catch (DateException error) // input state OK, but invalid date
   {
      cout << error.what() << endl;
   }
// what follows is the same code segment to ensure input is not in a failed state
   try
   {
     cout << "enter your birthday: ";
      cin >> myBirthday;  // format: month/day/year (all ints)
      cout << "your birthday is " << myBirthday << endl;
   }
   catch (ios_base::failure error)
   {
      cout << error.what() << endl;
   }
   catch (DateException error)
   {
      cout << error.what() << endl;
   }
   

/*************** NEXT LEVEL FOR 25% MORE CREDIT ******************/
  
   cout << "----------------------------------------------------------\n";
   Date today; // current date
   //d2 = Date(2,29,1999);
   d2=today;
   cout << d2 << endl;
   d3 = d2++;  // increment a day
   cout << d2 << endl;
   d3++;
   d3++;
   cout << d3 << endl;
   d2 = ++d3;
   cout << d2 << endl;
   d2--;
   cout << d2 << endl;
   d3 = --d2;
   --d2;
   cout << d3 << endl << d2 << endl;


/*************** NEXT LEVEL FOR 25% MORE CREDIT ******************/


   cout << "----------------------------------------------------------\n";
   Date::Arithmetic(Years);  // the default is Days
   Date FluxCapacitor(11,5,1955);  // November 5, 1955
   cout << "Dr. Emmett L. Brown conceived the possibility of time travel "
        << today-FluxCapacitor << " years ago\n";
   cout << "Dr. Emmett L. Brown conceived the possibility of time travel "
        << Date::Today()-FluxCapacitor << " years ago\n";
   cout << "Abraham Lincoln lived to be " 
        << LincolnDeath-LincolnBirthday << " years old\n";
// if the object occurs after the argument, the result is negative   
// yes, I know below sounds goofy but the result is negative
   cout << "Abraham Lincoln was born " 
        << LincolnBirthday-LincolnDeath
        << " years after his death\n";


   cout << "Abraham Lincoln would be "
        << today-LincolnBirthday << " years old today\n";
   Date::Arithmetic(Days);
   cout << "Abraham Lincoln lived " 
        << LincolnDeath-LincolnBirthday << " days\n";
// if the object occurs after the argument, the result is negative 
// again, the next output is goofy but the result is negative
   cout << "Abraham Lincoln was born " 
        << LincolnBirthday - LincolnDeath << " days after his death\n";
   cout << "Abraham Lincoln died " 
        << today-LincolnDeath << " days ago\n";
   cout << "It's " << LincolnBirthday.daysUntil() // the year doesn't matter
        << " days until Abraham Lincoln's birthday.\n";
        
   Date appointment(5,30,2022);
   Date::Arithmetic(Days);
   cout << "don't forget that you have an appointment in " 
        << appointment.until() << " days!\n";
   Date::Arithmetic(Years);
   cout << "don't forget that you have an appointment in " 
        << appointment.until() << " Years!\n";

   cout << "d2 is " << d2 << endl;
   Date::Arithmetic(Days);
   d2++;  // add 1 day
   Date::Arithmetic(Years);
   d2++;  // add 1 year
   ++d2;  // add 1 year
   cout << "d2 is now " << d2 << endl;
   cout << "d3 is " << d3 << endl;
   if (d2 > d3)  
      cout << "Yes\n";  // Yes, since d2 occurs after d3
   else
      cout << "my program has problems";
   d3 = d2--;  // subtract 1 year from d2, d3 is the original value of d2
   Date::Arithmetic(Days);
   --d2;  // subtract 1 day
   cout << "d2 is now " << d2 << endl;
   cout << "d3 is " << d3 << endl;
   
   d3.setDate(7,20,1969);
   cout << "a human first set foot on the moon " 
        << Date::Today()-d3 << " days ago\n";
   d2 = d3;
   Date::Arithmetic(Days);
   d3 = d3 + 7;  // add 7 days
   cout << "d3 is now " << d3 << endl;
   d3 = d3 - 7;  // subtract 7 days
   cout << "d3 is now " << d3 << endl;
   Date::Arithmetic(Years);
   d3 = d3 + 10;  // add 10 years
   cout << "d3 is now " << d3 << endl;
   cout << "d2 is " << d2 << endl;
   int num;
   num = d3-d2;
   cout << "num is " << num << endl;
   d2++;
   num = d3-d2;
   cout << "num is " << num << endl;
   num = d2-d3;
   cout << "num is " << num << endl;
   Date::Arithmetic(Days);
   num = d3-d2;
   cout << "num is " << num << endl;
   
// Arithmetic that doesn't make sense
//   d2 = d3+d4;
//   d2 = d3*d4;
//   d2 = d3/d4;
//   d2 = d3%d4;
   
// Also, overload the +=, -= etc. where appropriate
   cout << "d2 is " << d2 << endl;
   d2 += 4;
   cout << "d2 is " << d2 << endl;
   d2 -= 4;
   cout << "d2 is " << d2 << endl;
   cout << "d1 is " << d1 << endl;
   num -= d1-d2;
   num += d1-d2;
   cout << "num is " << num << endl;
   
/************************* BONUS LEVEL ***************************/

  /* cout << "----------------------------------------------------------\n";
   Date::Arithmetic(Months);
   cout << "don't forget that you have an appointment in " 
        << appointment.until() << " months!\n"; */
        
// All operators and methods that apply to Days and Years must
// also apply to Months if you are to receive bonus points.
// Everything works for Months or no bonus.  I am aware that Months
// are not as smooth as Days and Years. Even Years has a bump with
// leap year (for example adding 1 year to 2/29/2000 should not
// produce an error).  Handle Months as you see fit without producing
// an error.  All should be explained in your README file.
   

   return 0;
}
