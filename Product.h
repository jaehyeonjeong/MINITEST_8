#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <iostream>
using namespace std;

class Product
{
public:
	explicit Product(string _id = "", string _name = "", int _price = 0)			//��ǰ�� ������ �� �ʱ�ȭ
		:P_Id(_id), P_Name(_name), P_Price(_price)	
	{

	}
	string getPId() const;											//��ǰ��ID get() �Լ�
	void setPId(string& _id);										//��ǰ��ID set() �Լ�
	string getPName() const;										//��ǰ�� �̸� get() �Լ�
	void setPName(string& _name);									//��ǰ�� �̸� set() �Լ�
	int getPPrice() const;											//��ǰ�� ���� get() �Լ�
	void setPPrice(int _price);										//��ǰ�� ���� set() �Լ�
	bool operator==(string str)const;								//��ǰ�� ID�� PK�� �ΰ� �Է¹޴� str�� �� �Ͽ� bool���·� ��ȯ�ϴ� ������
private:
	//Product ������
	string P_Id;													//Product ID (Prime Key) 
	string P_Name;													//Product Name
	int P_Price;													//Product Price 
};

#endif