#include "Results.h"
#include "Courses.h"
#include "Students.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

Result::Result()
{
	counter = 0;

	c = new course[8];
	s = new Student[100];

	marks = new int* [20];

	for (int i = 0; i < 20; i++)
		marks[i] = new int[8];

	gpa = new double* [20];

	for (int i = 0; i < 20; i++)
		gpa[i] = new double[8];

	grades = new char* [20];

	for (int i = 0; i < 20; i++)
		grades[i] = new char[8];

	setStudents();
	setCourses();
	setMarks();
}

void Result::setStudents()
{
	char rollno[15], name[30], dob[20], fname[20], add[40], phone[20], stype[15];
	int batch, gradyear, REG;

	ifstream in;
	in.open("students.txt");

	while (in.good())
	{
		in.seekg(121 * counter);
		in.get(rollno, 10);
		in.seekg(121 * counter + 10);
		in.get(name, 26);
		in.seekg(121 * counter + 35);
		in.get(dob, 12);
		in.seekg(121 * counter + 47);
		in.get(fname, 13);
		in.seekg(121 * counter + 59);
		in.get(add, 31);
		in.seekg(121 * counter + 89);
		in.get(phone, 11);
		in.seekg(121 * counter + 99);
		in.get(stype, 8);
		in.seekg(121 * counter + 106);
		in >> batch >> gradyear >> REG;

		s[counter].setRollNo(rollno);
		s[counter].setName(name);
		s[counter].setDOB(dob);
		s[counter].setFatherName(fname);
		s[counter].setAddress(add);
		s[counter].setSemType(stype);
		s[counter].setPhone(phone);
		s[counter].setBatch(batch);
		s[counter].setGradYear(gradyear);
		s[counter].setRegNo(REG);

		counter++;
	}

	in.close();
}

void Result::setCourses()
{
	char code[10], name[35], semtype[10];
	int ch, s;

	int i = 0;

	ifstream in;
	in.open("courses.txt");

	while (in.good())
	{
		in.seekg(51 * i);
		in.get(code, 6);
		in.seekg(51 * i + 6);
		in.get(name, 29);
		in.seekg(51 * i + 35);
		in.get(semtype, 9);
		in.seekg(51 * i + 43);
		in >> ch >> s;

		c[i].setCode(code);
		c[i].setCourseName(name);
		c[i].setSemesterType(semtype);
		c[i].setSemester(s);
		c[i].setCreditHours(ch);
		i++;
	}

	in.close();
}

void Result::setMarks()
{
	double a1[8], a2;
	int c = 0;

	ifstream in;
	in.open("results.txt");

	while (in.good())
	{
		for (int i = 0; i < 8; i++)
			in >> a1[i];

		if (c != counter)
			for (int j = 0; j < 8; j++)
			{
				a2 = a1[j];
				marks[c][j] = a2;
			}
		else
			break;

		c++;
	}

	in.close();

	setGrades();
}

void Result::setGrades()
{
	char g;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			g = grade(marks[i][j]);
			grades[i][j] = g;
		}
	}
	calGPA();
}
void Result::calGPA()
{
	double totalcal = 0.0, totalcredit = 0.0;
	int credit = 1, cal = 1;
	int g1;

	for (int i = 0; i < 20; i++)
	{
		totalcal = 0.0; totalcredit = 0.0; credit = 1; cal = 1;

		for (int j = 0; j < 8; j++)
		{
			if (marks[i][j] != 0)
			{
				credit = c[j].getCreditHours();
				if (grades[i][j] == 'A')
					cal = credit * 4;
				else if (grades[i][j] == 'B')
					cal = credit * 3;
				else if (grades[i][j] == 'C')
					cal = credit * 2;
				else if (grades[i][j] == 'D')
					cal = credit * 1;
				else if (grades[i][j] == 'F')
					cal = credit * 0;

				totalcredit = totalcredit + credit;
				totalcal = totalcal + cal;
				gpa[i][j] = totalcal / totalcredit;

			}
			else
				gpa[i][j] = 0;
		}
	}
}
char Result::grade(int m)
{
	if (m == 0)
		return 'I';
	else if (m > 0 && m < 50)
		return 'F';
	else if (m >= 50 && m <= 60)
		return 'D';
	else if (m > 60 && m <= 70)
		return 'C';
	else if (m > 70 && m <= 80)
		return 'B';
	else if (m > 80 && m < 100)
		return 'A';
}
void Result::search()
{
	int i;
	string a, r;

	cout << "\n Enter the roll number of student you want to search " << endl;
	cout << " ________________________________________________________" << endl;
	cout << "\n Please enter the roll number: ";
	cin.ignore();
	getline(cin, a);

	for (i = 0; i < counter; i++)
	{
		r = s[i].getRollNo();

		if (a.compare(r) == 0)
		{
			cout << " ________________________________________________________________________________________________________________________" << endl;
			cout << "\n The details of the student are: \n" << endl;

			cout << left << setw(11) << " Roll No";
			cout << left << setw(25) << " Student name";
			cout << left << setw(12) << "    DOB";
			cout << left << setw(12) << " Father";
			cout << left << setw(30) << "         Address";
			cout << left << setw(10) << " Phone#";
			cout << left << setw(7) << " F/S/G";
			cout << left << setw(3) << " B";
			cout << left << setw(4) << " GY";
			cout << left << setw(7) << " Reg#" << endl;
			cout << " ________________________________________________________________________________________________________________________" << endl;
			s[i].print();
			cout << "\n\n";
			break;
		}
	}

	if (i == counter)
	{
		cout << "\n The entered student details do not exist in University's records." << endl;
		cout << "\n\n";
	}
}

