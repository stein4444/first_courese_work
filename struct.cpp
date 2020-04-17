#include "struct.h"
#include <iostream>
#include <string>
#include <windows.h> 
#include<stdlib.h>
using namespace std;



finance bablo;
products product;
//авторизація

void loginStaff()
{
	string login;
	string passwd;

	cout << "Enter your login: _____\b\b\b\b\b";
	cin >> login;
	cout << endl;
	cout << "Enter your password: *****\b\b\b\b\b";
	cin >> passwd;
	if (login == "staff" && passwd == "staff") {
		cout << "You successfully log in" << endl;
	}
	else
	{
		cout << "try again" << endl;
	}

}
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
void loginAdmin()
{
	
	string login;
	string passwd;
	SetConsoleTextAttribute(color, 4);
	cout << "Enter your login: _____\b\b\b\b\b";
	cin >> login;
	cout << endl;
	cout << "Enter your password: *****\b\b\b\b\b";
	cin >> passwd;
	if (login == "admin" && passwd == "admin") {
		cout << "You successfully log in" << endl;
	}
	else
	{
		cout << "try again" << endl;
	}
	SetConsoleTextAttribute(color, 2);

}

void logCook()
{
	string login;
	string passwd;
	SetConsoleTextAttribute(color, 1);
	cout << "Enter your login: ______\b\b\b\b\b\b";
	cin >> login;
	cout << endl;
	cout << "Enter your password: ******\b\b\b\b\b\b";
	cin >> passwd;
	if (login == "cooker" && passwd == "cooker") {
		cout << "You successfully log in" << endl;
	}
	else
	{
		cout << "try again" << endl;
	}
	SetConsoleTextAttribute(color, 2);

}

//функціонал працівників
void admin()
{
	
	SetConsoleTextAttribute(color, 4);
	int action = 0;
	do
	{
		cout << "Your start money = 1000$" << endl;
		cout << "If you wand to buy products press - 1" << endl;
		cout << "If you want chek press - 2" << endl;
		cout << "If you want calculate revenue press - 3" << endl;
		cout << "If you want to add money press - 4" << endl;
		cout << "Back to main menu press - 5" << endl;
		cout << "Enter your action->_ ";
		cin >> action;
		switch (action)
		{
		case 1: 
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		
		case 5: 
			cout << "By by see you later!!!" << endl;
			break;
		default:
			cout << "Invalid action try to use butons from 1 - 6. Thank you!!!" << endl;
			break;
		}

	} while (action != 5);
	SetConsoleTextAttribute(color, 2);
}

void staff()
{
	int action = 0;
	do
	{
		cout << "If you want creat an order press - 1" << endl;
		cout << "If you want calculate revenue press - 2" << endl;
		cout << "If you want reser a table press - 3" << endl;
		cout << "Back to main menu press - 4" << endl;
		cin >> action;
		switch (action)
		{
		case 1: 
			cout << "Menu: " << endl;
			break;
		case 2 :
			cout << "You completed an order for: ";

				break;
		case 3: 
			cout << "Table reservation: " << endl;
		case 4:
			cout << "By by see you later!!!" << endl;
			break;
		default:
			cout << "Invalid action try to use butons from 1 - 6. Thank you!!!" << endl;
			break;
		}
	} while (action != 3);
	
}

void cooker()
{
	



}

//продукти

void showProducts()
{
}

void showDishes()
{
}


// фінанси
void calculateFinance()
{
}

