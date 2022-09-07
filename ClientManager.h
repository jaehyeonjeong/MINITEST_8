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

class ClientManager : public AbstractManager									//ClientManager클래스는 AbstractManager클래스 상속
{
public:

	//AbstractManager클래스의 가상함수를 오버라이드
	virtual int Count() const override { return C_Count; }						//ClientList 머릿수 
	virtual void RemoveAll() override;											//ClientList 전체 리스트 제거
	virtual void Display() const override;										//ClientList 전체 나열
	virtual void Save() const override;											//ClientList 파일 저장
	virtual void Load() override;												//ClientList 파일 로드

	//ClientManager 클래스 만이 사용할 수 있는 메소드
	void Client_Input(string _word, string _name, 
		string _phone, string _email);											//ClientList 데이터 입력 함수
	void Client_Remove(string _word, string _name);								//ClientList 데이터 제거 함수
	void Client_Change(string _word, string _name);								//ClientList 데이터 변경 함수
	void Client_PK(string _word) const;											//ClientPrimeKey 표시 함수
	vector<string> parseCSV(istream& file, char delimiter);						//파일을 불러올 때 ','구분

	//ShoppingManager클래스와 호환이 되도록 어쩔 수 없이 public으로 선언
	vector<Client*> clientList;

	
private:
	//고객의 명수 저장 변수
	int C_Count = 0;
	
	//고객 정보 변경하는 함수에서 쓰이는 변수
	string CM_Word;																//ClientID (Client PK)
	string CM_Name;																//Client Name
	string CM_Phone;															//Client Phone
	string CM_Email;															//Client Email
};

#endif