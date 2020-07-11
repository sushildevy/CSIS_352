#include "symbol.h"

string Symbol::getSymbol() const
{
   return s;
}

void Symbol::setSymbol(const string& str)
{
   s = str;
}

int Symbol::getValue() const
{
   return value;
}

void Symbol::setValue(int num)
{
   value = num;
}

bool Symbol::operator==(const Symbol& sym) const
{
   return getSymbol()==sym.getSymbol();
}

ostream& operator << (ostream& o, const Symbol& s)
{
   o << s.getSymbol() << " (" << s.getValue() << ")   ";
   return o;
}
