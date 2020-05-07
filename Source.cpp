#include <iostream>
#include<string>
#include "struct.h"
#include <windows.h> 
#include<stdlib.h>

using namespace std;
#define CLEAR system("cls");
#define PAUSE system("pause");
#define purple SetConsoleTextAttribute(color, 5);

int main() {
	
	int action1 = 0;
	int action2 = 0;
	do
	{



	start:
	cout << "*********************************" << endl;
	cout << "|If you want register press [1] |" << endl;
	cout << "*********************************" << endl;
	cout << "|If you want sing in press  [2] |" << endl;
	cout << "*********************************" << endl;
	cout << "|Super admin menu press     [3] |" << endl;
	cout << "*********************************" << endl;
	cout << "|If you want exit press     [4] |" << endl;
	cout << "*********************************" << endl;

	cout << "Choose yhour action>_";
	cin >> action1;
	switch (action1)
	{
	case 1:
		registrarion();
		login();
		break;

	case 2:
		login();
		break;
	case 3: 
		superAmin();
		goto start;
		break;
	case 4:
		continue;
	default:
		cout << "Error try again" << endl;
		break;
	}

	CLEAR
	
	do
	{
		cout << "*********************************" << endl;
		cout << "|Press - 1 to show all statistic|" << endl;
		cout << "*********************************" << endl;
		cout << "|Press - 2 to use staff         |" << endl;
		cout << "*********************************" << endl;
		cout << "|Press - 3 to use cooker        |" << endl;
		cout << "*********************************" << endl;
		cout << "|If you want log out press - 4  |" << endl;
		cout << "*********************************" << endl;
		cout << "Enter your action->_ ";
		cin >> action2;
		
		CLEAR
		switch (action2)
		{
		case 1:
			CLEAR
			showStat();
			
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
	} while (action2 != 4);
	} while (action1 !=4);
	return 0;
}