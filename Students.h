#ifndef _STUDENTS_H_
#define _STUDENTS_H_

#include <string>
using namespace std;

class Student
{
private:
	string Roll_no;
	string name;
	string date_of_birth;
	string F_Name;
	string Address;
	string Phone_No;
	int Uni_Reg_No;
	int Batch;
	int Grad_Year;
	string sem_type; // To check Fall/Spring/Graduate
public:
	Student();
	//getter
	string getRollNo()const;
	string getName()const;
	string getDOB()const;
	string getFatherName()const;
	string getAddress()const;
	string getSemType()const;
	string getPhone()const;
	int getRegNo()const;
	int getBatch()const;
	int getGradYear()const;
	//setter
	void setRollNo(string);
	void setPhone(string);
	void setName(string);
	void setDOB(string);
	void setFatherName(string);
	void setAddress(string);
	void setSemType(string);
	void setRegNo(int);
	void setBatch(int);
	void setGradYear(int);
	void print();
};

#endif