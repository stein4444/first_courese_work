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
list<Menu> MenuList;
list<Users> UserList;
list<Menu> DishList;
const string Dishes = "Dishes.txt";
const string PlayerStat = "stat.txt";
const int countDish = 30;
float sum = 0;
string making;
string P_Name;

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

void staff()
{
	int action = 0;
	do
	{
		cout << "If you want creat an order press - 1" << endl;
		cout << "If you want calculate revenue press - 2" << endl;
		cout << "If you want reserve a table press - 3" << endl;
		cout << "Back to main menu press - 4" << endl;
		cin >> action;
		switch (action)
		{
		case 1:
			cout << "Menu: " << endl;
			makeOrder();
			break;
		case 2:
			cout << "You completed an orders for: " << sum << endl;

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
	} while (action != 4);
}

void cooker()
{
	
	int action = 0;
	do
	{
		cout << "Press - 1 to cooking " << endl;
		cout << "Press - 2 to exit" << endl;
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
	} while (action != 2);


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
			
			cout << "Enter dish id: ";
			cin >> Dish.dishID;
			fout << Dish.dishID << " "<< Dish.dishName << " " << Dish.price << endl;
			DishList.push_back(Dish);
		}


	fout.close();
}

void showDishes()
{
	int count;
	ifstream fin;
	fin.open(Dishes, ios::in);
	Menu dishInfo;
	if (!fin) {
		cout << "Cannot open file.\n";
	}
	else
	{
		int i = 0;
		while (fin >> dishInfo.dishID >> dishInfo.dishName >> dishInfo.price)
		{
			i++;
			cout << "[" << i << "]" << dishInfo.dishID << dishInfo.dishName << " - " << dishInfo.price << " $" << endl;
			dishInfo.dishID = i;
			MenuList.push_back(dishInfo);
		}
	}
	fin.close();
}

void cooking()
{

	int time = 10;
	int i = 0;
	for (i = time; i; i--) {
		cout << "time: " << i << endl;
		Sleep(500);
	}
	cout << "You have successfully cooked: "<< making << endl;
	
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
	string password, log, pw;
start:
	cout << "Enter your login: ";
	cin >> P_Name;
	cout << "Enter your password: ";
	cin >> password;
	


	ifstream fin;
	
	fin.open(P_Name, ios::in);
	if (!fin) {
		cout << "Cannot open file.\n";
	}
	else
	{
		getline(fin, log);
		getline(fin, pw);
	}
	if (P_Name == log && password == pw) {
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
	ofstream fout;
	fout.open(PlayerStat, ios:: app);
	bool isOpen = fout.is_open();
	if (isOpen == false) {
		cout << "Error: Application can't connecting to database file!" << endl;
	}
	else {
		fout << P_Name << " "<<  sum << endl;
	}
	fout.close();
	PAUSE
		CLEAR
}

void makeOrder()
{
	showDishes();
	int count;
	float price;
	cout << "Choose Dish number->_";
		cin >> count;
		for (Menu item : MenuList) {
			if (item.dishID == count) {
				cout << item.dishName << " - " << item.price << " $" << endl;
				price = item.price;
				making = item.dishName;
			}
			
		}
		
		cout << "Price: " << price << " $" << endl;
		sum += price;
		playerInfo();
	}

void tables()
{
}

void showStat()
{
	ifstream fin;
	string name;
	int stat;
	int i = 1;
	fin.open(PlayerStat, ios::app);
	bool isOpen = fin.is_open();
	if (isOpen == false) {
		cout << "Error: Application can't connecting to database file!" << endl;
	}
	else
	{
		while (fin >> name >> stat) {
			cout << "[" << i << "]" << name << " - " << stat << endl;
		}

	}

	fin.close();
}
	