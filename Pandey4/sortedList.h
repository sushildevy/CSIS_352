#ifndef H_STOREDLIST_H
#define H_STOREDLIST_H

#include <iostream>
#include <cassert>
#include <stdexcept>

using namespace std;
namespace sortedListSpace
{
    enum orderFormat{ASCENDING, DESCENDING};
    template <class Type>
    struct nodeType
    {
        Type info;
        nodeType<Type> *link;
    };
    
    template<class Type>
    class sortedList
    {
    public:
        
        // method -function assignment operator
        // description - Overload the assignment operator.
        // preconditions - 
        // postconditions - 
        // method input -none
        // method output-
        const sortedList<Type>& operator= (const sortedList<Type>&);
        
        //method - initializeList()
        //description- Initialize the list to an empty state.
        //Postcondition: first = NULL, count = 0;
        //method input - none
        //method output - none
        void initializeList();
       
        //method - isEmptyList()
        //description- Function to determine whether the list is empty. 
        //Postcondition: Returns true if the list is empty,
        //               otherwise it returns false.
        //method input - 
        //method output -
        bool isEmptyList() const;
        
        //method - destroyList() 
        //description- Function to delete all the nodes from the list.
        //Postcondition: first = NULL, last = NULL, count = 0;
        //method input- none
        //method output - none
        void destroyList();
        
        //method - default constructor
        //description-  Initializes the list to an empty state.
        //preconditions - none
        //Postcondition: first = NULL, count = 0;
        //method input - none; 
        //method output -none; 
        sortedList();
        
        //method -  constructor with output format
        //description-  Initializes the list to an empty state.
        //preconditions - none
        //Postcondition: format= ASCENDING or DESCENDING, count=0, first =NULL
        //method input - none; 
        //method output -none; 
        sortedList(orderFormat);
        
        
        //method - length() 
        //description-  Function to return the number of nodes in the list.
        //Postcondition: The value of count is returned.
        //method input - none
        //method output - none
        int length() const;
       
        // method - [] operator
        // description - overloads the [] operator and allows a 
        //               const pass by reference argument
        // preconditions - 
        // postconditions - 
        // method input -int index is given 
        // method output-none
        const Type& operator[](int index) const;
         
         //method - insertItem()
         //description- Function to insert newItem at the begninning of the list.
        //preconditions- 
         //Postcondition: first points to the new list, newItem 
         //               is inserted at the begninning of the list,
         //               last points to the last node in the list,
         //               and count is incremented by 1.
        //method input -templated item is passed 
        //method output - 
        void insertItem(const Type& newItem);
        
        // method -function valueAt
        // description - value at index is returned 
        // preconditions - 
        // postconditions - index value is given
        // method input -none
        // method output-
        Type& valueAt(int num);
        
        //method - inlist function 
        //description - Function to determine whether searchItem is in the list.
        //Postcondition: Returns true if searchItem is in the 
        //               list, otherwise the value false is 
        //               returned.
        //method input - 
        //method output - 
        bool inList (const Type& item) const;
        
        //method - setorder
        //description - sets the order format
        //preconditions - 
        //postconditions - a output order is set 
        //method input -
        //method output -
        void setOrder(orderFormat);
        
        // method - function Ascending
        // description -  puts the linkedlist info in Ascending order
        // preconditions - 
        // postconditions - original list is unchanged
        // method input -none
        // method output-list with list contents in ascending order 
        void Ascending();
        
        // method - function Reverse
        // description - puts the list with its node contents in opposite order
        // preconditions - 
        // postconditions - 
        // method input -none
        // method output-list with contents in opposite order 
        void Reverse();
        
        // method -function Descending
        // description -  puts the list contents in Descending order
        // preconditions - 
        // postconditions - original array is unchanged
        // method input -none
        // method output-Array with array contents in Descending order 
        void Descending();
        
        //method - deleteItem
        //description - function to delete deleteItem from the list.
        //Postcondition: If found, the node containing 
        //               deleteItem is deleted from the list.
        //               first points to the first node, last
        //               points to the last node of the updated 
        //               list, and count is decremented by 1.
        void deleteItem(const Type& deleteItem);
        
        //method deleteAll
        //description - Function to delete all the deleteItem from the list.
        //preconditions -
        //Postcondition - If found, the node containing 
        //               deleteItem is deleted from the list.
        //               first points to the first node, last
        //               points to the last node of the updated 
        //               list, and count is decremented by 1.
        // method input -none
        // method output-none
        void deleteAll(const Type& deleteItem);
        
        // method - function traverse
        // description - visits every nodes of the linked list
        // preconditions - 
        // postconditions - info at each node 
        // method input -
        // method output-
        void traverse(void (*) (Type&));
        
        // method - function merge
        // description - adds new list items in the existing list
        // preconditions - 
        // postconditions - list with added items
        // method input -
        // method output-
        void merge(const sortedList<Type>& otherList);
        
        // method - function removeDuplicates
        // description - remove the duplicate items from linked list
        // preconditions - 
        // postconditions - list with out any duplicate item 
        // method input -
        // method output-
        void removeDuplicates();
        
