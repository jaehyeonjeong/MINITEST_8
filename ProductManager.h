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

class ProductManager : public AbstractManager								//AbstractManager에서 가상함수 들을 상속
{
public:
	void Product_Input(string _id, string _name, int _price);				//ProductList 입력 데이터 함수
	void Product_Remove(string _id);										//Product PK에 따른 ProductList행 제거 함수
	void Product_Change(string _id);										//Product PK에 따른 ProductList행 변경 함수
	void Product_PK(string _id) const;										//Product PK호출 함수

	//AbstracuManager 클래스의 가상함수 오버라이드
	virtual void RemoveAll() override;										//ProductList 전체 제거 함수
	virtual void Display() const override;									//ProductList 나열 함수			
	virtual int Count() const override { return P_Count; }					//ProductList 갯수 카운트 함수
	virtual void Save() const override;										//ProductList 저장 함수			
	virtual void Load() override;											//ProductList 로드 함수


    vector<string> parseCSV(istream& file, char delimiter);					//PeoductList 불러오기 중 ','을 parsing하는 함수
	vector<Product*> productList;											//ShoppingList와 상호 호환하도록 어쩔 수 없이 public으로 선언
private:
	int P_Count = 0;														//ProductList 카운트를 저장하는 변수
		
	string PM_ID;															//Product ID (PK)			
	string PM_Name;															//Product Name		
	int PM_Price;															//Product Price
};


#endif