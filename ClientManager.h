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

class ClientManager : public AbstractManager //ClientManagerŬ������ AbstractManagerŬ���� ���
{
public:
	//ClientManager Ŭ���� ���� ����� �� �ִ� �޼ҵ�
	void Client_Input(string _word, 
		string _name, string _phone, string _email);
	void Client_Remove(string _word, string _name);
	void Client_Change(string _word, string _name);
	void Client_PK(string _word);
	vector<string> parseCSV(istream& file, char delimiter);

	//ShoppingManagerŬ������ ȣ���� �ǵ��� ��¿ �� ���� public���� ����
	vector<Client*> clientList;

	//AbstractManagerŬ������ �����Լ��� �������̵�
	virtual int Count() override { return C_Count; };
	virtual void RemoveAll() override;
	virtual void Display() override;
	virtual void Save() override;
	virtual void Load() override;
	
private:
	//������ ���� ���� ����
	int C_Count = 0;
	
	//���� ���� �����ϴ� �Լ����� ���̴� ����
	string CM_Word;
	string CM_Name;
	string CM_Phone;
	string CM_Email;
};

#endif