#pragma once
#include <string>
#include<windows.h>
using namespace std;


struct Menu {
	string dishName;
	float price;
	int dishID;
};

struct Users {
	string login;
	string password;
};


void loginAdmin();
void staff();
void cooker();
void addDishes();
void showDishes();
void cooking();
void superAmin();
void login();
void registrarion();
void playerInfo();
void makeOrder();
void tables(int numb);
void showStat();
void showTables();