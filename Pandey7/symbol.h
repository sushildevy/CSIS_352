#ifndef _SYMBOL_H_
#define _SYMBOL_H_

#include <string>
#include <iostream>
using namespace std;

class Symbol
{
   public:
      string getSymbol() const;
      void setSymbol(const string&);
      int getValue() const;
      void setValue(int);
      bool operator==(const Symbol&) const;
   private:
      string s;
      int value;
};

ostream& operator<<(ostream&,const Symbol&);

#endif