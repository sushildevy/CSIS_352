 // File:     graph.h
// Author:   Sushil pandey
// Program: Assignment5
// Date:    04/11/2019

// Description
// This file contains the specification and implementation of ADT Graph class

#ifndef H_GRAPH_H
#define H_GRAPH_H
#include <iostream>
#include <iomanip>
#include <cassert>
#include "city.h"
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <malloc.h>


using namespace std;

enum orderWeight{WEIGHTED,UNWEIGHTED};
enum orderDirection{DIRECTED,UNDIRECTED};
//const int maxVertices=100;
template< class Type>
class Graph
{
    
    public:
        //method - default constructor
        //description-  construct constructor without argument
        //preconditions - none
        //Postcondition: Graph object created
        //method input - none; 
        //method output -none; 
        Graph();

        //method - constructor with direction and weight in order
        //description-  construct new Graph object with two arguments
        //preconditions - none
        //Postcondition - Graph object created with given size
        //method input - none; 
        //method output -none; 
        Graph(orderDirection,orderWeight);

        //method - constructor with weight and direction in order
        //description-  construct Graph object with two arguments
        //preconditions - none
        //Postcondition - Graph object created with given size
        //method input - none; 
        //method output -none; 
        Graph(orderWeight,orderDirection);

        //method - constructor with direction only
        //description-  construct new Graph object with one argument
        //preconditions - none
        //Postcondition - Graph object created
        //method input - none; 
        //method output -none; Graph(orderWeight,orderDirection);
        Graph(orderDirection);

        //method - constructor with weight only
        //description-  construct new Graph with one argument
        //preconditions - none
        //Postcondition - Graph object created
        //method input - none; 
        //method output -none; 
        Graph(orderWeight);

        //method - isEmpty
        //description- checks if the graph is empty
        //preconditions - Graph object should exist
        //Postcondition - returns true if graph empty and returns false if exits
        //method input - none; 
        //method output -none;
        bool isEmpty();

        //method - isFull
        //description- checks if the graph is emFullpty
        //preconditions - Graph object should exist
        //Postcondition - returns true if graph full and returns false if empty
        //method input - none; 
        //method output -none;
        bool isFull();

        //method - insertVertex
        //description- inserts vertex in the graph
        //preconditions - Graph object should exist
        //Postcondition - a vertex is inserted
        //method input - vertex; 
        //method output -none;
        void insertVertex(const Type&);

        //method - isEmpty
        //description- inserts edge in the graph
        //preconditions - Graph object should exist
        //Postcondition - edge is inserted
        //method input - two vertex with weight if exists; 
        //method output -none;
        void insertEdge(const Type& fromVertex, const Type& toVertx, int miles=1);

        //method - vertexCount
        //description- counts the vertices in the graph
        //preconditions - vertex in  Graph object should exist
        //Postcondition - returns vertices number if exists and throws error message otherwise
        //method input - none; 
        //method output -none;
        int vertexCount() const;

        //method - edgeCount
        //description- counts the edge of the graph
        //preconditions - vertex in  Graph object should exist
        //Postcondition - returns vertices number if exists and throws error message otherwise
        //method input - none; 
        //method output -none;
        int edgeCount() const;
        
        //method - edgeWeight
        //description- gives the weight of edge if exists
        //preconditions - edge of the graph should exist
        //Postcondition - returns edgeWeight  if edge exists and gives default 1
        //method input - none; 
        //method output -none;
        int edgeWeight(const Type&,const Type&  );

        //method - isAdjacento
        //description- checks if destination is adjacent to begin vertex
        //preconditions - vertex in  Graph object should exist
        //Postcondition - returns true if true or false otherwise
        //method input - none; 
        //method output -none;
        bool isAdjacentTo(const Type&, const Type& )  ;

     
        void toString();
        //method - dump
        //description- prints the data with good looking format
        //preconditions - data
        //Postcondition - returns vertices number if exists and throws error message otherwise
        //method input - none; 
        //method output -none;
        void dump() const;

        //method - deleteVertex
        //description- deletes the vertex
        //preconditions - vertex in  Graph object should exist
        //Postcondition - vertex is deleted and countVertex is decreased
        //method input - vertex; 
        //method output -none;
        void deleteVertex(const Type& );

        //method - deleteEdge
        //description- deletes the edge
        //preconditions - edge in  Graph object should exist
        //Postcondition - edge is deleted and countEdge is decreased
        //method input - two vertices; 
        //method output -none;
        void deleteEdge(const Type, const Type);

        //method - dustroy
        //description-  destroy the object 
        //preconditions - Graph object should exist
        //Postcondition - Graph object created
        //method input - none; 
        //method output -none;
        void destroy();
    protected:
        int countVertex; //attribute to store the number of vertices 
        int countEdge;   //attribute to store the number of edge
        orderWeight Weight; //enum object
        orderDirection Direction; //enum object
       
        
        

