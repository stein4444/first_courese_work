#include <iostream>
#include<string>
#include "struct.h"
#include <windows.h> 
#include<stdlib.h>

using namespace std;

int main() {

	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "Hello you use restaurant program" << endl;
	int action = 0;
	do
	{
		SetConsoleTextAttribute(color, 4);
		cout << "If you want login as administrator press - 1" << endl;
		SetConsoleTextAttribute(color, 2);
		SetConsoleTextAttribute(color, 6);
		cout << "If you want login as stuff press - 2" << endl;
		SetConsoleTextAttribute(color, 2);
		SetConsoleTextAttribute(color, 1);
		cout << "If you want login as cooker press - 3" << endl;
		SetConsoleTextAttribute(color, 2);
		SetConsoleTextAttribute(color, 5);
		cout << "If you want exit press - 4" << endl;
		SetConsoleTextAttribute(color, 2);
		SetConsoleTextAttribute(color, 7);
		cout << "Enter your action->_ ";

		cin >> action;
		SetConsoleTextAttribute(color, 2);
		system("CLS");
		switch (action)
		{
		case 1:
			loginAdmin();
			system("CLS");
			admin();
			system("CLS");
			break;
		case 2:
			loginStaff();
			system("CLS");
			staff();
			system("CLS");
			break;
		case 3:
			logCook();
			system("CLS");
			cooker();
			system("CLS");
			break;
		default:
			cout << "Invalid action try to use butons from 1 - 3. Thank you!!!" << endl;
			break;
		}
	} while (action != 4);

	



	return 0;
}