        // method - copy constructor
        // description - makes the copy of otherlinkedlist 
        // preconditions - 
        // postconditions - makes the deep copy 
        // method input -
        // method output-
        sortedList(const sortedList<Type>& otherList);
        
        
        //method - destructor
        //description- Deletes all the nodes from the list.
        //Postcondition: The list object is destroyed.
        // method input -none
        // method output-none
        ~sortedList();
        
        
        
    protected:
        nodeType<Type> *first;     //pointer to the first node of the list
        int count;                  //variable to store the number of 
                                    //elements in the list
        orderFormat format;
        
    private:
       //method: copyList
      //description: Function to make a copy of otherList.
      //Postcondition: A copy of otherList is created and
      //               assigned to this list.
       void copyList(const sortedList<Type>& otherList); 
    };
    
    template <class Type>
    sortedList<Type>::sortedList()
    {
        first=NULL;
        count = 0;
        format=ASCENDING;
    }
    
    
    template<class Type> 
    bool sortedList<Type>::isEmptyList()const
    {
        return (first == NULL);
        
    }
         
    
    
    template<class Type>
    sortedList<Type>::sortedList(orderFormat f)
    {     
        format=f;
        first=NULL;
        count=0;
    
    }
    
    
    template<class Type>
    void sortedList<Type>::setOrder(orderFormat f)
    {
        format=f;
        if(f==ASCENDING)
            Ascending();
        else
            Descending();
    }
    
    
    template <class Type>
    void sortedList<Type>::destroyList()
    {
        nodeType<Type>*temp;
        while(first!=NULL)
        {
            temp=first;
            first=first->link;
            delete temp;
            
        }
        count=0;
    }
    
      
    template <class Type>
    void sortedList<Type>::initializeList()
    {
        destroyList();
    }
    
    template <class Type>
    void sortedList<Type>::copyList(const sortedList<Type>& otherList)
    {  
        nodeType<Type> *newNode;
        nodeType<Type> *current;
        
        if(first !=NULL)
            destroyList();
        if(otherList.first==NULL)
        {
            first=NULL;
            count=0;
        }
        
        else
        {
            current =otherList.first;
            count=otherList.count;
            first =new nodeType<Type>;
            assert(first!=NULL);
            first->info=current->info;
            first->link=NULL;
            nodeType<Type> *last =first;
            current=current->link;
            //count=0;
            while(current!=NULL)
            {
                newNode=new nodeType<Type>;
                
                assert(newNode!=NULL);
                newNode->info=current->info;
                newNode->link=NULL;
                last->link = newNode;
                last=newNode;
                current=current->link;
                //count++;
            }
        }
    }
    
    
     template <class Type>
     const Type& sortedList<Type>::operator[](int num) const 
     {
        if( num < 0 || num >=length() )
        {
            throw out_of_range("out of range:NULL List");
            
        }
        nodeType<Type> *tmp;
        tmp=first;       //set the tmp to point the first node in the sortedlist
        int counter=0;
        while(tmp != NULL)
        {
           if(counter==num)
           {
                return tmp->info;
           }
           
           counter++;
           tmp= tmp->link;
        }
       
        return tmp->info;
    }
    
     template <class Type>
    void sortedList<Type>::insertItem(const Type& newItem)  
    {
            nodeType<Type> *tmp;
            tmp=new nodeType<Type>;
            assert(tmp!=NULL);
            tmp->info=newItem;
            tmp->link=first;
            first=tmp;
            count++;
            if(format == ASCENDING)
            {   Ascending();
        
            }
            else if( format==DESCENDING)
                Descending();
        

        
    }
    
    template<class Type>
    void sortedList<Type>::Ascending()
    {   
        nodeType<Type> *current=first;
        int counter=0;
        while(current!=NULL)
        {
            
            counter++;
            current=current->link;
        }
       
        for(int i=counter ; i > 1 ; i--)
        {
             
            nodeType<Type> *tmp, *tmp1;
            tmp1=first;
            for(int j=0 ; j<counter-1;j++)
            {
                
                if(tmp1->info > tmp1->link->info)
                {
                    
                    nodeType<Type> *tmp2=tmp1->link;
                    tmp1->link=tmp2->link;
                    tmp2->link=tmp1;
                    if(tmp1==first)
                    {
                        first=tmp2;
                        tmp1=tmp2;
                        
                    }
                    else
                    {
                        tmp1=tmp2;
                        tmp->link=tmp2;
                    }
                }
                tmp=tmp1;
                tmp1=tmp1->link;
               
            }
        }
    }
    
    template<class Type>
    void sortedList<Type>::Reverse()
    {
        nodeType<Type> *current=first;
        nodeType<Type> *prev=NULL, *next=NULL;
        while(current !=NULL)
        {
            next=current->link;
            current->link=prev;
            prev=current;
            current=next;
            
        }
        first=prev;
    }
    