void Result::studentsDetail()
{
	cout << "\n The Personal Details of all the students of the university are:\n " << endl;
	cout << left << setw(11) << " Roll No";
	cout << left << setw(25) << " Student name";
	cout << left << setw(12) << "    DOB";
	cout << left << setw(12) << " Father";
	cout << left << setw(30) << "         Address";
	cout << left << setw(10) << " Phone#";
	cout << left << setw(7) << " F/S/G";
	cout << left << setw(3) << " B";
	cout << left << setw(4) << " GY";
	cout << left << setw(7) << " Reg#" << endl;
	cout << " ________________________________________________________________________________________________________________________" << endl;

	for (int i = 0; i < counter; i++)
	{
		s[i].print();
		cout << endl;
	}

	cout << "\n\n";
}

void Result::coursesDetail()
{
	cout << left << setw(7) << "\n Code" << setw(29) << "  Course Title";
	cout << left << setw(8) << "  F/S" << setw(4) << "  CH" << setw(4) << "  S" << endl;
	cout << " ___________________________________________________" << endl;
	for (int i = 0; i < 8; i++)
	{
		c[i].print();
		cout << endl;
	}

	string a, r;
	cout << "\n\n Enter the code of the course of which you want details about: ";
	cin.ignore();
	getline(cin, a);

	int index, j;
	for (j = 0; j < 8; j++)
	{
		r = c[j].getCode();

		if (a.compare(r) == 0)
		{
			index = j;
			break;
		}
	}

	//////////////////////////////////////////////////////////

	if (j != 8)
	{
		system("CLS");

		cout << "\n Printing details..." << endl;
		cout << "____________________________________________________________" << endl;
		cout << "\n";
		cout << " Course Code: " << c[index].getCode();
		cout << "\t\t\t" << "    Credit Hours: " << c[index].getCreditHours() << endl;
		cout << " Course Title: " << c[index].getCourseName() << endl;
		cout << "\n ";
		cout << left << setw(5) << "Sr#" << setw(12) << "Roll No" << setw(25) << "Student Name";
		cout << left << setw(7) << "Points" << setw(7) << "Grades" << endl;

		int j1 = 1;
		int larg = marks[0][index];
		int small = INT_MAX;
		int sum = 0;
		double avg = 1;

		for (int i1 = 0; i1 < counter; i1++)
		{
			if (marks[i1][index] != 0)
			{
				cout << " ";
				cout << left << setw(5) << j1;
				cout << left << setw(12) << s[i1].getRollNo();
				cout << left << setw(25) << s[i1].getName();
				cout << left << setw(7) << marks[i1][index];
				cout << left << setw(7) << grades[i1][index];
				cout << endl;

				j1++;

				if (marks[i1][index] >= larg)
					larg = marks[i1][index];
				if (marks[i1][index] <= small)
					small = marks[i1][index];

				sum = sum + marks[i1][index];
			}
		}

		if (j1 > 1)
		{
			avg = sum / (j1 - 1);

			cout << "\n";
			cout << "\t\t\tMaximum: " << larg << endl;
			cout << "\t\t\tMinimum: " << small << endl;
			cout << "\t\t\tAverage: " << avg << endl;
			cout << "____________________________________________________________" << endl;
		}
		else
		{
			cout << "\n";
			cout << "\t\t\tMaximum: 0" << endl;
			cout << "\t\t\tMinimum: 0" << endl;
			cout << "\t\t\tAverage: 0" << endl;
			cout << "____________________________________________________________" << endl;
		}
	}
	else
	{
		cout << "\n You entered a wrong entry.\n" << endl;
	}
}

