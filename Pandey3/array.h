// File:    array.h
// Author:  Sushil Pandey
// Program: program3
// Date:    14/03/2019

//Description: This file contains specifications and implementation of the ADT Array class
#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <iostream>
#include <cassert>
using namespace std;
namespace ArrayNameSpace 
{
    template <class T>
    class Array
    {
    public:
        // method - explicit Array constructor
        // description - construct Array Class
        // preconditions - 
        // postconditions - Array object has been created. length=0 and      
        //                  startIndex=0
        // method input -none
        // method output -
        explicit Array()
        {
            
            //theArray=new T[0];
            startIndex=0;
            length=0;
        }
        
        // method - parameterized Array constructor
        // description - construct Array of size num
        // preconditions - 
        // postconditions - The variable list contains the base address of the  
        //                  array. length=num and startIndex=0
        // method input -none
        // method output-none
        Array(int num );
        
        // method - Array constructor with two parameters
        // description - construct Array Class
        // preconditions - 
        // postconditions - The variable list contains the base address of the  
        //                  array. length=end-start+1 and startIndex=start
        // method input -none
        // method output-none
        Array(const int start,const int end);
        
        
        
        // method - copy constructor 
        // description -  Function to make a copy of otherStack.
        // preconditions - 
        // postconditions - A copy of otherStack is created and
      //               assigned to this Array. 
        // method input -none
        // method output-none
        Array (const Array<T>& otherArray); // copy constructor
        
        
        // method - destructor
        // description - Remove all the elements from the Array.
        // preconditions - 
        // postconditions - The array (list) holding the Array 
        //               elements is deleted.
        // method input -none
        // method output-none
        ~Array();   // destructor
        
        // method - operator equal
        // description - overloads the assignment operator
        // preconditions - 
        // postconditions - 
        // method input -none
        // method output-none
        const Array<T>& operator=(const Array<T>& ); //overloads the assignment operator
        
        // method - [] operator
        // description - overloads the [] operator
        // preconditions - 
        // postconditions - 
        // method input -none
        // method output-none
        T& operator[](int index);
        
        // method - [] operator
        // description - overloads the [] operator and allows a 
        //               const pass by reference argument
        // preconditions - 
        // postconditions - 
        // method input -none
        // method output-none
        const T& operator[](int index) const;
        
        // method -  function Size
        // description - returns the length of the Array
        // preconditions - 
        // postconditions - 
        // method input -none
        // method output-length of the Array has been returned 
        int Size() const;
        
        // method - function getStartIndex
        // description - returns the starting index of the Array
        // preconditions - 
        // postconditions - 
        // method input -none
        // method output-starting index of the array has been returned
        int getStartIndex() const;
        
        // method - function setStartIndex
        // description - sets the staring index for Array
        // preconditions - 
        // postconditions - 
        // method input -int number is provided
        // method output-starting index has been set to num.
        void setStartIndex(int s );
        
        // method - function resize
        // description - changes the size of the array
        // preconditions - 
        // postconditions - throws exception if new size is less than 0 and 
        //                  truncate if less than original Array        
        // method input -none
        // method output-Array with new size
        void Resize(int s);
        
        // method - function Reverse
        // description - returns the array with its array contents in opposite order
        // preconditions - 
        // postconditions - 
        // method input -none
        // method output-Array with contents in opposite order has been returned
        Array Reverse() const;
        
        // method - function Ascending
        // description - returns the array contents in Ascending order
        // preconditions - 
        // postconditions - original array is unchanged
        // method input -none
        // method output-Array with array contents in ascending order has been returned
        Array Ascending();
        
        // method -function Descending
        // description - returns the array contents in Descending order
        // preconditions - 
        // postconditions - original array is unchanged
        // method input -none
        // method output-Array with array contents in Descending order has been returned
        Array Descending() ;
        
        // method -  boolean operator ==
        // description - returns the true if two array are equal in size and contents
        // preconditions - 
        // postconditions - 
        // method input -none
        // method output-
        bool operator == (const Array<T>& otherArray) const ;
        
