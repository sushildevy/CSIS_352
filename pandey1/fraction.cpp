// File:    fraction.cpp
// Author:  Sushil Pandey
// Program: Assignment1
// Date:    1/31/2019

//Description: This file contains implementation of the fraction class

#include "fraction.h"
#include "function.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

output_Format fraction :: format = mixed;
istream& operator >> (istream& in, fraction& f)
{
    int numer, denom;
    char dummy;
    in>>numer;
    in>>dummy;
    in>>denom;
    f.setFraction(numer,denom);
    return in;
    
}

ostream& operator << (ostream& out, const fraction& f)
{
     if(f.getFormat()==improper)
         out<<f.getNumerator()<< "/"<< f.getDenominator();
     
     else if(f.getFormat()==decimal)
         out<<f.decimalValue();
     
     else if(f.getFormat()==mixed)
     {
         int denominator=static_cast<int>(f.getDenominator());
         int numerator=static_cast<int>(f.getNumerator());
         //cout<<"numerator: "<<numerator<<"and deno: "<<denominator<<endl;
         int tmpNumer=1;
         double tmp=0;
         double tmpPrd=tmp*denominator;
         double wholeNum;
         if(numerator<0)
         {
             tmpNumer=numerator;
             numerator*=-1;
            cout<<"2nd numer: "<<numerator<<"and " <<tmpNumer<<endl;
         }
         if(numerator%denominator==0)
         {
             double tmpquotient=numerator/denominator;
             if(tmpNumer<0)
                 out << tmpquotient*-1;
             else
                 out << tmpquotient;
        }
        else
        {
            if(numerator<denominator)
            {
                if(tmpNumer<0)
                    out<<numerator*-1 << "/"<<denominator;
                else
                    out<<numerator<<"/"<<denominator;
                
            }
            else
            {
                if(numerator<0)
                {
                    tmpNumer=numerator;
                    numerator*=-1;
                }
                
                while(tmpPrd<numerator)
                {
                    tmp++;
                    tmpPrd=tmp*denominator;
                    
                }
                tmpPrd -=denominator;
                cout<<"tmp product:"<<tmpPrd<<endl;
                wholeNum=tmp-1;
                numerator -=tmpPrd;
                cout<<"Third numer:"<<numerator<<endl;
                if(tmpNumer<0)
                    {
                        wholeNum *=-1;
                        out << wholeNum<<" " << numerator << "/" << denominator;
                    }
                else
                    out<<wholeNum <<" "<< numerator << "/" <<denominator;
            }
            
               
            
            
            
        }
    }
    return out;
}


fraction ::fraction()
{
    numerator=1;
    denominator=1;
}

fraction::fraction(int numer,int denom)
{
    setNumerator(numer);
    denominator =denom;
    
}
fraction::fraction(double num)
{
    setValue(num);
    reduce();
}
void fraction::setFraction(int n,int d)
{
    setNumerator(n);
   denominator =d;
}

void fraction::setFraction(double f)
{
    setValue(f);
    reduce();
    
}
void fraction::setNumerator(int numer)
{
    numerator=numer;
}

int fraction::getNumerator() const
{
    return numerator;
}


void fraction::setDenominator(int denom)
{
  
   
    
    double tmpNumer=static_cast<double>((getNumerator() *denom))/getDenominator();
    if((floor(tmpNumer)-tmpNumer)==0)
    {
        denominator=denom;
        numerator = static_cast<int>(tmpNumer);
        
    }
    else
    {
        cout<<"invalid :"<<endl;
    }
    
}

int fraction::getDenominator() const
{
    return denominator;
}

void fraction::setValue(double num)
{
    double numer;
    double denom;
    decimalToFraction(num,numer,denom);
    //calculation(numer,denom);
    setNumerator(numer);
     denominator = denom;
    
    
}

double fraction::decimalValue() const
{
    double decimalVal;
    decimalVal=static_cast<double>(getNumerator())/static_cast<double>(getDenominator());
    return decimalVal;
}

void fraction::reduce()
{
    double numerator=getNumerator();
    double denominato=getDenominator();
    int gcd= commonFactor(numerator,denominato);
    
    while(!(gcd ==1 ))
    {
        numerator=numerator/gcd;
        denominato=denominato/gcd;
        gcd=commonFactor(numerator,denominato);
    }
    setNumerator(numerator);
    denominator = denominato;
    
}


void fraction::outputFormat(output_Format f)
{
    
    format=f;
}
output_Format fraction::getFormat() const
{
    return format;
}

fraction fraction::operator + (const fraction& f) const
{
    fraction tmpFraction(static_cast<double>(getNumerator())/static_cast<double>(getDenominator()) + static_cast<double>(f.getNumerator())/static_cast<double>(f.getDenominator()));
    return tmpFraction;
}

fraction fraction::operator - (const fraction& f) const
{
    fraction tmpFraction(static_cast<double>(getNumerator())/static_cast<double>(getDenominator()) - static_cast<double>(f.getNumerator())/static_cast<double>(f.getDenominator()));
    return tmpFraction;
}

fraction fraction::operator * (const fraction& f) const
{
   fraction tmpFraction(getNumerator()* f.getNumerator(),getDenominator()*f.getDenominator());
   return tmpFraction;
}


fraction fraction::operator / (const fraction& f) const
{
   fraction tmpFraction(getNumerator()* f.getDenominator(),getDenominator()*f.getNumerator());
   return tmpFraction;
}


bool fraction :: operator ==(const fraction& f) const
{
     return static_cast<double>(getNumerator())/static_cast<double>(getDenominator())==static_cast<double>(f.getNumerator())/static_cast<double>(f.getDenominator());
}


bool fraction::operator!=(const fraction& f) const
{
    return !(*this==f);
}

bool fraction :: operator < (const fraction& f) const
{
    return static_cast<double>(getNumerator())/static_cast<double>(getDenominator()) < static_cast<double>(f.getNumerator())/static_cast<double>(f.getDenominator()); 
}

bool fraction :: operator <= (const fraction& f) const
{
    return (*this < f) || (*this==f);
}

bool fraction :: operator > (const fraction& f) const
{
    return static_cast<double>(getNumerator())/static_cast<double>(getDenominator()) > static_cast<double>(f.getNumerator())/static_cast<double>(f.getDenominator()); 
}

bool fraction :: operator >= (const fraction& f) const
{
    return (*this > f) || (*this==f);
}

bool fraction :: operator ==(double d) const
{
    return static_cast<double>(getNumerator())/static_cast<double>(getDenominator())==d;
}

bool fraction :: operator !=(double d) const
{
     return !(*this ==d);
}

bool fraction :: operator < (double d) const
{
    return static_cast<double>(getNumerator())/static_cast<double>(getDenominator()) < d;
}

bool fraction :: operator <= (double d) const
{
    return (*this < d) || (*this == d);
}

bool fraction :: operator > (double d) const
{
    return static_cast<double>(getNumerator())/static_cast<double>(getDenominator()) > d;
}

bool fraction :: operator >=(double d ) const
{
     return (*this > d) || (*this ==d);
}


