#pragma once
#include <string>
using namespace std;


struct Menu {
	string dishName;
	float price;
};

struct Users {
	string login;
	string password;
};

//авторизація 
void loginAdmin();

//фунціонал
void staff();
void cooker();
void addDishes();
void showDishes();
void calculateFinance();
void cooking();
void superAmin();
void login();
void registrarion();
void playerInfo();
