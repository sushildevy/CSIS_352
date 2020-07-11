// File:    date.h
// Author:  Sushil Pandey
// Program: Assignment6
// Date:    04/25/2019

//Description: This file contains implementation of the Date class

#include "date.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

namespace DateNameSpace{
    
outOrderFormat Date :: orderF=MiddleEndian;
outDelimeterFormat Date::delimeterF=Slash;
outMonthFormat Date::monthF=Numeric;
outDayFormat Date::dayF=NoWeekday;
Arithmetic_F Date::aF=Days;
bool leapyear(int);
string txtDay;
const int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
istream& operator >>(istream& in,Date& d)
{
    int m,dy,y;
    char dummy;
    in >> m;
    in>>dummy;
    in>>dy;
    in>>dummy;
    in>>y;
    
    if(in.fail())
    {
        in.clear();
        in.ignore(1000, '\n');
        throw ios_base::failure("input stream failure: iostream error");
    }
    d.setDate(m,dy,y);
    return in;
}


ostream& operator <<(ostream& o,const Date& d)
{
   string output;
   
   if (d.orderF==MiddleEndian)
   {
       output= d.getWeekDay() + d.getMonthName()+d.getDelimeter()+ to_string(d.getDay())+d.getDelimeter()+to_string(d.getYear());
       if(d.monthF==Text)
       {
           output=d.getWeekDay()+ d.getMonthName()+" "+to_string(d.getDay())+", "+ to_string(d.getYear());
    }
       
        
    }
     if(d.orderF==LittleEndian)
    {
        output= d.getWeekDay()+ to_string(d.getDay())+ d.getDelimeter()+d.getMonthName()+d.getDelimeter()+ to_string(d.getYear());
        if(d.monthF==Text)
        {
            output=d.getWeekDay()+ to_string(d.getDay()) +" "+ d.getMonthName()+", "+ to_string(d.getYear());
        }
    }
    if(d.orderF==BigEndian)
    {
        output= to_string(d.getYear()) +d.getDelimeter()+ d.getMonthName()+d.getDelimeter()+to_string(d.getDay()) ;
        if(d.monthF==Text)
        {
            output=d.getWeekDay() + to_string(d.getYear()) +" " + d.getMonthName() + to_string(d.getDay());
        }
    
    }
    
    
    o<<output;
    return o;
}

bool leapyear(int year)
{
   return year % 400 == 0 || (year % 4 == 0 && year % 100) != 0;
}

Date:: Date()
{
    setToday();
    
}

void Date::setToday()
{
   
    int tmpMonth;
    int tmpDay;
    int tmpYear;
    tm *current;
    time_t lt;
    lt = time(0);
    current = localtime(&lt);
    tmpYear = current->tm_year + 1900;
    tmpMonth = current->tm_mon+1;
    tmpDay = current->tm_mday;
    
    
    
    
     setDate(tmpMonth,tmpDay,tmpYear);
    
   
}

Date::Date(int month,int day,int year)
{
    setDate(month,day,year);
}

void Date::setDate(int m,int d, int yr)
{
    if(((m==2) && (((yr % 4 ==0) && (yr%100 ==0)) || (yr % 400 == 0)) && (d>=1 && d<=29)) ||((m==2) &&( d>=1 && d <=28) ) ||  
     ((m ==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) && (d>= 1 && d<=31)) || 
     ((m ==4 || m== 6 || m==9 || m==11) && (d>=1 && d<=30)))
    {
        month=m;
        day=d;
        year=yr;
    }
    else
    {
        if(m>12 || m<1)
        {
            setToday();
            throw DateException("DateException: invalid month, month = "+to_string(m)+" d1 is still "+to_string(getMonth())+"/"+to_string(getDay())+"/"+to_string(getYear()));
            
            
        }
        else if(((m==2) && ((yr % 4 ==0 && yr%100 ==0) || (yr % 400 == 0)) && (d<1 || d>29)) ||((m==2) && (d<1 || d>28)) || ((m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)&& (d<1 || d>31)) || ((m==4 || m== 6 || m==9) && (d<1 || d>30)))
        {
            setToday();
           throw DateException("DateException: invalid day, month= "+to_string(m)+" day= "+to_string(d)+" d1 is still "+to_string(getMonth())+"/"+to_string(getDay())+"/"+to_string(getYear()));
           
        
           //setToday();
  
        }
    }
        
}

int Date::getMonth() const
   {
	  return month;
   }

int Date::getDay() const
{
    return day;
}

int Date::getYear() const
{
    return year;
}

void Date::outputFormat(outOrderFormat oF)
{
    orderF=oF;  
    
}

void Date::outputFormat(outDelimeterFormat dF)
{
    delimeterF=dF;
}


void Date::outputFormat(outMonthFormat mF)
{
    monthF=mF;
}

void Date::outputFormat(outDayFormat dyF)
{
    dayF=dyF;
}

void Date::Arithmetic(Arithmetic_F F)
{
    aF=F;
}
string Date::getDelimeter() const
{
   
    string delimeterSign;
    switch(delimeterF)
    {
        
        case Dash: 
                    delimeterSign= "-";break;
        case Space:
                    delimeterSign= " ";break;
        case Slash:
                    delimeterSign= "/";break;
        
    }
    return delimeterSign;
}

string Date::getMonthName() const
{  
   string monthName;
   switch (monthF)
   {
       
       case Text:if(getMonth()==1)
                    monthName="January";
                else if(getMonth()==2)
                    monthName="February";
                else if(getMonth()==3)
                    monthName="March";
                else if(getMonth()==4)
                    monthName="April";
                else if(getMonth()==5)
                    monthName="May";
                else if(getMonth()==6)
                    monthName="June";
                else if(getMonth()==7)
                    monthName="July";
                else if(getMonth()==8)
                    monthName="August";
                else if(getMonth()==9)
                    monthName="September";
                else if(getMonth()==10)
                    monthName="October";
                else if(getMonth()==11)
                    monthName="November";
                else if(getMonth()==12)
                    monthName="December";
                break;
       case Numeric:monthName=to_string(getMonth());
       break;
    }
    
    return monthName;
}
string Date::getWeekDay() const
{
    string txtD="";
    int centuries;
    int months;
    int dayofweek=0;
    centuries = (3-year/100%4)*2;
    switch (month)
    {
        case 1  : if (leapyear(year))
                    months = 6;
                    else
                    months = 0; 
                    break;
        case 2  : if (leapyear(year))
                    months = 2;
                    else
                    months = 3; 
                    break;
        case 3  : months = 3; break;
        case 4  : months = 6; break;
        case 5  : months = 1; break;
        case 6  : months = 4; break;
        case 7  : months = 6; break;
        case 8  : months = 2; break;
        case 9  : months = 5; break;
        case 10 : months = 0; break;
        case 11 : months = 3; break;
        case 12 : months = 5; break;
    }
    dayofweek = (centuries+year%100+year%100/4+months+day)%7;
    switch (dayofweek)
    {
        case 0 : txtDay="Sunday, "; break;
        case 1 : txtDay="Monday, "; break;
        case 2 : txtDay="Tuesday, "; break;
        case 3 : txtDay="Wednesday, "; break;
        case 4 : txtDay="Thursday, "; break;
        case 5 : txtDay="Friday, "; break;
        case 6 : txtDay="Saturday, "; break;
    }
    switch(dayF)
    {
        case Weekday:txtD=txtDay;break;
        case NoWeekday:txtD="";break;
    }
    

    
    return txtD;
}

string Date::getDayOfWeek() const
{
   
    //string txtD="";
    int centuries;
    int months;
    int dayofweek=0;
    centuries = (3-year/100%4)*2;
    switch (month)
    {
        case 1  : if (leapyear(year))
                    months = 6;
                    else
                    months = 0; 
                    break;
        case 2  : if (leapyear(year))
                    months = 2;
                    else
                    months = 3; 
                    break;
        case 3  : months = 3; break;
        case 4  : months = 6; break;
        case 5  : months = 1; break;
        case 6  : months = 4; break;
        case 7  : months = 6; break;
        case 8  : months = 2; break;
        case 9  : months = 5; break;
        case 10 : months = 0; break;
        case 11 : months = 3; break;
        case 12 : months = 5; break;
    }
    dayofweek = (centuries+year%100+year%100/4+months+day)%7;
    switch (dayofweek)
    {
        case 0 : txtDay="Sunday"; break;
        case 1 : txtDay="Monday"; break;
        case 2 : txtDay="Tuesday"; break;
        case 3 : txtDay="Wednesday"; break;
        case 4 : txtDay="Thursday"; break;
        case 5 : txtDay="Friday"; break;
        case 6 : txtDay="Saturday"; break;
    }
    /*switch(dayF)
    {
        case Weekday:txtD=txtDay;break;
        case NoWeekday:txtD="";break;
    }
    */
    //cerr<<"Yaha samma"<<txtDay<<endl;
    
    return txtDay;
}



Date Date::Today()
{
    Date d;
    return d;
}


bool Date::operator==(const Date& d) const
{
   return (getMonth() == d.getMonth() && getDay()== d.getDay() && getYear()== d.getYear());
}

bool Date::operator<(const Date& d) const
{
  bool res= false;
  if (getYear()< d.getYear())
      res=true;
  else if (getYear() == d.getYear())
  {
    if (getMonth ()< d.getMonth())
        res=true;
  
    else  if (getMonth() == d.getMonth())
    {
      if (getDay()<d.getDay())
	res=true;
    }
  }
  return res;
}
   

bool Date::operator<=(const Date& d) const
{
   return *this<d || *this==d;
}

bool Date::operator>(const Date& d) const
{
   return !(*this<=d);
}

bool Date::operator>=(const Date& d) const
{
   return !(*this<d);
}


bool Date::operator!=(const Date& d) const
{
   return !(*this==d);
}

const Date& Date::operator++()
{
    if(aF==Days)
    {
        if( getMonth()==2 && (getDay()==29 ))
        {
            setDate(3,1,getYear());
        }
        else if((getMonth()==2 && getDay()==28) && leapyear(getYear()) )
        {
            setDate(2,29,getYear());
        }
    
        else if(getDay()==daysInMonth[getMonth() -1])
        {
            if(getMonth()==12)
            {
               setDate(1,1,getYear()+1);
            }
            else
                setDate(getMonth()+1,1,getYear());
        }
        else
            setDate(getMonth(),getDay()+1,getYear());
    }
    if(aF==Years)
    {
        setDate(getMonth(),getDay(),getYear()-1);
    }
    return *this;
}

const Date& Date::operator--()
{
    if(aF==Days)
    {
        if(getDay()==1 && getMonth()==1 && getYear()==1)
        {
            throw DateException("DateException: date can not be decrement");
        }
        else if(getDay()==1 && getMonth()==1)
        {
            setDate(1,1,getYear()-1);
        }
        else if(getDay()==1)
        {
            if(getMonth()==3 && leapyear(getYear()))
                setDate(2,29,getYear());
            else if(getMonth()==3 )
                setDate(2,28,getYear());
            else
                setDate(getMonth()-1,daysInMonth[getMonth()-2],getYear());
        }
        
        
        else
        {
            setDate(getMonth(),getDay()-1,getYear());
        }
    }
    if(aF==Years)
    {
        if(getYear()==1)
        {
            throw DateException("DateException: years is miminum for decrement");
        }
        else
        {
            setDate(getMonth(),getDay(),getYear()-1);
        }
    }
   
    //setDate(getMonth(),getDay()-1,getYear());
    return *this;
}

Date Date::operator--(int)
{
    Date temp(getMonth(),getDay(),getYear());
    if(aF==Days)
    {
        if(getDay()==1 && getMonth()==1 && getYear()==1)
        {
            throw DateException("DateException: date can not be decrement");
        }
        else if(getDay()==1)
        {
            int monthLastDay;
            for(int i=0; i < getMonth()-1;i++ )
            {
                monthLastDay=daysInMonth[i];
            }
            setDate(getMonth()-1,monthLastDay,getYear());
        }
        else if(getDay()==1 && getMonth()==1)
        {
            setDate(1,1,getYear()-1);
        }
        
        else
        {
            setDate(getMonth(),getDay()-1,getYear());
        }
    }
    if(aF==Years)
    {
        if(getYear()==1)
        {
            throw DateException("DateException: years is miminum for decrement");
        }
        else
        {
            setDate(getMonth(),getDay(),getYear()-1);
        }
    }
   
   
    return temp;
}

Date Date::operator++(int)
{
    Date temp(getMonth(),getDay(),getYear());
    if(aF==Days)
    {
        if( getMonth()==2 && (getDay()==29 ))
        {
            setDate(3,1,getYear());
        }
        else if((getMonth()==2 && getDay()==28) && leapyear(getYear()) )
        {
            setDate(2,29,getYear());
        }
    
        else if(getDay()==daysInMonth[getMonth() -1])
        {
            day=1;
            month=getMonth()+1; 
            setDate(month,1,getYear());
        }
        else
            setDate(getMonth(),getDay()+1,getYear());
    }
    if(aF==Years)
    {
        setDate(getMonth(),getDay(),getYear()-1);
    }
    return temp;
}


/*int countLeapYears(int& y1,int& y2)
{
    int numLeapYear;
    int lp1;
    int lp2;
    lp1=y1 / 4 - y1 / 100 + y1 / 400;
    lp2=y2 / 4 - y2 / 100 + y2 / 400;
    numLeapYear=lp2-lp1;
    return numLeapYear;
}*/


int Date::operator-(const Date& d2) 
{
    long int tmpNum1;
    long int tmpNum2;
    int lp1;
    int lp2;
    int y1=getYear();
    int y2=d2.getYear();
    if(getMonth() > 2 )
    {
        lp1=y1 / 4 - y1 / 100 + y1 / 400;
   
    }
    
    if(getMonth() <=2)
    {
        lp1=(y1-1) / 4 - (y1-1) / 100 + (y1-1) / 400;
    }
    if(d2.getMonth() >2)
    {
         lp2=y2 / 4 - y2 / 100 + y2 / 400;
    }
 
    if(d2.getMonth()<=2)
    {
        lp2=(y2-1) / 4 - (y2-1) / 100 + (y2-1) / 400;
    }
    
    
    tmpNum1=y1*365 +getDay()  + lp1;
    tmpNum2=y2*365 +d2.getDay()  +lp2;
    //calululate of days in Month
    for (int i=0; i<getMonth() - 1; i++) 
        tmpNum1 += daysInMonth[i]; 
    
    for (int i=0; i<d2.getMonth() - 1; i++) 
        tmpNum2 += daysInMonth[i];
    
    
    if(aF==Days)
    {
       return(tmpNum1 - tmpNum2);
        
    }
    if(aF==Years)
    {
       return(tmpNum1 - tmpNum2)/365;
    }
    return 0;
}

Date Date::operator-(int num)
{
    Date temp(getMonth(),getDay(),getYear());
    for(int i=0; i<num; i++)
        temp--;
    return temp;
    
}

Date Date::operator+(int num)
{
   Date temp(getMonth(),getDay(),getYear());
    for(int i=0; i<num; i++)
        temp++;
    return temp;
}

const Date& Date::operator+=(int d)
{
    int day=getDay();
    int month;
    day +=d;
    if(day==daysInMonth[getMonth() -1])
    {
        day=1;
        month=getMonth()+1; 
    }
    else 
        day++;
    setDate(month,day,getYear());
    return *this;
}

const Date& Date::operator-=(int d)
{
    int day=getDay();
    int tmpDay;
    int month;
    day -=d;
    if(day < 0)
    {
        
        month=getMonth()- 1; 
        for(int i=0 ; i < month; i++)
            tmpDay=daysInMonth[i]-day;
    }
    else 
        day--;
    setDate(month,tmpDay,getYear());
    return *this;
}

int Date::daysUntil()
{
    Date w;
    Date d2(getMonth(),getDay(),w.getYear()+1);
    long int tmpNum1;
    long int tmpNum2;
    int lp1;
    int lp2;
    int y1=w.getYear();
    int y2=d2.getYear();
    if(getMonth() > 2 )
    {
        lp1=y1 / 4 - y1 / 100 + y1 / 400;
   
    }
    
    if(getMonth() <=2)
    {
        lp1=(y1-1) / 4 - (y1-1) / 100 + (y1-1) / 400;
    }
    if(d2.getMonth() >2)
    {
         lp2=y2 / 4 - y2 / 100 + y2 / 400;
    }
 
    if(d2.getMonth()<=2)
    {
        lp2=(y2-1) / 4 - (y2-1) / 100 + (y2-1) / 400;
    }
    
    
    tmpNum1=y1*365 +getDay()  + lp1;
    tmpNum2=y2*365 +d2.getDay()  +lp2;
    //calululate of days in Month
    for (int i=0; i<getMonth() - 1; i++) 
        tmpNum1 += daysInMonth[i]; 
    
    for (int i=0; i<d2.getMonth() - 1; i++) 
        tmpNum2 += daysInMonth[i];
    return (tmpNum2-tmpNum1);
}

int Date::until()
{
    Date x;
    return (*this - x);
}
}
