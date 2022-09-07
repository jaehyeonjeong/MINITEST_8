#ifndef _CLIENT_MANAGER_H_
#define _CLIENT_MANAGER_H_

#include "Client.h"
#include "AbstractManager.h"
#include <vector>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iomanip>

class ClientManager : public AbstractManager									//ClientManagerŬ������ AbstractManagerŬ���� ���
{
public:

	//AbstractManagerŬ������ �����Լ��� �������̵�
	virtual int Count() const override { return C_Count; }						//ClientList �Ӹ��� 
	virtual void RemoveAll() override;											//ClientList ��ü ����Ʈ ����
	virtual void Display() const override;										//ClientList ��ü ����
	virtual void Save() const override;											//ClientList ���� ����
	virtual void Load() override;												//ClientList ���� �ε�

	//ClientManager Ŭ���� ���� ����� �� �ִ� �޼ҵ�
	void Client_Input(string _word, string _name, 
		string _phone, string _email);											//ClientList ������ �Է� �Լ�
	void Client_Remove(string _word, string _name);								//ClientList ������ ���� �Լ�
	void Client_Change(string _word, string _name);								//ClientList ������ ���� �Լ�
	void Client_PK(string _word) const;											//ClientPrimeKey ǥ�� �Լ�
	vector<string> parseCSV(istream& file, char delimiter);						//������ �ҷ��� �� ','����

	//ShoppingManagerŬ������ ȣȯ�� �ǵ��� ��¿ �� ���� public���� ����
	vector<Client*> clientList;

	
private:
	//���� ��� ���� ����
	int C_Count = 0;
	
	//�� ���� �����ϴ� �Լ����� ���̴� ����
	string CM_Word;																//ClientID (Client PK)
	string CM_Name;																//Client Name
	string CM_Phone;															//Client Phone
	string CM_Email;															//Client Email
};

#endif