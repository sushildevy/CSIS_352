// File:    hashtable.h
// Author:  Sushil Pandey
// Program: Assignment7
// Date:    05/07/2019

//Description: This file contains specification and implementation of the HashTable class
#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include "symbol.h"
#include <iomanip>


using namespace std;
const int size=13;
template<class T>
class HashTable
{
    public:
    //method - parametarized constructor 
    //description-  construct HashTable object with two arguments
    //preconditions - none
    //Postcondition - HashTable object created with given size and int pointer to templated function 
    //method input - none; 
    //method output -none;
    HashTable(int,int(*)(const T&));

    //method - insert()
    //description-  inserts item to vector and count collisions. 
    //preconditions - none
    //Postcondition - items inserted to vector
    //method input - none; 
    //method output -none;
    void insert(const T&);

     //method - search()
    //description-search if the item is alrealy in vector container
    //preconditions - none
    //Postcondition - returns a boolen value: if foud true and false otherwise
    //method input - none; 
    //method output -none;
    bool search(const T& ) const;

    //method - collisions()
    //description- returns the number of collisions occurred during insertion
    //preconditions - none
    //Postcondition - count of collisions is returned 
    //method input - none; 
    //method output -none;
    int collisions();

    //method - dump()
    //description-prints the data in well format 
    //preconditions - none
    //Postcondition - requied information is printed 
    //method input - none; 
    //method output -none;
    void dump();

    //method -retieve
    //description-returns item name if it is same as retrieveditem in vector container
    //preconditions - none
    //Postcondition - item name is returned
    //method input - none; 
    //method output -none;
    T retrieve(T&) const;


    private:
    int collisionCount;              //private attribute to count the number of collisions
    int count;                       //private attribute to store the number of items in vector container
    int maxSize;                    //maximum size of hashTable 
    int (*funcPtr)(const T& );      //function pointer 
    vector<T> vecHashTable;         //vector container 
    list<int> hashTable;            //list container
    bool contains(const T& );           
    
   


};
template<class T>
HashTable<T>::HashTable(int size, int(*ptr)(const T& ))
{
    maxSize=size;
    funcPtr=ptr;
    count=0;
    collisionCount=0;
    vecHashTable.resize(maxSize);
     

}

template<class T>
void HashTable<T>::insert(const T& item)
{   
    if(search(item))
    {  
        throw logic_error(" is duplicate here");
    }
    int index = funcPtr(item);
    list<int>::iterator it1;
    it1=hashTable.begin();
    bool found=false;
     for(it1;it1!=hashTable.end();it1++)
    {
        if(*it1==index)
        {
            found =true;
            collisionCount++;
            break;
        }
    }
    if(!found)
    {
        hashTable.push_back(index);
    }
    else
    {
        index++;
        if(index==maxSize)
            index=0;
        bool found1 =find(hashTable.begin(),hashTable.end(),index)!=hashTable.end();
        bool x=false;
        while( found1) 
        {
            index++;
            if(index==maxSize)
                index=0;

            found1 =find(hashTable.begin(),hashTable.end(),index)!=hashTable.end();
            if(found1==false)
                break;
           
        }
       hashTable.push_back(index);
       
    }
     
    
    vecHashTable[index] = item;
    count++;
}

template<class T> 
bool HashTable<T>::search(const T& item) const
{
    bool found;
    T value=item;
    typename vector<T>::const_iterator it;
   if(find(vecHashTable.begin(),vecHashTable.end(),value)!=vecHashTable.end())
       
       found=true;
      
   else
       found=false;

   return found;
   
}

template<class T>
int HashTable<T>::collisions()
{
    return collisionCount;
}

template<class T>
void HashTable<T>::dump()
{
   
    typename vector<T>::iterator it;
    it=vecHashTable.begin();
    int flag=0;
    while(flag<maxSize)
    {
        bool found=false;
        cout<<setw(10)<<left<<"\nhashtable["<<setw(2)<<right<<flag<<"]"<<setw(4)<<": ";
       
            for(int i = 0;i<maxSize;i++)
            {  
                T item=vecHashTable[i];
                //bool tmpFound=find(vecHashTable.begin(),vecHashTable.end(),item)!=vecHashTable.end();
                int index=funcPtr(vecHashTable[i]);
                if(index==flag && contains(item))
                {
                    cout<<vecHashTable[i]<<" ";
                    //cout<<"index :"<<index;
                    found = true;
                }
            }
            if(found==false)
                cout<<"{empty}";
            flag++;     

       
    }     
        cout<<endl; 
        

}

template<class T>
T HashTable<T>::retrieve(T& item) const
{
    
    bool found=false;
    typename vector<T>::const_iterator it;
    it=vecHashTable.begin();
    for(it;it!=vecHashTable.end();it++)
    {   
        if(*it==item)
        {
            item=*it;
            found=true;
        }
    }
    if(found==true)
        return item;
    else
    {
        throw logic_error("item not is the hash table");
    }
    
}

template<class T>
bool HashTable<T>::contains(const T& item)
{
    typename vector<T>::const_iterator it;
    bool found=false;
    for(it=vecHashTable.begin();it!=vecHashTable.end();it++)
        {
             if(find(vecHashTable.begin(),vecHashTable.end(),*it)!=vecHashTable.end() && item==*it )
                return (found=true);
        }
       
            return  found;
}

#endif