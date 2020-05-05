#include "struct.h"
#include <iostream>
#include <string>
#include <windows.h> 
#include<list>
#include <fstream>

using namespace std;
#define CLEAR system("cls");
#define PAUSE system("pause");

Menu Dish;
Users User;
list<Users> UserList;
list<Menu> DishList;
const string Dishes = "Dishes.txt";


//авторизація
void loginAdmin()
{

	string login;
	string passwd;
	start:
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
		goto start;
	}
}

//функціонал працівників
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
		case 2:
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
	
	int action = 0;
	do
	{
		cout << "Press - 1 to cooking " << endl;
		cout << "Press - 2 to deny" << endl;
		cout << "Press - 3 to exit" << endl;
		cout << "Enter your action>_";
		cin >> action;

		switch (action)
		{
		case 1:
			cooking();
			break;
		default:
			break;
		}
	} while (action != 3);


}

void addDishes()
{
	int value;

	cout << "How many dishes you want to add: ";
	cin >> value;

	ofstream fout;
	fout.open(Dishes, ios::app);
	bool isOpen = fout.is_open();
	if (isOpen == false) {
		cout << "Error: Application can't connecting to database file!" << endl;
	}
	else

		for (int i = 0; i < value; i++) {
			cout << "Enter dish name: ";
			cin >> Dish.dishName;

			cout << "Enter dish prise: ";
			cin >> Dish.price;
			fout << Dish.dishName << " "<< Dish.price << endl;

			DishList.push_back(Dish);
		}


	fout.close();
}

void showDishes()
{
	ifstream fin;

	fin.open(Dishes, ios::in);
	string str;
	if (!fin) {
		cout << "Cannot open file.\n";
	}
	else
	{
		while (!fin.eof())
		{
			fin >> str;
			cout << str << " $" << endl;
		}
	}

}


// фінанси
void calculateFinance()
{
}

void cooking()
{

	int time = 10;
	int i = 0;
	for (i = time; i; i--) {
		cout << "time: " << i << endl;
		Sleep(500);
	}
	cout << "You have successfully cooked" << endl;
	
}


void superAmin()
{
	CLEAR
	loginAdmin();
	int action = 0;
	do
	{
		cout << "Add dish and price press - 1" << endl;
		cout << "Show all dishes press - 2" << endl;
		cout << "Press - 3 to exit" << endl;
		cout << "Choose an action->_";
		cin >> action;
		switch (action)
		{

		case 1:
			CLEAR
			addDishes();
			break;

		case 2:
			
			showDishes();
			break;
		default:
			break;
		}


	} while (action != 3);

}

void registrarion()
{

	cout << "Enter your name: ";
	cin >> User.login;

	cout << "Enter your password: ";
	cin >> User.password;
	UserList.push_back(User);
	ofstream fout;
	string UserName = User.login;
	
	fout.open(UserName, ios::app);

	bool isOpen = fout.is_open();
	if (isOpen == false) {
		cout << "Error: Application can't connecting to database file!" << endl;
	}
	else {

		fout << User.login << endl;
		fout << User.password << endl;
	}
	fout.close();
	cout << "You successfully registered" << endl;
	PAUSE
		CLEAR
}

void login()
{
	string login, password, log, pw;
start:
	cout << "Enter your login: ";
	cin >> login;
	cout << "Enter your password: ";
	cin >> password;
	


	ifstream fin;
	
	fin.open(login, ios::in);
	if (!fin) {
		cout << "Cannot open file.\n";
	}
	else
	{
		getline(fin, log);
		getline(fin, pw);
	}
	if (login == log && password == pw) {
		cout << "Hello " << login << endl;
	}
	else
	{
		cout << "Error try again" << endl;
		goto start;
	}
	fin.close();
}

void playerInfo()
{
}