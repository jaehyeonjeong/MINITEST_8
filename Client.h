#ifndef _CLIENT_H_
#define _CLIENT_H_

#include <iostream>
using namespace std;

class Client
{
public:
	//�� Ŭ���� ���� ������
	explicit Client(string _word = "", string _name = "",
		string _phone = "", string _email = "", string _grade = "", int _cprice = 0)
		:C_Custom_Word(_word), C_Name(_name),
		C_Phone(_phone), C_Email(_email), C_Grade(_grade), Client_price(_cprice)
	{

	}
	string getCWord() const;
	void setCWord(string& _custom);
	string getCName() const;
	void setCName(string& _name);
	string getCPhone() const;
	void setCPhone(string& _phone);
	string getCEmail() const;
	void setCEmail(string& _email);

	//�� ��� ���� get set�Լ�
	string getCGrade()const { return C_Grade; }
	void setCGrade(string _grade) { C_Grade = _grade; }

	//���� ����� �ݾ� get set�Լ�
	int getCPrice() const { return Client_price; }
	void setCPrice(int _price) { Client_price = _price; }

	//���� ����� �ݾ� �����ϴ� set�Լ�
	void setAddCPrice(int _addprice) { Client_price += _addprice; }

	bool operator==(string str) const;
private:
	//�� �⺻ ������ ����
	string C_Custom_Word;
	string C_Name;
	string C_Phone;
	string C_Email;


	//���� �� �����ʹ� ���� ������ ���� ���� �����ڿ��� �ʱ�ȭ�� �ʿ䰡 ����
	//�� ��� ���� ����
	string C_Grade;
	//���� ����� �ݾ� ����
	int Client_price;
};

#endif