    private:
       int maxVertices; //maximum number of vertices possible
       vector<Type> vectorVertex; //vector container to store the vertices 
       vector<pair<int,int>> weightVector[100]; //vector with pair container to store vertex relations
        bool contains( const Type& item) const ; // private function to check if vertex exists
        int findIndex(Type item) ; //function to find the index of vertex in graph
};
  
template<class Type>
Graph<Type>::Graph()
{
    maxVertices=100;
    Weight=UNWEIGHTED;
    Direction=UNDIRECTED;
    countVertex=0;
    countEdge=0;
    
}


template<class Type>
Graph<Type>::Graph(orderWeight w,orderDirection d)
{
    maxVertices=100;
    Weight=w;
    Direction=d;
    countVertex=0;
    countEdge=0;
    
}

template<class Type>
Graph<Type>::Graph(orderDirection d, orderWeight w)
{
    maxVertices=100;
    Weight=w;
    Direction=d; 
    countVertex=0;
    countEdge=0;
  
}

template<class Type>
Graph<Type>::Graph(orderDirection d)
{
    maxVertices=100;
    Weight=UNWEIGHTED;
    Direction=d;
    countVertex=0;
    countEdge=0;
    
}

template<class Type>
Graph<Type>::Graph(orderWeight w)
{
    maxVertices=100;
    Weight=w;
    Direction=UNDIRECTED;
    countVertex=0;
    countEdge=0;
    
}

template<class Type>
bool Graph<Type>::isEmpty()
{
    return(countVertex==0);
}

template<class Type>
bool Graph<Type>::isFull()
{
    return(countVertex==maxVertices);
}

template<class Type>
bool Graph<Type>::contains(const Type& item) const
{ 
   bool found;
   Type value=item;
    typename vector<Type>::const_iterator it;
   if(find(vectorVertex.begin(),vectorVertex.end(),value)!=vectorVertex.end())
       found=true;
      
   else
       found=false;

   return found;     
}

template<class Type>
int Graph<Type>::vertexCount() const
{
    return countVertex;
}

template<class Type>
int Graph<Type>::edgeCount() const
{
    return countEdge;
}

template<class Type> 
void Graph<Type>::insertVertex(const Type& vertexItem)
{   
    if(isFull())
        throw out_of_range("list is full");
    if(contains(vertexItem))
    {
        throw out_of_range("duplicate vertex in insertVertex");
    }
    else
    {
        vectorVertex.push_back(vertexItem);
        countVertex++;  
    }
    
    
    
}

template<class Type>
void Graph<Type>::insertEdge(const Type& fromVertex,const Type& toVertex, int  miles)
{
    if(isAdjacentTo(fromVertex,toVertex))
        throw logic_error("duplicate edge in insertEdge");

    if(fromVertex==toVertex)
        throw logic_error("loops are not allowed here!! ");
    int fromIndex, toIndex;
    fromIndex=findIndex(fromVertex);
    toIndex=findIndex(toVertex);
    int tmp;
    for(auto it =weightVector[fromIndex].begin();it!=weightVector[fromIndex].end();it++)
    {
        
        tmp=it->first;
      
        if(tmp==toIndex)
           {   
                throw logic_error("Duplicate edge in insertEdge");
           }
    }
     if(Direction==DIRECTED)
     {
        weightVector[fromIndex].push_back(make_pair(toIndex,miles));
        
     }  
    else if(Direction==UNDIRECTED)
    {
        weightVector[fromIndex].push_back(make_pair(toIndex,miles));
        weightVector[toIndex].push_back(make_pair(fromIndex,miles));
        
    }
     countEdge++; 
}



template<class Type>
bool Graph<Type>::isAdjacentTo(const Type& fromVertex,const Type& toVertex)  
{
     if(!contains(fromVertex) || !contains(toVertex))
        throw logic_error("Adjacenct does not exist  ");
    int fromIndex,toIndex;
    fromIndex = findIndex(fromVertex);
    toIndex = findIndex(toVertex);
    for(auto it=weightVector[fromIndex].begin();it!=weightVector[fromIndex].end();it++)
    {
        int v = it->first;
        if(v==toIndex)
            return true;
    }
    return false;



} 

template<class Type>
int Graph<Type>::edgeWeight(const Type& fromVertex,const Type& toVertex )
{   
    if(!isAdjacentTo(fromVertex,toVertex))
    {
        throw logic_error("No adjacency between those vertices");
    }
    int fromIndex=findIndex(fromVertex);
    //int toIndex=findIndex(toVertex);
    int w; 
    if(isAdjacentTo(fromVertex,toVertex))
    {
        
        for (int u = 0; u < static_cast<int>(vertexCount()); u++) 
        { 
            for (auto it = weightVector[fromIndex].begin(); it!=weightVector[fromIndex].end(); it++) 
            { 
            w = it->second; 
                
            } 
        } 
    }
     
    return w;

}