void Result::GPLimit()
{
	cout << left << setw(7) << " Code" << setw(29) << " Course Title";
	cout << left << setw(8) << " F/S" << setw(4) << " CH" << setw(4) << " S" << endl;
	cout << " ___________________________________________________" << endl;
	for (int i = 0; i < 8; i++)
	{
		c[i].print();
		cout << endl;
	}

	int G;
	string a, r;

	cout << "\n\n Enter the code of the course of which you want details about: ";
	cin.ignore();
	getline(cin, a);

	cout << " Enter the points limit: ";
	cin >> G;

	int index, j;

	for (j = 0; j < 8; j++)
	{
		r = c[j].getCode();

		if (a.compare(r) == 0)
		{
			index = j;
			break;
		}
	}

	//////////////////////////////////////////////////////////

	if (j != 8)
	{
		system("CLS");
		cout << "\n Printing details..." << endl;
		cout << "____________________________________________________________" << endl;
		cout << "\n";
		cout << " Course Code: " << c[index].getCode();
		cout << "\t\t\t" << "    Credit Hours: " << c[index].getCreditHours() << endl;
		cout << " Course Title: " << c[index].getCourseName() << endl;
		cout << " Grade point limit: " << G << endl;
		cout << "\n ";
		cout << left << setw(5) << "Sr#" << setw(12) << "Roll No" << setw(25) << "Student Name";
		cout << left << setw(7) << "Points" << setw(7) << "Grades" << endl;

		int j1 = 1;
		int larg = marks[0][index];
		int small = INT_MAX;
		int sum = 0;
		double avg = 1;

		for (int i1 = 0; i1 < counter; i1++)
		{
			if (marks[i1][index] >= G)
			{
				cout << " ";
				cout << left << setw(5) << j1;
				cout << left << setw(12) << s[i1].getRollNo();
				cout << left << setw(25) << s[i1].getName();
				cout << left << setw(7) << marks[i1][index];
				cout << left << setw(7) << grades[i1][index];
				cout << endl;
				j1++;

				if (marks[i1][index] >= larg)
					larg = marks[i1][index];
				if (marks[i1][index] <= small)
					small = marks[i1][index];

				sum = sum + marks[i1][index];
			}
		}

		if (j1 > 1)
		{
			avg = sum / (j1 - 1);
			cout << "\n";
			cout << "\t\t\tMaximum: " << larg << endl;
			cout << "\t\t\tMinimum: " << small << endl;
			cout << "\t\t\tAverage: " << avg << endl;
			cout << "____________________________________________________________" << endl;
		}

		else
		{
			cout << "\n";
			cout << "\t\t\tMaximum: 0" << endl;
			cout << "\t\t\tMinimum: 0" << endl;
			cout << "\t\t\tAverage: 0" << endl;
			cout << "____________________________________________________________" << endl;
		}

	}

	else
	{
		cout << " You entered a wrong entry." << endl;
	}
}

void Result::transcript()
{
	studentsDetail();
	string a, r;
	cout << " ----------------------------------------------------------------------" << endl;
	cout << " Enter the roll number of student whose details are to be displayed. " << endl;;
	cout << " Please enter in following template (BSCSXXXXX): ";
	cin.ignore();
	getline(cin, a);

	system("CLS");
	int index = 0, i3;
	for (i3 = 0; i3 < counter; i3++)
	{
		r = s[i3].getRollNo();
		if (a.compare(r) == 0)
		{
			index = i3;
			break;
		}
	}

	int credit1 = 0; double cal1 = 0;
	double totalcred = 0.0;

	if (i3 != counter)
	{
		system("CLS");
		cout << "\n ----------------------------------------------------------------------------" << endl;
		cout << "\t\t\t\tTranscript" << endl;
		cout << " ----------------------------------------------------------------------------" << endl;
		cout << " Student name: ";
		cout << left << setw(25) << s[index].getName();
		cout << "\t Roll No: ";
		cout << left << setw(12) << s[index].getRollNo() << endl;
		cout << " Date of Birth: ";
		cout << left << setw(12) << s[index].getDOB();
		cout << "\t\t\t Registration Number: ";
		cout << left << setw(10) << s[index].getRegNo() << endl;
		cout << " Father's name: ";
		cout << left << setw(12) << s[index].getFatherName() << endl;
		cout << "\n";

		for (int k = 0; k < 8; k++)
		{
			if (marks[index][k] != 0)
			{
				cout << " ____________________________________________________________________________" << endl;
				credit1 = c[k].getCreditHours();
				if (grades[index][k] == 'A')
					cal1 = credit1 * 4;
				else if (grades[index][k] == 'B')
					cal1 = credit1 * 3;
				else if (grades[index][k] == 'C')
					cal1 = credit1 * 2;
				else if (grades[index][k] == 'D')
					cal1 = credit1 * 1;
				else if (grades[index][k] == 'F')
					cal1 = credit1 * 0;

				double sGPA = cal1 / credit1;
				totalcred = totalcred + credit1;

				cout << " " << left << c[k].getSemesterType() << endl;
				cout << left << setw(7) << " Code";
				cout << left << setw(29) << " Course Title";
				cout << left << setw(12) << " Credit hrs";
				cout << left << setw(10) << " Points";
				cout << left << setw(10) << " Grade" << endl;
				cout << " ";
				cout << left << setw(7) << c[k].getCode();
				cout << left << setw(29) << c[k].getCourseName();
				cout << left << setw(12) << c[k].getCreditHours();
				cout << left << setw(10) << sGPA;
				cout << left << setw(10) << grades[index][k] << endl;
				cout << left << "\n Total Credit: " << totalcred;
				cout << "\t\t\t CGPA: " << gpa[index][k] << endl;
				cout << "\t\t\t\t\t SGPA: " << sGPA << endl;
				cout << "\n";

			}
		}
	}
	else
		cout << " Invalid entry." << endl;
}

Result::~Result()
{
	for (int i = 0; i < 20; i++)
	{
		delete[] marks[i];
		delete[] grades[i];
		delete[] gpa[i];
	}

	delete[]marks;
	delete[]grades;
	delete[] gpa;
}