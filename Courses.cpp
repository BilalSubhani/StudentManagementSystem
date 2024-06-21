#include "Courses.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

course::course()
{
	code = " ";		
	course_name = " ";
	semType = " ";
	semester = 0;	
	credit_hours = 0;
}
void course::print()
{
	cout << " ";
	cout << left << setw(7) << code;
	cout << setw(29) << course_name;
	cout << setw(8) << semType;
	cout << setw(4) << credit_hours << setw(4) << semester;
}

string course::getCode()const
{
	return code;
}

string course::getCourseName()const
{
	return course_name;
}

string course::getSemesterType()const
{
	return semType;
}

int course::getCreditHours()const
{
	return credit_hours;
}

int course::getSemester()const
{
	return semester;
}

void course::setCode(string c)
{
	code = c;
}

void course::setCourseName(string cn)
{
	course_name = cn;
}

void course::setSemesterType(string st)
{
	semType = st;
}

void course::setCreditHours(int c)
{
	credit_hours = c;
}

void course::setSemester(int s)
{
	semester = s;
}