    template<class Type>
    void sortedList<Type>::Descending()
    {
        nodeType<Type> *current=first;
        int counter=0;
        while(current!=NULL)
        {
            
            counter++;
            current=current->link;
        }
       
        for(int i=counter ; i > 1 ; i--)
        {
            nodeType<Type> *tmp, *tmp1;
            tmp1=first;
            for(int j=0 ; j<counter-1;j++)
            {
                
                if(tmp1->info < tmp1->link->info)
                {
                    
                    nodeType<Type> *tmp2=tmp1->link;
                    tmp1->link=tmp2->link;
                    tmp2->link=tmp1;
                    if(tmp1==first)
                    {
                        first=tmp2;
                        tmp1=tmp2;
                        
                    }
                    else
                    {
                        tmp1=tmp2;
                        tmp->link=tmp2;
                    }
                }
                tmp=tmp1;
                tmp1=tmp1->link;
               
            }
        }
    }
    
    template <class Type>
    Type& sortedList<Type>::valueAt(int num)
    { 
         if( num < 0 || num >=length() )
        {
            throw out_of_range("out of range:NULL List");
            
        }
        nodeType<Type> *tmp;
        tmp=first;       //set the tmp to point the first node in the sortedlist
        int counter=0;
        while(tmp != NULL)
        {
           if(counter==num)
               return tmp->info;
           counter++;
           tmp= tmp->link;
        }
       
        return tmp->info;
        
        
        
    }
    
    
    template<class Type>
    bool sortedList<Type>::inList(const Type& item) const
    {   //cerr<<"IN inlist"<<endl;
        nodeType<Type> *curr;
        bool found=false;
        curr=first;
        while (curr!=NULL && !found)
        {
            if(curr->info==item)
                found=true;
            else
                curr=curr->link;
        }
        return found;
    }
    
    
    template<class Type>
    void sortedList<Type>::traverse(void (*f) (Type&))
    {
        //f=first;
        for (int i=0 ;i<count; i++)
        {
            f(valueAt(i));
            
            
        }
    }
    
    template<class Type>
    void sortedList<Type>::deleteItem(const Type& deleteItem)
    {
        nodeType<Type> *current; //pointer to traverse the list
        nodeType<Type> *trailCurrent; //pointer just before current
        bool found;

       
        if(inList(deleteItem)==false)
        {
            throw logic_error("deleteItem failed, Item not in list");
        }
        
         if(first==NULL )
            throw out_of_range("out of range: Null List");
        else
        {
            if(first->info==deleteItem)
            {
                current=first;
                first=first->link;
                count--;
                if(first==NULL)
                    count=0;
                delete current;
            }
            else
            {
                trailCurrent = first;  //set trailCurrent to point
                                       //to the first node
                current = first->link; //set current to point to 
                                       //the second node

                while (current != NULL && !found)
                {
                    if (current->info != deleteItem) 
                    {
                        trailCurrent = current;
                        current = current-> link;
                    }
                    else
                        found = true;
                } 
                
                 if (found) //Case 3; if found, delete the node
                {
                    trailCurrent->link = current->link; 
                    count--;
                    delete current;  //delete the node from the list
                }
            
            }
        }
    }
        
    template<class Type>
    void sortedList<Type>::deleteAll(const Type& deleteItem)
    {
        if(inList(deleteItem)==false)
        {
            throw logic_error("deleteAll failed, Item not in list");
        }
        
        nodeType<Type> *current; //pointer to traverse the list
        nodeType<Type> *trailCurrent; //pointer just before current
        current=first;
        if(first==NULL)
            throw out_of_range("out of range:Null List");

        
       else
       {
            while(current->info!=deleteItem)
            {
                trailCurrent=current;
                current=current->link;
            }
            while(current->info ==deleteItem)
            {
                trailCurrent->link=current->link;
                delete current;
                current=trailCurrent->link;
                count--; 
            }
            
            
       }
        
    }
    
    
     template <class Type>
     int sortedList<Type>::length() const 
     {
         return count;
    }
    
    template<class Type>
    void sortedList<Type>::merge(const sortedList<Type>& otherList)
    {       
       nodeType<Type> * current=otherList.first;
       int counter=0;
       while(counter != otherList.length() || current!=NULL)
       {
           insertItem(current->info);
           current=current->link;
           counter++;
           
        }
       
    }
    
    template<class Type>
    void sortedList<Type>::removeDuplicates()
    {
        nodeType<Type> * current=first;
        nodeType<Type> * next;
        if(current == NULL)
            throw out_of_range("out of range: NULL list");
        while(current-> link != NULL)
        {
            if(current->info == current->link->info)
            {
                next=current->link->link;
                delete current->link;
                current->link=next;
                count--;
            }
            else
            {
                current=current->link;
            }
        }
        
    }
    
    
    template <class Type>
    sortedList<Type>::~sortedList()
    {
        destroyList();
    }
    
    
    template <class Type>
    sortedList<Type>::sortedList(const sortedList<Type>& otherList)
    {
        first=NULL;
        copyList(otherList);
    }
    
    template<class Type>
    const sortedList<Type>&sortedList<Type>::operator=(const sortedList<Type>& otherList)
    {
        if(this!=&otherList)
        {
            copyList(otherList);

        }
        return *this;

    }
}

#endif
