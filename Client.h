#ifndef _CLIENT_H_
#define _CLIENT_H_

#include <iostream>
using namespace std;

class Client
{
public:
	//�� Ŭ���� ���� ������
	explicit Client(string _word = "", string _name = "",
		string _phone = "", string _email = "", string _grade = "", int _cprice = 0)		//���� ������ �� �ʱ�ȭ
		:C_Custom_Word(_word), C_Name(_name),
		C_Phone(_phone), C_Email(_email), C_Grade(_grade), Client_price(_cprice)
	{

	}
	string getCWord() const;																//���� ID get()�Լ�
	void setCWord(string& _custom);															//���� ID set()�Լ�
	string getCName() const;																//���� �̸� get() �Լ�
	void setCName(string& _name);															//���� �̸� set() �Լ�
	string getCPhone() const;																//���� ��ȭ��ȣ get() �Լ�
	void setCPhone(string& _phone);															//���� ��ȭ��ȣ set() �Լ�	
	string getCEmail() const;																//���� �̸��� get() �Լ�
	void setCEmail(string& _email);															//���� �̸��� set() �Լ�	

	//�� ��� ���� get set�Լ�
	string getCGrade()const { return C_Grade; }												//���� ��� get() �Լ�
	void setCGrade(string _grade) { C_Grade = _grade; }										//���� ��� set() �Լ�	

	//���� ����� �ݾ� get set�Լ�
	int getCPrice() const { return Client_price; }											//���� ��޿� ���� �Ҵ簡�� get() �Լ�
	void setCPrice(int _price) { Client_price = _price; }									//���� ��޿� ���� �Ҵ簡�� set() �Լ� �ʱ�ȭ �ϱ� ���� ����

	//���� ����� �ݾ� �����ϴ� set�Լ�
	void setAddCPrice(int _addprice) { Client_price += _addprice; }                         //���� ��޿� ���� �����Ҵ簡�� set() �Լ� 

	bool operator==(string str) const;														//���� ID�� �Է��ϴ� ���� string�� ��� bool���� ��ȯ�ϴ� operator
private:
	//�� �⺻ ������ ����
	string C_Custom_Word;																	//���� ID �Է� ����
	string C_Name;																			//���� Name�Է� ����		
	string C_Phone;																			//���� ��ȭ��ȣ �Է� ����
	string C_Email;																			//���� Email �Է� ����			


	//���� �� �����ʹ� ���� ������ ���� ���� �����ڿ��� �ʱ�ȭ�� �ʿ䰡 ����
	//�� ��� ���� ����
	string C_Grade;
	//���� ����� �ݾ� ����
	int Client_price;
};

#endif