#include "Students.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

Student::Student()
{
	Roll_no = " ";			name = " ";
	date_of_birth = " ";	F_Name = " ";
	Address = " ";			Phone_No = " ";
	sem_type = " ";
	Uni_Reg_No = 0;			Batch = 0;
	Grad_Year = 0;
}

string Student::getRollNo()const
{
	return Roll_no;
}

string Student::getName()const
{
	return name;
}

string Student::getDOB()const
{
	return date_of_birth;
}

void Student::print()
{
	cout << " ";
	cout << left << setw(11) << Roll_no;
	cout << setw(25) << name;
	cout << setw(12) << date_of_birth;
	cout << setw(12) << F_Name;
	cout << setw(30) << Address;
	cout << setw(10) << Phone_No;
	cout << setw(7) << sem_type;
	cout << setw(3) << Batch << setw(4) << Grad_Year << setw(3) << Uni_Reg_No;
}

string Student::getFatherName()const
{
	return F_Name;
}

string Student::getAddress()const
{
	return Address;
}

string Student::getSemType()const
{
	return sem_type;
}

string Student::getPhone()const
{
	return Phone_No;
}

int Student::getRegNo()const
{
	return Uni_Reg_No;
}

int Student::getBatch()const
{
	return Batch;
}

int Student::getGradYear()const
{
	return Grad_Year;
}

void Student::setRollNo(string r)
{
	Roll_no = r;
}

void Student::setPhone(string r)
{
	Phone_No = r;
}

void Student::setName(string r)
{
	name = r;
}

void Student::setDOB(string d)
{
	date_of_birth = d;
}

void Student::setFatherName(string f)
{
	F_Name = f;
}

void Student::setAddress(string a)
{
	Address = a;
}

void Student::setSemType(string s)
{
	sem_type = s;
}

void Student::setRegNo(int r)
{
	Uni_Reg_No = r;
}

void Student::setBatch(int b)
{
	Batch = b;
}

void Student::setGradYear(int g)
{
	Grad_Year = g;
}