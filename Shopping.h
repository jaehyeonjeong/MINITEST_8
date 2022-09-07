#ifndef _SHOPPING_H_
#define _SHOPPING_H_

#include <iostream>
using namespace std;

class Shopping
{
public:
	Shopping(int _snum = 0, string _cpk = "", string _ppk = "", int _date = 0, int _quan = 0, int _allprice = 0)
		:S_Number(_snum), PK_Client(_cpk), PK_Product(_ppk), S_Date(_date), S_Quan(_quan), S_Allprice(_allprice)
	{																		//shopping 데이터 초기화

	}																		//shoppingList는 shoppingManager에서 저장
	int getSNumber() const;													//shoppingList number get() 함수 : shopping PK
	void setSNumber(int _number);											//shoppingList number set() 함수
	string getSPKClient() const;											//shoppingList ClientPK get() 함수
	void setSPKClient(string& _client);										//shoppingList ClientPK set() 함수
	string getSPKProduct() const;											//shoppingLIst ProductPK get() 함수	
	void setSPKProcut(string& _product);									//shoppingList ProductPK set() 함수
	int getSDate() const;													//shoppingList Date get() 함수
	void setSDate(int _date);												//shoppingList Date set() 함수
	int getSQuan() const;													//shoppingList Quantity get() 함수
	void setSQuan(int _quan);												//shoppingList Quantity set() 함수
	int getSAllprice() const;												//shoppingList 1행의 총 금액 get() 함수
	void setSAllprice(int _allprice) { S_Allprice = _allprice; }			//shoppingList 1행의 총 금액 set() 함수

	bool operator==(int date)const;											//shoppingList의 Pk와 입력받는 int형 인자와 비교하여 bool 타입으로 반환하는 연산자
private:
	int S_Number;															//Shopping Number(Shopping List PK)
	string PK_Client;														//Client PK비교
	string PK_Product;														//Product PK비교
	int S_Date;																//ShoppingList 구매 날짜
	int S_Quan;																//Shopping List 수량
	int S_Allprice;															//Shopping List 총 금액
};

#endif