        // method -  boolean operator less than
        // description - returns the true if two array are not equal in size and contents
        // preconditions - 
        // postconditions - 
        // method input -none
        // method output-
        bool operator< (const Array<T>& ) const;
        
        // method -  boolean operator less than and equal
        // description - returns the true if one array is less than other
        // preconditions - 
        // postconditions - 
        // method input -none
        // method output-
        bool operator<= (const Array<T>& ) const;
        
        // method -  boolean operator not equal
        // description - returns the true if two arrays are not equal in size or contents
        // preconditions - 
        // postconditions - 
        // method input -none
        // method output-
        bool operator!= (const Array<T>& ) const;
        
        // method -  boolean operator greater than 
        // description - returns the true if array size is greater than other
        // preconditions - 
        // postconditions - 
        // method input -none
        // method output-
        bool operator> (const Array<T>& ) const;
        
        // method -  boolean operator greater than and equal 
        // description - returns the true if one array are greater than other in size and have same contents
        // preconditions - 
        // postconditions - 
        // method input -none
        // method output-
        bool operator>= (const Array<T>& ) const;
        
        
    private:
        T *theArray;  //array to hold the Array elements
        int length;   //variable to store the length of the Array
        int startIndex; // variable to store staring index of Array
        //int endIndex;   
        
        
        
    };

    template <class T>    
    Array<T> :: Array(int num)
    {
        if(num<0)
            throw out_of_range("out of range: num not be negative ");
        theArray = new T[num];
        length=num;
        startIndex=0;
        //endIndex=num-1;
      
        
            
    }
    
    template<class T>
    Array<T>::Array(const int start, const int end)
    {
        if(end<start)
            throw out_of_range("out of range: end can not be smaller than start");
        length=end-start+1;
        theArray = new T[length];
        startIndex=start;
        //endIndex=end;
     
        
    }
    
    template<class T>
    int Array<T>::Size() const
    {   //cerr<<"IN size"<<endl;
        return length;
    }
    
    template <class T>
    int Array<T>::getStartIndex() const
    {
        return startIndex;
    }
    
    template <class T>
    void Array<T>::setStartIndex(int s)
    {
        Array<T> temp=*this;
        startIndex=s;
        //endIndex=getStartIndex()+Size()-1;
        for(int i= 0 ; i<Size();i++)
        {
            theArray[i]=temp.theArray[i];
           
        }
    }
    
    template<class T>
    void Array<T>::Resize(int s)
    {
        if(length == 0)
        {
            theArray=new T[s];
            length=s;
        }
        else if (s  < 0)
            
            throw out_of_range("Exception: new size less than 0");
       
        else if (s >= Size())
        {
            Array<T> temp=*this;
            delete [] theArray;
            theArray = new T[s];
            
            for(int i=0;i<Size();i++)
            {
                theArray[i]=temp.theArray[i];
                
            }
            length=s;
         
        
        }
        else if(s < Size())
        { 
            length =s;
            Array<T>temp=*this;
            delete [] theArray;
            theArray = new T[s];
            for(int i=0;i<s;i++)
            {theArray[i]=temp.theArray[i];
            }
           
        }
        
    }
    
    
    template <class T>
    Array<T> Array<T>::Reverse() const
    {
       
        Array<T> temp=*this;
        for(int i=0; i<length; ++i)
        {
           
            temp.theArray[i]=theArray[length-i-1];
        }
       
        return temp;
     
    }
    
    
   /*template <class T>
    Array<T> Array<T>::Descending()
    {  
        Array<T> temp=*this;        
        for(int i=0;i<Size();i++)
            {		
                for(int j=i+1;j<Size()+1;j++)
                {
                    if(theArray[i]<theArray[j])
                    {
                        temp[i]  =temp.theArray[i];
                        temp.theArray[i]=temp.theArray[j];
                        temp.theArray[j]=temp.theArray[i];
                    }
                }
                
            }
           
         return temp;  
    }*/
   
