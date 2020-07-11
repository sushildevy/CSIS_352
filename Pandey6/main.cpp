#include <iostream>
#include <fstream>
#include "person.h"
#include "employee.h"
#include "employees.h"
#include "salaryEmployee.h"
#include "hourlyEmployee.h"
#include "date.h"
#include<iomanip>


using namespace std;
using namespace DateNameSpace;

void write(Employees emp);
void read(char* filename,Employees& emp );

int main(int argc, char *argv[])
{
     Employees emp;

    ifstream readFile();
    ofstream ofs;
    string name;
    //Date bthDay;
    string SSN;
    int ID;
    string employeeCategory;
    int hourWorked;
    double wageRate;
    try
    {
        if(argc!=2)
        {
            cerr << "usage: " << argv[0] << " <inputfile> \n";

        }
        else
        {
            read(argv[1],emp);
            write(emp);
    }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    
    //getline(readFile,name);
     return 0;
}
void read(char* filename, Employees& emp)
{
    
    int ff = 1;

    string name;
    //Date bthDay;
    int day, month, year;
    char dummy;
    string SSN;
    int ID;
    string employeeCategory;
    int hourWorked;
    double wageRate;
    double salary;

    ifstream ifs;
    ifs.open(filename);
    if(ifs.fail())
    {
         throw invalid_argument("error opening inputfile:the file doesn't exist?\n");

    }
    else
    {
        while(ifs.peek()!=EOF)
        {
            if(ifs.eof())
                break;
           getline(ifs,name);
            ifs >> month;
            ifs>>dummy;
            ifs >> day;
            ifs>>dummy;
            ifs >> year;
            Date d1(month,day,year);
            
            ifs.ignore(1000,'\n');
            getline(ifs,SSN);
            ifs >> ID; 
            ifs.ignore(1000,'\n');
            getline(ifs,employeeCategory);
            if(employeeCategory=="S")
            {
                ifs >> salary;  ifs.ignore(1000,'\n');
                Employee* employee = new SalaryEmployee(name,d1,SSN,ID,salary );
                emp.addToList(employee);
               
            
            }
            else if(employeeCategory=="H")
            {
                ifs >> hourWorked; ifs.ignore(1000,'\n');
                ifs >> wageRate;  ifs.ignore(1000,'\n');
                Employee * employee=new HourlyEmployee(name,d1,SSN,ID,hourWorked,wageRate);
                emp.addToList(employee);
            } 
        }
        ifs.close();
    }
}

void write(Employees emp)
{
    ofstream ofs("payroll");
    ofstream ofs2("employees");
    ofs<<fixed<<setprecision(2);
    ofs2<<fixed<<setprecision(2);
    if(ofs.fail())
    {
        throw invalid_argument("error opening outputfile");
    }
    else
    {
        
           ofs<<setw(28)<<left<<"Name "<<setw(17)<<"Employee ID "<<setw(13)<<"Salary "<<setw(10)<<"Hours"<<setw(15)<<"wage rate "<<endl;
           Employee* e;
           for (int i=0;i<emp.length();i++)
           {
               e = emp.valueAt(i);
              ofs<<setw(25)<<left<<e->getName()<<setw(10)<<right<<e->getID()<<setw(18)<<setw(10);e->Display(ofs);ofs<<endl;
           } 

            Date::Arithmetic(Years);
           ofs2<<setw(30)<<left<<"Name "<<setw(20)<<"SSN "<<setw(20)<<"BirthDay"<<setw(10)<<"age "<<endl;
       
           for (int i=0;i<emp.length();i++)
           {
               e = emp.valueAt(i);
               ofs2<<setw(25)<<left<<e->getName()<<setw(25)<<e->getSSN()<<setw(20)<<e->getBirthDay()<<(e->getBirthDay()).until() *-1<<endl;           
           } 
            
    }
}
