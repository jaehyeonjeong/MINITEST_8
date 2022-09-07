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

class ProductManager : public AbstractManager
{
public:
	void Product_Input(string _id, string _name, int _price);
	void Product_Remove(string _id);
	void Product_Change(string _id);
	void Product_PK(string _id);

	//AbstracuManager 클래스의 가상함수 오버라이드
	virtual void RemoveAll() override;
	virtual void Display() override;
	virtual int Count() override { return P_Count; };
	virtual void Save() override;
	virtual void Load() override;


    vector<string> parseCSV(istream& file, char delimiter);
	vector<Product*> productList;
private:
	int P_Count = 0;
	  
	string PM_ID;
	string PM_Name;
	int PM_Price;
};


#endif