#ifndef _SHOPPING_H_
#define _SHOPPING_H_

#include <iostream>
using namespace std;

class Shopping
{
public:
	Shopping(int _snum = 0, string _cpk = "", string _ppk = "", int _date = 0, int _quan = 0, int _allprice = 0)
		:S_Number(_snum), PK_Client(_cpk), PK_Product(_ppk), S_Date(_date), S_Quan(_quan), S_Allprice(_allprice)
	{																		//shopping ������ �ʱ�ȭ

	}																		//shoppingList�� shoppingManager���� ����
	int getSNumber() const;													//shoppingList number get() �Լ� : shopping PK
	void setSNumber(int _number);											//shoppingList number set() �Լ�
	string getSPKClient() const;											//shoppingList ClientPK get() �Լ�
	void setSPKClient(string& _client);										//shoppingList ClientPK set() �Լ�
	string getSPKProduct() const;											//shoppingLIst ProductPK get() �Լ�	
	void setSPKProcut(string& _product);									//shoppingList ProductPK set() �Լ�
	int getSDate() const;													//shoppingList Date get() �Լ�
	void setSDate(int _date);												//shoppingList Date set() �Լ�
	int getSQuan() const;													//shoppingList Quantity get() �Լ�
	void setSQuan(int _quan);												//shoppingList Quantity set() �Լ�
	int getSAllprice() const;												//shoppingList 1���� �� �ݾ� get() �Լ�
	void setSAllprice(int _allprice) { S_Allprice = _allprice; }			//shoppingList 1���� �� �ݾ� set() �Լ�

	bool operator==(int date)const;											//shoppingList�� Pk�� �Է¹޴� int�� ���ڿ� ���Ͽ� bool Ÿ������ ��ȯ�ϴ� ������
private:
	int S_Number;															//Shopping Number(Shopping List PK)
	string PK_Client;														//Client PK��
	string PK_Product;														//Product PK��
	int S_Date;																//ShoppingList ���� ��¥
	int S_Quan;																//Shopping List ����
	int S_Allprice;															//Shopping List �� �ݾ�
};

#endif