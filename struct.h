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
	products* products; // ��� ���� ����� �������� ��� ������������ ���� ������
};

struct finance {
	float money;
	

};

//����������� 
void loginStaff();
void loginAdmin();
void logCook();

//���������
void admin();
void staff();
void cooker();
void showProducts();
void showDishes();
void calculateFinance();
