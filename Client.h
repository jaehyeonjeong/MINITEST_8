#ifndef _CLIENT_H_
#define _CLIENT_H_

#include <iostream>
using namespace std;

class Client
{
public:
	//고객 클래스 복사 생성자
	explicit Client(string _word = "", string _name = "",
		string _phone = "", string _email = "", string _grade = "", int _cprice = 0)		//고객의 데이터 값 초기화
		:C_Custom_Word(_word), C_Name(_name),
		C_Phone(_phone), C_Email(_email), C_Grade(_grade), Client_price(_cprice)
	{

	}
	string getCWord() const;																//고객의 ID get()함수
	void setCWord(string& _custom);															//고객의 ID set()함수
	string getCName() const;																//고객의 이름 get() 함수
	void setCName(string& _name);															//고객의 이름 set() 함수
	string getCPhone() const;																//고객의 전화번호 get() 함수
	void setCPhone(string& _phone);															//고객의 전화번호 set() 함수	
	string getCEmail() const;																//고객의 이메일 get() 함수
	void setCEmail(string& _email);															//고객의 이메일 set() 함수	

	//고객 등급 변수 get set함수
	string getCGrade()const { return C_Grade; }												//고객의 등급 get() 함수
	void setCGrade(string _grade) { C_Grade = _grade; }										//고객의 등급 set() 함수	

	//고객이 사용한 금액 get set함수
	int getCPrice() const { return Client_price; }											//고객의 등급에 따른 할당가격 get() 함수
	void setCPrice(int _price) { Client_price = _price; }									//고객의 등급에 따른 할당가격 set() 함수 초기화 하기 위해 쓰임

	//고객이 사용한 금액 누적하는 set함수
	void setAddCPrice(int _addprice) { Client_price += _addprice; }                         //고객의 등급에 따른 누적할당가격 set() 함수 

	bool operator==(string str) const;														//고객의 ID와 입력하는 값이 string인 경우 bool값을 반환하는 operator
private:
	//고객 기본 데이터 설정
	string C_Custom_Word;																	//고객의 ID 입력 변수
	string C_Name;																			//고객의 Name입력 변수		
	string C_Phone;																			//고객의 전화번호 입력 변수
	string C_Email;																			//고객의 Email 입력 변수			


	//휘하 두 데이터는 파일 저장을 위해 복사 생성자에서 초기화할 필요가 있음
	//고객 등급 변수 설정
	string C_Grade;
	//고객이 사용한 금액 저장
	int Client_price;
};

#endif