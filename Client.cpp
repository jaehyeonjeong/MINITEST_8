#include "Client.h"

//Client �����͸� get set�Լ��� ���� �� ȣ�� �����ϰԲ� ����

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

//Client, Product�� key���� string���¿� ���� ���ϱ� ���� ������
bool Client::operator==(string str)const
{
	return (this->C_Custom_Word == str);
}