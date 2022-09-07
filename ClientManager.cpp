#include "ClientManager.h"

//main문에서 고객관리 정보 데이터가 들어가는 함수
void ClientManager::Client_Input(string _word,
	string _name, string _phone, string _email)
{
	clientList.push_back(new Client(_word, _name, _phone, _email));
	ClientManager::C_Count += 1;
	Client_PK(_word);
	cout << "\n고객 정보 입력 완료" << endl;
}

//고객 정보 리스트 공개 함수
void ClientManager::Display()
{
	cout << "ClientCount : " << C_Count << endl;
	cout << "+++++++++++++++++++++++++++++++++고객 정보 리스트+++++++++++++++++++++++++++++++++" << endl;
	cout << "----------------------------------------------------------------------------------" << endl;
	cout << setw(11) << "고객ID" << " | " << setw(10) << "고객 성함" << " | " << setw(15) << "고객 전화번호" << " | " 
		<< setw(20) << "고객 이메일" << " | " << setw(12) << "고객 등급" << endl;
	cout << "----------------------------------------------------------------------------------" << endl;
	for_each(clientList.begin(), clientList.end(), [](Client* c)
		{
			cout << setw(11) << c->getCWord() << " | " << setw(10) << c->getCName() << " | "
				<< setw(15) << c->getCPhone() << " | " << setw(20) << c->getCEmail() << " | " 
				
				//등급 확인과 구매한 총금액을 확인하는 함수
				<< setw(12) << c->getCGrade() << endl;
			cout << "----------------------------------------------------------------------------------" << endl;
		});
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl << endl;
}

//고객 정보 제거 함수
void ClientManager::Client_Remove(string _word, string _name)
{
	for (int i = 0; i < C_Count; i++)
	{
		if ((clientList.at(i)->getCWord().compare(_word) == 0) &&
			(clientList.at(i)->getCName().compare(_name) == 0))
		{
			clientList.erase(clientList.begin() + i);
			ClientManager::C_Count -= 1;
			cout << "\n고객 정보 삭제 완료" << endl;
		}
	}
}

//고객 정보 전체 제거 함수
void ClientManager::RemoveAll()
{
	while (!clientList.empty()) //clientList의 데이터가 비어질때 까지
	{
		clientList.erase(clientList.begin(), clientList.end());//clientList의 모든 데이터를 제거
	}
	//client의 데이터가 모두 지워지면 while문에서 탈출
	ClientManager::C_Count = 0;//Client 머릿수 초기화
	cout << "\n고객 정보 전체 삭제 완료" << endl;
}

//고객 정보 변경 함수
void ClientManager::Client_Change(string _word, string _name)
{
	//고객의 머릿수 만큼 탐색
	for (int i = 0; i < ClientManager::C_Count; i++)
	{
		//받는 인자의 ID와 이름이 같은경우에 변경할 고객 데이터를 제시
		if ((clientList.at(i)->getCWord().compare(_word) == 0) &&
			(clientList.at(i)->getCName().compare(_name) == 0))
		{
			cout << "\n변경할 고객 ID : "; cin >> ClientManager::CM_Word;
			clientList.at(i)->setCWord(ClientManager::CM_Word);
			cout << "변경할 고객 성함 : "; cin >> ClientManager::CM_Name;
			clientList.at(i)->setCName(ClientManager::CM_Name);
			cout << "변경할 고객 전화번호 : "; cin >> ClientManager::CM_Phone;
			clientList.at(i)->setCPhone(ClientManager::CM_Phone);
			cout << "변경할 고객 이메일 : "; cin >> ClientManager::CM_Email;
			clientList.at(i)->setCEmail(ClientManager::CM_Email);
			cout << "고객 정보 변경 완료!!" << endl;
		}
	}
}

void ClientManager::Client_PK(string _word)
{
	string C_WORD = _word;
	auto it = find_if(clientList.begin(), clientList.end(),
		[=](Client* p) {return *p == C_WORD; });
	if (it != clientList.end())
	{
		Client* c = *it;
		cout << "Client Prime Key : " << c->getCWord() << endl;
	}
}

//고객 정보 파일로 저장 함수
void ClientManager::Save()
{
	ofstream file;
	file.open("clientlist.csv");
	if (!file.fail()) {
		for (const auto& c : clientList) {
			file << c->getCWord() << ',';
			file << c->getCName() << ',';
			file << c->getCPhone() << ',';
			file << c->getCEmail() << ',';

			//파일로 등급과 구매한 금액 저장
			file << c->getCGrade() << ',';
			file << c->getCPrice() << ',';

			//Client의 머릿수
			file << C_Count << endl;
		}
		file << endl;
	}
	file.close();
	cout << "Client 파일 저장 완료" << endl;
}

//고객 정보 파일로 불러오기 함수
void ClientManager::Load()
{
	//vector<Client*> vecList;
	ifstream file; //input
	file.open("clientlist.csv");
	if (!file.fail()) {
		while (!file.eof()) {
			vector<string> row = parseCSV(file, ',');
			if (row.size()) {
				//해당 고객이 사용한 금액 int 형으로 변환
				int cprice = atoi(row[5].c_str());
				//고객의 인원수 저장
				int count = atoi(row[6].c_str());

				//row[4]와 cprice에서 client생성자와 비교하여 파일에서 불러드림
				Client* c = new Client(row[0], row[1],
					row[2], row[3], row[4], cprice);
				clientList.push_back(c);
				C_Count = count;
			}
		}
	}
	file.close();
	cout << "Client 파일 불러오기 완료" << endl;
}

//파일에서 불러오는 정보를 파싱하여 ','문은 구분할 수 있는 함수를 제작
vector<string> ClientManager::parseCSV(istream& file,
	char delimiter)
{
	stringstream ss; //문자행렬을 받는 stringstream
	vector<string> row;
	string t = " \n\r\t"; // 파일 내의 \n\r\t에서 공백값을 지우는 변수 설정

	while (!file.eof()) { //file의 끝까지
		char c = file.get();
		if (c == delimiter || c == '\r' || c == '\n') {//c가 받는 ','와 \r, \n인 경우
			if (file.peek() == '\n') file.get();
			string s = ss.str();
			s.erase(0, s.find_first_not_of(t)); // string인 t변수에서 해당 \n\r\t는 지우겠다는 함수
			s.erase(s.find_last_not_of(t) + 1); // 마지막까지
			row.push_back(s); //vector로 저장된 값들을 넣어줌
			ss.str("");
			if (c != delimiter) break; //','을 만나면 함수종료
		}
		else { //c가 받는  ','와 \r, \n이 아닌 경우
			ss << c;
		}
	}
	return row;
}