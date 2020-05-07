#include"struct.h"
#include<iostream>
#include<string>
#include<windows.h> 
#include<list>
#include<fstream>

using namespace std;

HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
//defines
#define CLEAR system("cls");
#define PAUSE system("pause");
#define defaultClour SetConsoleTextAttribute(color, 2);
#define blue SetConsoleTextAttribute(color, 1);
#define red SetConsoleTextAttribute(color, 4);
#define purple SetConsoleTextAttribute(color, 5);
// 
Menu Dish;
Users User;
list<Menu> MenuList;
list<Users> UserList;
list<Menu> DishList;
const string Dishes = "Dishes.txt";
const string PlayerStat = "stat.txt";
const int countDish = 30;
int countDishes;
float sum = 0;
string making;
string P_Name;
//авторизація super admin
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
	CLEAR
}
//функціонал 
void staff()
{
	int number = 0;
	int action = 0;
	do
	{
		cout << "******************************************" << endl;
		cout << "|If you want creat an order press - 1    |" << endl;
		cout << "******************************************" << endl;
		cout << "|If you want calculate revenue press - 2 |" << endl;
		cout << "******************************************" << endl;
		cout << "|If you want reserve a table press - 3   |" << endl;
		cout << "******************************************" << endl;
		cout << "|Back to main menu press - 4             |" << endl;
		cout << "******************************************" << endl;
		cout << "Enter your action->_";
		cin >> action;
		switch (action)
		{
		case 1:
			cout << "Menu: " << endl;
			makeOrder();
			break;
		case 2:
			cout << "You completed " << countDishes << "orders for: " << sum << endl;

			break;
		case 3:
			cout << "Table reservation: " << endl;
			showTables();
			cout << "Enter numb of table->_";
			cin >> number;
			tables(number);
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
	CLEAR

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
			fout << Dish.dishID << " " << Dish.dishName << " " << Dish.price << endl;
			DishList.push_back(Dish);
		}


	fout.close();
	CLEAR
}

void showDishes()
{
	CLEAR
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
	CLEAR
		int time = 10;
	int i = 0;
	for (i = time; i; i--) {
		cout << "time: " << i << endl;
		Sleep(500);
	}
	cout << "You have successfully cooked: " << making << endl;

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
		CLEAR
			switch (action)
			{

			case 1:
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
// реєстрація 
void registrarion()
{
	CLEAR
	cout << " ***********************" << endl;
	cout << " |Enter your name: ";
	cin >> User.login;
	cout << " ***********************" << endl;
	cout << " |Enter your password: ";
	
	cin >> User.password;
	cout << " ***********************" << endl;
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
//вхід
void login()
{
	CLEAR
		string password, log, pw;
start:
	cout << " ***********************" << endl;
	cout << " |Enter your login:    | ";
	cin >> P_Name;
	cout << " ***********************" << endl;
	cout << " |Enter your password: | ";
	cin >> password;
	cout << " ***********************" << endl;
	int action = 0;

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
	else if (P_Name != log && password != pw)
	{
		back:
		cout << "Error try again or create new account" << endl;
		cout << "1 - try agin 2 - register" << endl;
		cout << "action->_";
		cin >> action;
		if (action == 1) {
			goto start;
		}
		else if (action == 2) {
			registrarion();
		}
		else {
			goto back;
		}

		
	}
	CLEAR
	cout << "*********" << endl;
	cout << "| Hello |  |" << P_Name<< " |" << endl;
	cout << "*********" << endl;
	fin.close();
}
//інформація 
void playerInfo()
{

	ofstream fout;
	fout.open(PlayerStat, ios::app);
	bool isOpen = fout.is_open();
	if (isOpen == false) {
		cout << "Error: Application can't connecting to database file!" << endl;
	}
	else {
		fout << P_Name << " " << sum << " " << countDishes << endl;
	}
	fout.close();

}
// створення замовлення 
void makeOrder()
{
	CLEAR
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
	countDishes++;

	playerInfo();
}

void tables(int numb)
{
	CLEAR
		blue;
	if (numb == 1) {
		red;
		cout << "You reserved table #1" << endl;
		cout << " ************" << endl;
		cout << " * table: 1 *" << endl;
		cout << " *          *" << endl;
		cout << " *          *" << endl;
		blue;
		cout << " ************" << endl;
		cout << " * table: 2 *" << endl;
		cout << " *          *" << endl;
		cout << " *          *" << endl;

		cout << " ************" << endl;
		cout << " * table: 3 *" << endl;
		cout << " *          *" << endl;
		cout << " *          *" << endl;

		cout << " ************" << endl;
		cout << " * table: 4 *" << endl;
		cout << " *          *" << endl;
		cout << " *          *" << endl;

	}

	else if (numb == 2) {

		cout << " ************" << endl;
		cout << " * table: 1 *" << endl;
		cout << " *          *" << endl;
		cout << " *          *" << endl;
		red;
		cout << "You reserved table #2" << endl;
		cout << " ************" << endl;
		cout << " * table: 2 *" << endl;
		cout << " *          *" << endl;
		cout << " *          *" << endl;
		blue;
		cout << " ************" << endl;
		cout << " * table: 3 *" << endl;
		cout << " *          *" << endl;
		cout << " *          *" << endl;

		cout << " ************" << endl;
		cout << " * table: 4 *" << endl;
		cout << " *          *" << endl;
		cout << " *          *" << endl;

	}
	if (numb == 3) {
		cout << " ************" << endl;
		cout << " * table: 1 *" << endl;
		cout << " *          *" << endl;
		cout << " *          *" << endl;

		cout << " ************" << endl;
		cout << " * table: 2 *" << endl;
		cout << " *          *" << endl;
		cout << " *          *" << endl;
		red;
		cout << "You reserved table #3" << endl;
		cout << " ************" << endl;
		cout << " * table: 3 *" << endl;
		cout << " *          *" << endl;
		cout << " *          *" << endl;
		blue;
		cout << "You reserved table #4" << endl;
		cout << " ************" << endl;
		cout << " * table: 4 *" << endl;
		cout << " *          *" << endl;
		cout << " *          *" << endl << endl << endl;
	}

	if (numb == 4) {
		cout << " ************" << endl;
		cout << " * table: 1 *" << endl;
		cout << " *          *" << endl;
		cout << " *          *" << endl;

		cout << " ************" << endl;
		cout << " * table: 2 *" << endl;
		cout << " *          *" << endl;
		cout << " *          *" << endl;

		cout << " ************" << endl;
		cout << " * table: 3 *" << endl;
		cout << " *          *" << endl;
		cout << " *          *" << endl;
		red;
		cout << "You reserved table #4" << endl;
		cout << " ************" << endl;
		cout << " * table: 4 *" << endl;
		cout << " *          *" << endl;
		cout << " *          *" << endl << endl << endl;
	}
	defaultClour;

}
//вивід інформації
void showStat()
{

	ifstream fin;
	string name;
	int count;
	int stat;
	int i = 1;
	fin.open(PlayerStat, ios::app);
	bool isOpen = fin.is_open();
	if (isOpen == false) {
		cout << "Error: Application can't connecting to database file!" << endl;
	}
	else
	{
		while (fin >> name >> stat >> count) {
			cout << "[" << i << "]" << name << " made "<< count<<" ofers for " << stat << " $"  << endl;
		}

	}

	fin.close();
}

void showTables()
{
	CLEAR
		blue;
	cout << " ************" << endl;
	cout << " * table: 1 *" << endl;
	cout << " *          *" << endl;
	cout << " *          *" << endl;

	cout << " ************" << endl;
	cout << " * table: 2 *" << endl;
	cout << " *          *" << endl;
	cout << " *          *" << endl;

	cout << " ************" << endl;
	cout << " * table: 3 *" << endl;
	cout << " *          *" << endl;
	cout << " *          *" << endl;

	cout << " ************" << endl;
	cout << " * table: 4 *" << endl;
	cout << " *          *" << endl;
	cout << " *          *" << endl;
	defaultClour;

}
