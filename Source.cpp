#include <iostream>
#include<string>
#include "struct.h"
#include <windows.h> 
#include<stdlib.h>

using namespace std;
#define CLEAR system("cls");
#define PAUSE system("pause");


int main() {

	int action = 0;
start:
	begin:
	
	cout << "If you want register press - 1" << endl;
	cout << "If you want sing in press - 2" << endl;
	cout << "Super admin menu press - 3 " << endl;
	cout << "action>_";
	cin >> action;
	if (action == 1) {
		registrarion();
		login();
		

	}
	else if (action == 2)
	{
		login();
		
	}
	else if (action == 3)
	{
		superAmin();
		goto begin;
	}
	else if (action < 1 || action > 3)
	{

		cout << "Error try again" << endl;
		goto start;
	}

	CLEAR
	
	do
	{
		cout << "Press - 1 to show all statistic" << endl;
		cout << "Press - 2 to use staff" << endl;
		cout << "Press - 3 to use cooker" << endl;
		cout << "If you want exit press - 5" << endl;
		cout << "Enter your action->_ ";
		cin >> action;
		
		CLEAR
		switch (action)
		{
		case 1:

			CLEAR
			break;
		case 2:
			staff();
			CLEAR
			break;
		case 3:
			cooker();
			CLEAR
			break;
		case 4: 

			
			break;
		default:
			cout << "Invalid action try to use butons from 1 - 3. Thank you!!!" << endl;
			break;
		}
	} while (action != 5);

	return 0;
}