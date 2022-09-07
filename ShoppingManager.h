#ifndef _SHOPPING_MANAGER_H_
#define _SHOPPING_MANAGER_H_

#include "Shopping.h"
#include "ClientManager.h"
#include "ProductManager.h"
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>

#define BLACK 0									//콘솔 배경화면 색(검은색)
#define WHITE 15								//콘솔 텍스트색(하얀색)
#define LIGHTRED 12								//콘솔 텍스트색(밝은 적색)

void textcolor(int foreground, int background); //콘솔 텍스트색 정의부

class ShoppingManager
{
public:
	void Shopping_Input(ClientManager& C_ref, ProductManager& P_ref,
		int num, string _clpk, string _prpk, int _date, int _quantatiy);		//Shopping List 입력 함수
	void Shopping_Display(ClientManager& _cm, ProductManager& _pm);				//Shopping List 조회 함수 -> 이후 해당List들의 PK값에 따른 정보 추출
	void Display() const;														//일반 Shopping List 조회 함수 
	int getSNumber() const { return Snumber; }									//ShoppingList PK(prime key)
	void setSNumber(int _Snumber) { Snumber = _Snumber; }						//ShoppingList PK수정
	
	void sort();																//shoppinglist 삭제후 Snumber내림차순 초기화 정렬
	void Shopping_Remove(int _num);												//해당 _num값에 따른 shoppingList행 제거
	void Shopping_Remove_All(ClientManager& _cm);								// shoppingList 전체 제거
	void Shopping_Change(int _num, ClientManager& sh_cm, ProductManager& sh_pm);//파라미터에 따른 shoppingList 데이터 변경 함수
	void ShoppingListSave() const;//shoppingList 파일 저장함수
	void ShoppingListLoad();													//shoppingList 파일 로드함수


	//구매 리스트 get, set 함수구현
	int getAllPrice() const { return Allprice; }								//총금액 get함수
	void setAllPrice(int _price);												//총금액 set함수

	//쇼핑 리스트에 따른 고객 총금액 탐지 함수 client->cprice->getCPrice(), shopping->getAllPrice()
	//이 함수는 각각 추가 제거 변경 기능에서 기능에 따른 고객 등급이 최신화 될 수 있도록 적용
	void FindCPrice(ClientManager& _cm) const;
	//main 함수 에서는 sm.FindCPrice(cm) 으로 각 case마다 호출

	vector<string> parseCSV(istream& file, char delimiter);
private:
	vector<Shopping*> shoppingList;
	//구매정보 리스트 넘버 PK와 구매 정보 카운트 저장 변수
	int S_Count = 0;															//shoppingList 총갯수 카운트
	int Snumber = 0;															//shoppingList PK

	//구매정보 리스트의 변경함수 내부 변경 데이터
	int date;																	//또한 날짜를 입력받아 해당하는 날짜에 데이터를 찾음
	int quan;																	//shoppingList 수량

	//shopping list의 pk의 값을 찾기위한 데이터
	string pk_cl;																//client pk
	string pk_pr;																//procut pk

	
	int Allprice;																//각 행의 shoppingList 총금액 = productprice * quan; 
};


void textcolor(int foreground, int background)									//콘솔 텍스트 색 구현부
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);			//window에서 제공하는 핸들러를 통해 텍스트색과 배경색을 바꾸는 함수
}

#endif