template<class Type>
void Graph<Type>::dump() const
{
    string type;
    string weight, direction;
    if(Weight==WEIGHTED)
        weight="WEIGHTED";
    else
        weight="UNWEIGHTED";
    if(Direction==DIRECTED)
        direction="DIRECTED";
    else
        direction="UNDIRECTED";

cout<<"dumping graph"<<'\t'<<direction<<'\t'<<weight<<'\t'<<"Vertices:"<<vertexCount()<<'\t'<<"edges:"<<edgeCount()<<endl;
cout<<left<<setw(18)<<"VERTEX"<<setw(46)<<"ADJACENT VERTICES"<<endl;
cout<<left<<setw(18)<<"-----------"<<setw(20)<<"----------------------------------------------------"<<endl;
 int v, w; 
    for (int u = 0; u < static_cast<int>(vertexCount()); u++) 
    { 
        cout<<left<<setw(18)<<vectorVertex[u];
        for (auto it = weightVector[u].begin(); it!=weightVector[u].end(); it++) 
        { 
            v = it->first; 
            w = it->second; 
            if(Weight==UNWEIGHTED)
                cout<<left<<vectorVertex[v]<<"   ";
            else
            {
                cout<<left<<vectorVertex[v]<<"("<<w<<")   ";
            } 

        } 
        cout << "\n"; 
    }

    
    cout<<endl;

}
 template<class Type>
void Graph<Type>::deleteVertex(const Type& vertex)
{
    if(!contains(vertex))
        throw logic_error("non-existant vertex in deleteVertex");
    int count1=0;
    int  w =findIndex(vertex);
    for(auto p = weightVector[w].begin();p!=weightVector[w].end();p++)
    {
        count1++;
    }
    countEdge-=count1;
    
    weightVector[w].clear();  //clear weights for vertex
    typename vector<Type>::const_iterator i,v;
    for( i=vectorVertex.begin();i!=vectorVertex.end();i++)
    {
        if( *i==vertex )
            {
                v=i;
            }
    }
    vectorVertex.erase(v);   //clear vertex
    countVertex--;
    for(int u =0;u<vertexCount();u++)
        for(auto p = weightVector[u].begin();p!=weightVector[u].end();p++)
        {
            int o=p->first;
            if(o==w)
               {
                    weightVector[u].erase(p--);
                    countEdge--;
               }
        }
}   

template<class Type>
void Graph<Type>::deleteEdge(const Type fromVertex, const Type toVertex)
{
    if(!isAdjacentTo(fromVertex,toVertex))
    {
        throw logic_error("non-existant edge in deleteEdge");
    }

    int fromIndex=findIndex(fromVertex);
    int toIndex=findIndex(toVertex);
    auto it1 = weightVector[fromIndex].begin();
    int v;
    for ( auto it = weightVector[fromIndex].begin() ; it!=weightVector[fromIndex].end(); it++) 
        { 
            v = it->first; 
            if(v==toIndex)
               it1=it;
        } 
    weightVector[fromIndex].erase(it1);  //erase the edge

    if(Direction==UNDIRECTED)
    {
    auto it1 = weightVector[toIndex].begin();
    int v;
    for ( auto it = weightVector[toIndex].begin() ; it!=weightVector[toIndex].end(); it++) 
        { 
            v = it->first; 
            if(v==fromIndex)
               it1=it;
        } 
    weightVector[toIndex].erase(it1);  //erase the edge
    
    }
    countEdge--;
}

template<class Type> 
void Graph<Type>::destroy()
{
    vectorVertex.clear();
    countEdge=0;
    countVertex=0;
    for(auto it=0;it<static_cast<int>(vertexCount());it++)
    {
        weightVector[it].clear();
    }
    

}

template<class Type>
void Graph<Type>::toString() 
{
    typename vector<Type>::const_iterator x;
   cout<<"######INTOSTRING#########"<<endl;
   for(x = vectorVertex.begin();x!=vectorVertex.end();x++)
      { cout<<*x;Type t= *x;cout<<findIndex(t)<<endl;}
    cout<<"total vertices: "<<countVertex<<endl<<endl;
    int v, w; 
    for (int u = 0; u < static_cast<int>(vectorVertex.size()); u++) 
    { 
        cout <<left<<setw(12)<<vectorVertex[u];
        for (auto it = weightVector[u].begin(); it!=weightVector[u].end(); it++) 
        { 
            v = it->first; 
            w = it->second; 
            cout<<"["<<v<<","<<w<<"]   ";
           // cout<<left<<setw(20)<<vectorVertex[u]<<setw(10)<<vectorVertex[v]<<"("<<w<<")\t";
        } 
        cout << "\n"; 
    }
    cout<<"Vertices: "<<countVertex<<" Edges: "<<countEdge<<endl;

    cout<<"########################"<<endl;

} 

template<class Type>
int Graph<Type>::findIndex(Type item) 
{
    
    int index;
    for(int i =0;i<vertexCount();i++)
    {
        
        if(vectorVertex[i]==item)
            index=i;   
    }
    return index;
}
#endif