   template <class T>
   Array<T> Array<T>::Descending()
   {
      
      int i,j,flag = 1;   
      int temp;             
      int numLength = Size(); 
      Array<T> tempArray = *this;
      for(i = 1; ( i <= numLength) && flag; i++)
     {
          flag = 0;
          for ( j=0; j < (numLength -1); j++)
         {
               if (tempArray.theArray[j+1] > tempArray.theArray[j])    
              { 
                    temp = tempArray.theArray[j];             
                    tempArray.theArray[j] = tempArray.theArray[j+1];
                    tempArray.theArray[j+1] = temp;
                    flag = 1;               
               }
          }
     }
    return tempArray;
}
    
    template <class T>
    Array<T> Array<T>::Ascending()
    { /* Array<T> temp=*this;
        for(int i=0;i<Size();i++)
        {
            for(int j=i+1;j<Size()+1;j++)
            {
                if(theArray[i]>theArray[j])
                {
                    temp.theArray[i]=theArray[i];
                    theArray[i]=theArray[j];
                    theArray[j]=temp.theArray[i];
                    
                }
            }
        }
        return temp;*/       
        Array<T> temp = *this;
        temp = temp.Descending();
        temp = temp.Reverse();
        return temp;
    }
    
    template <class T>
    Array<T>::~Array()
    {
        delete[] theArray;
        theArray=NULL;
    }
    
    
    template <class T>
    Array<T>::Array(const Array<T>& otherArray)
    {
        length=otherArray.Size();
        startIndex=otherArray.getStartIndex();
        //endIndex=otherArray.endIndex;
        theArray=new T[length]; 
        assert(theArray!=NULL);
        for (int i=0;i<Size();i++)
            theArray[i]=otherArray.theArray[i];
        

    }
    
    template <class T>
    const Array<T>& Array<T>::operator=(const Array<T>& otherArray)
    {
        if(this!=&otherArray)
        {
            delete [] theArray;
            length=otherArray.Size();
            startIndex=otherArray.getStartIndex();
            //endIndex=otherArray.endIndex;
            theArray=new T[length];
            assert (theArray!=NULL);
            for(int i=0;i<Size();i++)
                theArray[i]=otherArray.theArray[i];
        }
        return *this;
    }
    
    
    template <class T> 
    T& Array<T>::operator[](int index)
    {
        if (index >= (Size()+startIndex) || index < startIndex )
        {
            throw out_of_range("out_of_range: index out of range");
        }
        else
            return theArray[index-getStartIndex()];
    } 
    
    template <class T>
    const T& Array<T>::operator[](int index) const
    {
        
        if (index >= (Size()+startIndex) || index < startIndex)
        {
            throw out_of_range("out_of_range: index out of range");
        }
        else
            return theArray[index-getStartIndex()];
    }
    
    template <class T>
    bool Array<T>:: operator == (const Array<T>& otherArray) const 
    {
      
//         if(otherArray.Size()!=Size())
//         {
//             return false;
//         }
        for(int i=0;i<Size();i++)
        {
            if (otherArray.Size()!=Size() && otherArray.theArray[i]!=theArray[i])
                return false;
        }
        return true;
    }
    
    template <class T>
    bool Array<T>::operator < (const Array<T>& otherArray) const
    {
    bool Check=false;
       if(otherArray.Size() == Size())
       {
            for(int i=0; i < Size();i++)
                {
                    if(otherArray.theArray[i]==theArray[i])
                        Check=true;
                    else 
                        Check=false;    
                }
       }
       else 
           Check=true;
      return Check;
        
    }
    
    template <class T>
    bool Array<T>::operator<= (const Array<T>& otherArray ) const 
    {
        return (*this<otherArray || *this==otherArray); 
    }
    
    
    template <class T>
    bool Array<T>::operator!= (const Array<T>& otherArray) const
    {
        return !(*this==otherArray);
    }
    
    template <class T>
    bool Array<T>::operator > (const Array<T>& otherArray) const
    {
        return !(*this <= otherArray);
    }
    
    
    template <class T>
    bool Array<T>::operator>= (const Array<T>& otherArray) const
    {
        return!(*this < otherArray );
        
        
    }


}

#endif
