
// -----------------------------------------------------------------------------
// 
// ------------------------------------ Note -----------------------------------
// 
//  1. The following code includes user defined external header files and can  
//	   only be run through a compiler like Visual Studio, etc. which supports 
//	   user defined external header files.
// 
//	2. The passwrod to run the execute the program is 70131514
// 
// -----------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <Windows.h>
#include "Students.h"
#include "Courses.h"
#include "Results.h"

using namespace std;

void MainMenu(int& z)
{
	system("CLS");

	cout << " --------------------------------------------------------" << endl;
	cout << "  Welcome To University Academic Record (UAR) System!" << endl;
	cout << " --------------------------------------------------------" << endl;
	cout << " \n\t\t\tMAIN MENU\n\n";
	cout << " --------------------------------------------------------\n";
	cout << " Press 1: To Print Personal Details of all Students." << endl;
	cout << " Press 2: To search a student." << endl;
	cout << " Press 3: To Print Course Details." << endl;
	cout << " Press 4: To Print Course Details using Points limit." << endl;
	cout << " Press 5: To Generate transcript of a student." << endl;
	cout << " Press 0: To Exit." << endl;
	cout << " --------------------------------------------------------\n\n";
	cout << " Enter the desired number to perform desired task: ";
	cin >> z;
	cout << endl;
	system("CLS");
}

/*This function is used for logging in with the help of password*/

/*
			 Note: The password is "70131514".
*/

bool passcode()
{
	string password;

	cout << "\n Enter the password to login: " << endl;

	cout << " Password: ";
	cin >> password;

	if (password == "70131514")
		return true;
	else
		return false;
}

int main()
{
	system("color F0");
	cout << "--------------------------------------------------------------" << endl;
	cout << " * Kindly maximize your console window for better experience * \n";
	cout << "--------------------------------------------------------------" << endl;

	int t = 1, ab = 3;
	while (t <= 3)
	{
		if (passcode())
		{
			system("CLS");
			break;
		}
		else
		{
			cout << "\n --------------------------------" << endl;
			cout << " Incorrect password. Try again!" << endl;
			cout << " Hint: Roll no (Use readme file on GitHub Repo). " << endl;
			cout << " Tries remaining: " << ab - t;
			cout << "\n --------------------------------" << endl;

			if (t == 3)
			{
				cout << " Incorrect password entries.\n Program terminating..." << endl;
				return 0;
			}
		}
		t++;
	}

	Result r;

	int z = 10;
	while (z != 0)
	{
		MainMenu(z);
		switch (z)
		{
		case 1:
			r.studentsDetail();
			system("pause");
			break;
		case 2:
			r.search();
			system("pause");
			break;
		case 3:
			r.coursesDetail();
			system("pause");
			break;
		case 4:
			r.GPLimit();
			system("pause");
			break;
		case 5:
			r.transcript();
			system("pause");
			break;
		default:
			break;
		}
	}

	cout << "\n\n ---------------------------------------------" << endl;
	cout << " Thank you for using UAR System Software <3 :)" << endl;
	cout << " ---------------------------------------------\n" << endl;

	return 0;
}

// -----------------------------------------------------------------------------
