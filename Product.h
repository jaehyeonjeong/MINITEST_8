#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <iostream>
using namespace std;

class Product
{
public:
	explicit Product(string _id = "", string _name = "", int _price = 0)
		:P_Id(_id), P_Name(_name), P_Price(_price)
	{

	}
	string getPId() const;
	void setPId(string& _id);
	string getPName() const;
	void setPName(string& _name);
	int getPPrice() const;
	void setPPrice(int _price);
	bool operator==(string str)const;
private:
	string P_Id;
	string P_Name;
	int P_Price;
};

#endif