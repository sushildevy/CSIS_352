#include <iostream>
using namespace std;
#include "sortedList.h"
using namespace sortedListSpace;

sortedList<int> func(sortedList<int> anotherlist)
{
   return anotherlist;
}

void output(const sortedList<int>& list)
{
   for (int i=0; i<list.length(); i++)
      cout << list[i] << ' '; // operator[] can throw out_of_range exception
   cout << endl;
}

void output2(const sortedList<char>& list)
{
   for (int i=0; i<list.length(); i++)
      cout << list[i] << ' '; // operator[] can throw out_of_range exception
   cout << endl;
}

void visit(int& num)
{
   cout << num << '/';
}

void increment(int& num)
{
   num++;
}

int main()
{
   sortedList<int> list1; // you do not specify a size with a linked structure
   sortedList<int> list2; // default is ASCENDING
   sortedList<int> list3(ASCENDING);
   sortedList<int> list4(DESCENDING);
   
   if (list3.isEmptyList())
      cout << "list3 is empty\n";
   else
   {
      cout << "list3 is NOT empty\n";
      //cout<<"xxxxxxxxxxxxx\n";
   }
    
   list3.insertItem(3);
   list3.insertItem(5);
   list3.insertItem(2);
   list3.insertItem(6);
   list3.insertItem(1);
   if (list3.isEmptyList())
      cout << "list3 is empty\n";
   else
      cout << "list3 is NOT empty\n";
   cout << "list3: ";
   //cout<<list3.length();
   for (int i=0; i<list3.length(); i++)
      cout << list3.valueAt(i) << ' ';  // valueAt can throw out_of_range exception
   cout << endl;
   cout << "list3: ";
   for (int i=0; i<list3.length(); i++)
      cout << list3[i] << ' ';  // operator[] can throw out_of_range exception
   cout << endl;
   int i=0;
   try
   {
      while (true)
         cout << list3[i++] << '*';
   }
   catch (out_of_range err)
   {
      cout << endl;
   }
   
 //list3[2]=99999;  // Indexing cannot be used to change a list value
                    //      because it is a sortedList.
                    // This should be syntax error caught by compiler.
                    // Be sure to uncomment to check.
   list3.insertItem(4);  
   if (list3.inList(4))
      cout << "4 is in the list\n";
   else
      cout << "4 is NOT in the list\n";

   list3.insertItem(4);
   list3.insertItem(3);
   list3.insertItem(3);
   list3.insertItem(5);
   list3.insertItem(3);
   list3.insertItem(2);
   list3.insertItem(3);
   cout << "list3: ";
   output(list3);
   list2 = list3;
   cout << "list2 after operator= : ";
   output(list2);
   cerr<<"after = \n";
   output(list3);
   list2 = func(list3);
   cout << "list2 after func call : ";
   output(list2);

   
  list3.deleteItem(3); // deletes the first occurence
   cout << "list3 after deleteItem: ";
   output(list3);
   try
   {
      list3.deleteItem(999); // not in list, logic_error exception
   }
   catch (logic_error e)
   {
      cout << e.what() << endl;
   }
   list3.deleteAll(3);  // deletes all matching values
   try
   {
      list3.deleteAll(3); // not in list, logic_error exception
   }
   catch (logic_error e)
   {
      cout << e.what() << endl;
   }
   cout << "list3 with no 3s in it: ";
   output(list3);
   
   cout << "list3 using traverse: ";
   list3.traverse(visit);
   cout << endl;
   list3.traverse(increment);
   cout << "list3 using traverse: ";
   list3.traverse(visit);
   cout << endl;
   
   list3.merge(list2); // all items in list2 added to list3
   cout << "list3 after merge: ";
   output(list3);
   list3.removeDuplicates();
   cout << "list3 after removing duplicates: ";
   output(list3);
   
   list3.setOrder(DESCENDING);
   list3.setOrder(DESCENDING); // no change since it is already DESCENDING 
   cout << "list3: ";
   output(list3);
   list3.setOrder(ASCENDING); 
   cout << "list3: ";
   output(list3);
   list3.destroyList();
   if (list3.isEmptyList()) 
      cout << "list3 is empty\n";
   else
      cout << "list3 is NOT empty\n";
   list4.insertItem(3);  // list4 is DESCENDING
   list4.insertItem(1);
   list4.insertItem(4);
   list4.insertItem(2);
   list4.insertItem(5);
   cout << "list4: ";
   output(list4);
   list3 = list4;        // list3 would now be DESCENDING
   cout << "list3: ";
   output(list3);
   

   
   return 0;
}
