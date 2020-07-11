// File:    main.cpp
// Author:  Sushil Pandey
// Program: Assignment7
// Date:    05/07/2019

//Description: This file contains main program
#include <iostream>
#include "hashtable.h"
#include "symbol.h"
#include "constants.h"
using namespace std;

int hash1(const Symbol& value); // found in hashfunctions.cpp
int hash2(const int& value);    // found in hashfunctions.cpp

int main()
{
// Symbol must have operator== overloaded
   HashTable<Symbol> hashtable(TABLE_SIZE,hash1); // TABLE_SIZE in constants.h
   Symbol s;
   s.setSymbol("hello");
   s.setValue(1);
   cout << "Hash value of '" << s.getSymbol() << "' is " 
        << hash1(s) << endl;
   hashtable.insert(s);
    
   if (!hashtable.search(s))
   {
      hashtable.insert(s);
      cout << s << " entered\n";
   }
   else
   {
      cout << s << " already in the table, not entered\n";
   }
   cout << "there were " << hashtable.collisions() << " collisions\n";
   s.setSymbol("there");
   s.setValue(2);
   cout << "Hash value of '" << s.getSymbol() << "' is " 
        << hash1(s) << endl;
   hashtable.insert(s);
   cout << "there were " << hashtable.collisions() << " collisions\n";
   s.setSymbol("how");
   s.setValue(3);
   cout << "Hash value of '" << s.getSymbol() << "' is " 
        << hash1(s) << endl;
   hashtable.insert(s);
   cout << "there were " << hashtable.collisions() << " collisions\n";
   s.setSymbol("are");
   s.setValue(4);
   cout << "Hash value of '" << s.getSymbol() << "' is " 
        << hash1(s) << endl;
   hashtable.insert(s);
   cout << "there were " << hashtable.collisions() << " collisions\n";
   s.setSymbol("you");
   s.setValue(5);
   cout << "Hash value of '" << s.getSymbol() << "' is " 
        << hash1(s) << endl;
   hashtable.insert(s);
   cout << "there were " << hashtable.collisions() << " collisions\n";
   s.setSymbol("I");
   s.setValue(6);
   cout << "Hash value of '" << s.getSymbol() << "' is " 
        << hash1(s) << endl;
   hashtable.insert(s);
   cout << "there were " << hashtable.collisions() << " collisions\n";
   s.setSymbol("am");
   s.setValue(7);
   cout << "Hash value of '" << s.getSymbol() << "' is " 
        << hash1(s) << endl;
   hashtable.insert(s);
   cout << "there were " << hashtable.collisions() << " collisions\n";
   s.setSymbol("fine");
   s.setValue(8);
   cout << "Hash value of '" << s.getSymbol() << "' is " 
        << hash1(s) << endl;
   hashtable.insert(s);
   cout << "there were " << hashtable.collisions() << " collisions\n";
   s.setSymbol("banana");
   s.setValue(8);
   cout << "Hash value of '" << s.getSymbol() << "' is " 
        << hash1(s) << endl;
   hashtable.insert(s);
   cout << "there were " << hashtable.collisions() << " collisions\n";
   s.setSymbol("orange");
   s.setValue(8);
   cout << "Hash value of '" << s.getSymbol() << "' is " 
        << hash1(s) << endl;
   hashtable.insert(s);
   cout << "there were " << hashtable.collisions() << " collisions\n";
   s.setSymbol("pear");
   s.setValue(8);
   cout << "Hash value of '" << s.getSymbol() << "' is " 
        << hash1(s) << endl;
   hashtable.insert(s);
   cout << "there were " << hashtable.collisions() << " collisions\n";
   s.setSymbol("peach");
   s.setValue(8);
   cout << "Hash value of '" << s.getSymbol() << "' is " 
        << hash1(s) << endl;
   hashtable.insert(s);
   cout << "there were " << hashtable.collisions() << " collisions\n";

   cout << "--------------------------------------------------------------\n";

   hashtable.dump();

   cout << "--------------------------------------------------------------\n";

   Symbol s2;
   s2.setSymbol("am");
   cout << "searching for " << s2.getSymbol() << ".  ";
   if (hashtable.search(s2))
   {
      hashtable.retrieve(s2); // s2 is pass by reference, all it needs is the
                              // key and it will come back with the full record
      cout << s2.getSymbol() << " found, value = " << s2.getValue() << endl;
   }
   else
      cout << s2.getSymbol() << " is not in the hash table\n";
   s2.setSymbol("how");
   cout << "searching for " << s2.getSymbol() << ".  ";
   if (hashtable.search(s2))
   {
      hashtable.retrieve(s2); // s2 is pass by reference
      cout << s2.getSymbol() << " found, value = " << s2.getValue() << endl;
   }
   else
      cout << s2.getSymbol() << " is not in the hash table\n";
   s2.setSymbol("baseball");
   cout << "searching for " << s2.getSymbol() << ".  ";
   if (hashtable.search(s2))
   {
      hashtable.retrieve(s2); // s2 is pass by reference
      cout << s2.getSymbol() << " found, value = " << s2.getValue() << endl;
   }
   else
      cout << s2.getSymbol() << " is not in the hash table\n";
   try
   {
      hashtable.retrieve(s2); // s2 is pass by reference
      cout << s2.getSymbol() << " found, value = " << s2.getValue() << endl;
   }
   catch (logic_error e)
   {
      cout << e.what() << endl;
   }


   cout << "--------------------------------------------------------------\n";

   HashTable<int> hashtable2(TABLE_SIZE,hash2);
   int num=57;
   cout << "Hash value of '" << num << "' is " << hash2(num) << endl;
   hashtable2.insert(num);
   num=24;
   cout << "Hash value of '" << num << "' is " << hash2(num) << endl;
   hashtable2.insert(num);
   num=45;
   cout << "Hash value of '" << num << "' is " << hash2(num) << endl;
   hashtable2.insert(num);
   num=17;
   cout << "Hash value of '" << num << "' is " << hash2(num) << endl;
   hashtable2.insert(num);
   num=78;
   cout << "Hash value of '" << num << "' is " << hash2(num) << endl;
   hashtable2.insert(num);
   num=49;
   cout << "Hash value of '" << num << "' is " << hash2(num) << endl;
   hashtable2.insert(num);
   num=6;
   cout << "Hash value of '" << num << "' is " << hash2(num) << endl;
   hashtable2.insert(num);
   num=32;
   cout << "Hash value of '" << num << "' is " << hash2(num) << endl;
   hashtable2.insert(num);
   num=37;
   cout << "Hash value of '" << num << "' is " << hash2(num) << endl;
   try
   {
      hashtable2.insert(num);
      hashtable2.insert(num);  // no duplicates, should throw exception
   }
   catch (logic_error e)
   {
      cout << e.what() << endl;
   }

   cout << "--------------------------------------------------------------\n";
   cout << "there were " << hashtable2.collisions() << " collisions\n";
   hashtable2.dump();
   
   return 0;
}
