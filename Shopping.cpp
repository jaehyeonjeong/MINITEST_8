#include "Shopping.h"

//Shopping 데이터를 get set함수로 수정 및 호출 가능하게끔 구현

int Shopping::getSNumber() const
{
	return S_Number;
}

void Shopping::setSNumber(int _number)
{
	S_Number = _number;
}

string Shopping::getSPKClient() const
{
	return PK_Client;
}

void Shopping::setSPKClient(string& _client)
{
	PK_Client = _client;
}

string Shopping::getSPKProduct() const
{
	return PK_Product;
}

void Shopping::setSPKProcut(string& _product)
{
	PK_Product = _product;
}

int Shopping::getSDate() const
{
	return S_Date;
}

void Shopping::setSDate(int _date)
{
	S_Date = _date;
}

int Shopping::getSQuan() const
{
	return S_Quan;
}

void Shopping::setSQuan(int _quan)
{
	S_Quan = _quan;
}

int Shopping::getSAllprice() const
{
	return S_Allprice;
}

bool Shopping::operator==(int date)const
{
	return(this->S_Date == date);
}

