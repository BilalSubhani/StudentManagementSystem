#ifndef _RESULTS_H_
#define _RESULTS_H_

#include "Courses.h"
#include "Students.h"
#include <string>
using namespace std;

class Result
{
private:
	int counter;
	Student* s;
	course* c;
	char** grades;
	int** marks;
	double** gpa;
public:
	Result();
	void setStudents();
	void setCourses();
	void setGrades();
	void setMarks();
	char grade(int);
	void calGPA();
	void search();
	void studentsDetail();
	void coursesDetail();
	void GPLimit();
	void transcript();
	~Result();
};
#endif