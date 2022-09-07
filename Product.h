#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <iostream>
using namespace std;

class Product
{
public:
	explicit Product(string _id = "", string _name = "", int _price = 0)			//상품의 데이터 값 초기화
		:P_Id(_id), P_Name(_name), P_Price(_price)	
	{

	}
	string getPId() const;											//상품의ID get() 함수
	void setPId(string& _id);										//상품의ID set() 함수
	string getPName() const;										//상품의 이름 get() 함수
	void setPName(string& _name);									//상품의 이름 set() 함수
	int getPPrice() const;											//상품의 가격 get() 함수
	void setPPrice(int _price);										//상품의 가격 set() 함수
	bool operator==(string str)const;								//상품의 ID를 PK로 두고 입력받는 str과 비교 하여 bool형태로 반환하는 연산자
private:
	//Product 데이터
	string P_Id;													//Product ID (Prime Key) 
	string P_Name;													//Product Name
	int P_Price;													//Product Price 
};

#endif