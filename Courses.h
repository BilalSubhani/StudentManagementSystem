#ifndef _COURSES_H_
#define _COURSES_H_

#include <string>
using namespace std;

class course
{
private:
	string code;
	string course_name;
	int credit_hours;
	int semester;
	string semType;
public:
	course();
	//getter
	string getCode()const;
	string getCourseName()const;
	string getSemesterType()const;
	int getCreditHours()const;
	int getSemester()const;
	//setter
	void setCode(string);
	void setCourseName(string);
	void setSemesterType(string);
	void setCreditHours(int);
	void setSemester(int);
	void print();
};

#endif