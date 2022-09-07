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
#include <Windows.h>
#include <conio.h>

#define BLACK 0									//�ܼ� ���ȭ�� ��(������)
#define WHITE 15								//�ܼ� �ؽ�Ʈ��(�Ͼ��)
#define LIGHTRED 12								//�ܼ� �ؽ�Ʈ��(���� ����)

void textcolor(int foreground, int background); //�ܼ� �ؽ�Ʈ�� ���Ǻ�

class ShoppingManager
{
public:
	void Shopping_Input(ClientManager& C_ref, ProductManager& P_ref,
		int num, string _clpk, string _prpk, int _date, int _quantatiy);		//Shopping List �Է� �Լ�
	void Shopping_Display(ClientManager& _cm, ProductManager& _pm);				//Shopping List ��ȸ �Լ� -> ���� �ش�List���� PK���� ���� ���� ����
	void Display() const;														//�Ϲ� Shopping List ��ȸ �Լ� 
	int getSNumber() const { return Snumber; }									//ShoppingList PK(prime key)
	void setSNumber(int _Snumber) { Snumber = _Snumber; }						//ShoppingList PK����
	
	void sort();																//shoppinglist ������ Snumber�������� �ʱ�ȭ ����
	void Shopping_Remove(int _num);												//�ش� _num���� ���� shoppingList�� ����
	void Shopping_Remove_All(ClientManager& _cm);								// shoppingList ��ü ����
	void Shopping_Change(int _num, ClientManager& sh_cm, ProductManager& sh_pm);//�Ķ���Ϳ� ���� shoppingList ������ ���� �Լ�
	void ShoppingListSave() const;//shoppingList ���� �����Լ�
	void ShoppingListLoad();													//shoppingList ���� �ε��Լ�


	//���� ����Ʈ get, set �Լ�����
	int getAllPrice() const { return Allprice; }								//�ѱݾ� get�Լ�
	void setAllPrice(int _price);												//�ѱݾ� set�Լ�

	//���� ����Ʈ�� ���� �� �ѱݾ� Ž�� �Լ� client->cprice->getCPrice(), shopping->getAllPrice()
	//�� �Լ��� ���� �߰� ���� ���� ��ɿ��� ��ɿ� ���� �� ����� �ֽ�ȭ �� �� �ֵ��� ����
	void FindCPrice(ClientManager& _cm) const;
	//main �Լ� ������ sm.FindCPrice(cm) ���� �� case���� ȣ��

	vector<string> parseCSV(istream& file, char delimiter);
private:
	vector<Shopping*> shoppingList;
	//�������� ����Ʈ �ѹ� PK�� ���� ���� ī��Ʈ ���� ����
	int S_Count = 0;															//shoppingList �Ѱ��� ī��Ʈ
	int Snumber = 0;															//shoppingList PK

	//�������� ����Ʈ�� �����Լ� ���� ���� ������
	int date;																	//���� ��¥�� �Է¹޾� �ش��ϴ� ��¥�� �����͸� ã��
	int quan;																	//shoppingList ����

	//shopping list�� pk�� ���� ã������ ������
	string pk_cl;																//client pk
	string pk_pr;																//procut pk

	
	int Allprice;																//�� ���� shoppingList �ѱݾ� = productprice * quan; 
};


void textcolor(int foreground, int background)									//�ܼ� �ؽ�Ʈ �� ������
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);			//window���� �����ϴ� �ڵ鷯�� ���� �ؽ�Ʈ���� ������ �ٲٴ� �Լ�
}

#endif