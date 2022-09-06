#ifndef _SHOPPING_MANAGER_H_
#define _SHOPPING_MANAGER_H_

#include "Shopping.h"
#include "ClientManager.h"
#include "ProductManager.h"
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <iomanip>

#define BLACK 0
#define WHITE 15
#define LIGHTRED 12

void textcolor(int foreground, int background);

class ShoppingManager
{
public:
	void Shopping_Input(ClientManager& C_ref, ProductManager& P_ref,
		int num, string _clpk, string _prpk, int _date, int _quantatiy);
	void Shopping_Display(ClientManager& _cm, ProductManager& _pm);
	void Display();
	int getSNumber() { return Snumber; }
	void setSNumber(int _Snumber) { Snumber = _Snumber; }
	void sort();
	void Shopping_Remove(int _num);
	void Shopping_Remove_All(ClientManager& _cm);
	void Shopping_Change(int _num, ProductManager& sh_pm);
	void ShoppingListSave();
	void ShoppingListLoad();


	//���� ����Ʈ get, set �Լ�����
	int getAllPrice() { return Allprice; }
	void setAllPrice(int _price);

	//���� ����Ʈ�� ���� �� �ѱݾ� Ž�� �Լ� client->cprice->getCPrice(), shopping->getAllPrice()
	//�� �Լ��� ���� �߰� ���� ���� ��ɿ��� ��ɿ� ���� �� ����� �ֽ�ȭ �� �� �ֵ��� ����
	void FindCPrice(ClientManager& _cm);
	//main �Լ� ������ sm.FindCPrice(cm) ���� �� case���� ȣ��

	vector<string> parseCSV(istream& file, char delimiter);
private:
	vector<Shopping*> shoppingList;
	//�������� ����Ʈ �ѹ� PK�� ���� ���� ī��Ʈ ���� ����
	int S_Count = 0;
	int Snumber = 0;

	//�������� ����Ʈ�� �����Լ� ���� ���� ������
	int date; //���� ��¥�� �Է¹޾� �ش��ϴ� ��¥�� �����͸� ã��
	int quan;

	//shopping list�� pk�� ���� ã������ ������
	string pk_cl;
	string pk_pr;

	
	int Allprice;
};

#endif