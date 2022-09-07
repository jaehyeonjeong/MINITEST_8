#include "Product.h"

//Product 데이터를 get set함수로 수정 및 호출 가능하게끔 구현

string Product::getPId() const
{
	return P_Id;
}

void Product::setPId(string& _id)
{
	P_Id = _id;
}

string Product::getPName() const
{
	return P_Name;
}

void Product::setPName(string& _name)
{
	P_Name = _name;
}

int Product::getPPrice() const
{
	return P_Price;
}

void Product::setPPrice(int _price)
{
	P_Price = _price;
}

bool Product::operator==(string str) const
{
	return (this->P_Id == str);
}