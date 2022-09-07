#ifndef _PRODUCT_MANAGER_H_
#define _PRODUCT_MANAGER_H_

#include "Product.h"
#include "AbstractManager.h"
#include <vector>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iomanip>

class ProductManager : public AbstractManager								//AbstractManager���� �����Լ� ���� ���
{
public:
	void Product_Input(string _id, string _name, int _price);				//ProductList �Է� ������ �Լ�
	void Product_Remove(string _id);										//Product PK�� ���� ProductList�� ���� �Լ�
	void Product_Change(string _id);										//Product PK�� ���� ProductList�� ���� �Լ�
	void Product_PK(string _id) const;										//Product PKȣ�� �Լ�

	//AbstracuManager Ŭ������ �����Լ� �������̵�
	virtual void RemoveAll() override;										//ProductList ��ü ���� �Լ�
	virtual void Display() const override;									//ProductList ���� �Լ�			
	virtual int Count() const override { return P_Count; }					//ProductList ���� ī��Ʈ �Լ�
	virtual void Save() const override;										//ProductList ���� �Լ�			
	virtual void Load() override;											//ProductList �ε� �Լ�


    vector<string> parseCSV(istream& file, char delimiter);					//PeoductList �ҷ����� �� ','�� parsing�ϴ� �Լ�
	vector<Product*> productList;											//ShoppingList�� ��ȣ ȣȯ�ϵ��� ��¿ �� ���� public���� ����
private:
	int P_Count = 0;														//ProductList ī��Ʈ�� �����ϴ� ����
		
	string PM_ID;															//Product ID (PK)			
	string PM_Name;															//Product Name		
	int PM_Price;															//Product Price
};


#endif