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

class ClientManager : public AbstractManager //ClientManager클래스는 AbstractManager클래스 상속
{
public:

	//AbstractManager클래스의 가상함수를 오버라이드
	virtual int Count() const override { return C_Count; };
	virtual void RemoveAll() override;
	virtual void Display() const override;
	virtual void Save() const override;
	virtual void Load() override;

	//ClientManager 클래스 만이 사용할 수 있는 메소드
	void Client_Input(string _word, 
		string _name, string _phone, string _email);
	void Client_Remove(string _word, string _name);
	void Client_Change(string _word, string _name);
	void Client_PK(string _word);
	vector<string> parseCSV(istream& file, char delimiter);

	//ShoppingManager클래스와 호완이 되도록 어쩔 수 없이 public으로 선언
	vector<Client*> clientList;

	
private:
	//고객의 명수 저장 변수
	int C_Count = 0;
	
	//고객 정보 변경하는 함수에서 쓰이는 변수
	string CM_Word;
	string CM_Name;
	string CM_Phone;
	string CM_Email;
};

#endif