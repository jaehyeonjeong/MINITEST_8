#include "Client.h"

//Client 데이터를 get set함수로 수정 및 호출 가능하게끔 구현

string Client::getCWord() const
{
	return C_Custom_Word;
}

void Client::setCWord(string& _custom)
{
	C_Custom_Word = _custom;
}

string Client::getCName() const
{
	return C_Name;
}

void Client::setCName(string& _name) 
{
	C_Name = _name;
}

string Client::getCPhone() const
{
	return C_Phone;
}

void Client::setCPhone(string& _phone)
{
	C_Phone = _phone;
}

string Client::getCEmail() const
{
	return C_Email;
}

void Client::setCEmail(string& _email)
{
	C_Email = _email;
}

//Client, Product의 key값을 string형태와 대조 비교하기 위한 연산자
bool Client::operator==(string str)const
{
	return (this->C_Custom_Word == str);
}