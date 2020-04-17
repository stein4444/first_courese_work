#pragma once
#include <string>
using namespace std;

struct products {
	string products;
	float productPrice;
};

struct dishes {
	string dishes;
	float dishesPrice;
	products* products; // тут буде масив продуктів для виготовлення цієї страви
};

struct finance {
	float money;
	

};

//авторизація 
void loginStaff();
void loginAdmin();
void logCook();

//фунціонал
void admin();
void staff();
void cooker();
void showProducts();
void showDishes();
void calculateFinance();
