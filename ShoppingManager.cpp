#include "ShoppingManager.h"
#include <Windows.h>
#include <conio.h>


//���� ���� ������ �߰� �Լ�
void ShoppingManager::Shopping_Input(ClientManager& C_ref, ProductManager& P_ref,
	int _num, string _clpk, string _prpk, int _date, int _quantatiy)
{
	//�� ����� string������ ���ο��� ���� �����ϴ� ������ compare�Լ��� "VVIP"�� �ۼ��ϸ� const char*�� NULL���ڱ��� ���Խ��� ������.
	string VVIP = "VVIP";
	string VIP = "VIP";
	string Normal = "Normal";



	for (int i = 0; i < C_ref.Count(); i++)
	{
		if (C_ref.clientList.at(i)->getCWord().compare(_clpk) == 0) //Ŭ���̾�Ʈ PK�� �Է��� Ŭ���̾�Ʈ PK�� �� ���̸� �ٵ� ���
		{
			string C_Word = C_ref.clientList.at(i)->getCWord();
			auto it1 = find_if(C_ref.clientList.begin(), C_ref.clientList.end(),
				[=](Client* c) {return *c == C_Word; });
			if (it1 != C_ref.clientList.end())
			{
				Client* c = *it1;
				cout << "ADD Client Prime Key : " << c->getCWord() << endl;
				for (int j = 0; j < P_ref.Count(); j++)
				{
					if (P_ref.productList.at(j)->getPId().compare(_prpk) == 0) //���δ�Ʈ PK�� �Է��� ���δ�Ʈ PK�� �� ���̸� �ٵ� ���
					{
						string P_Id = P_ref.productList.at(j)->getPId();
						auto it2 = find_if(P_ref.productList.begin(),
							P_ref.productList.end(),
							[=](Product* p) {return *p == P_Id; });
						if (it2 != P_ref.productList.end())
						{
							Product* p = *it2;
							cout << "ADD Prodcut Prime Key : " << p->getPId() << endl;
							double price;
		
							//��޺� ���� ����
							if (C_ref.clientList.at(i)->getCGrade().compare(VVIP) == 0)
							{
								price = (P_ref.productList.at(j)->getPPrice() * _quantatiy) * 0.90; //VVIP�� 10�ۼ�Ʈ ����
								shoppingList.push_back(new Shopping(_num,
									_clpk, _prpk, _date, _quantatiy, price)); // ���� PK�� ��ġ�� ���� �ȴٸ� ���� ����Ʈ�� ������ �߰�
								Snumber += 1;
								S_Count += 1;
								cout << "\n���� ���� �߰� �Ϸ�" << endl;
							}
							if (C_ref.clientList.at(i)->getCGrade().compare(VIP) == 0)
							{
								price = (P_ref.productList.at(j)->getPPrice() * _quantatiy) * 0.95; //VIP�� 5�ۼ�Ʈ ����
								shoppingList.push_back(new Shopping(_num,
									_clpk, _prpk, _date, _quantatiy, price)); // ���� PK�� ��ġ�� ���� �ȴٸ� ���� ����Ʈ�� ������ �߰�
								Snumber += 1;
								S_Count += 1;
								cout << "\n���� ���� �߰� �Ϸ�" << endl;
							}
							if (C_ref.clientList.at(i)->getCGrade().compare(Normal) == 0)
							{
								price = P_ref.productList.at(j)->getPPrice() * _quantatiy; //Normal�̸� �ƹ��͵� ����
								shoppingList.push_back(new Shopping(_num,
									_clpk, _prpk, _date, _quantatiy, price)); // ���� PK�� ��ġ�� ���� �ȴٸ� ���� ����Ʈ�� ������ �߰�
								Snumber += 1;
								S_Count += 1;
								cout << "\n���� ���� �߰� �Ϸ�" << endl;
							}
						}
					}
				}
			}
		}
	}
}

//���� ���� ����Ʈ ���� ���� �Լ�
void ShoppingManager::sort()
{
	for (int i = 0; i < S_Count; i++)
	{
		shoppingList.at(i)->setSNumber(i);
	}
}
void ShoppingManager::Display()
{
	cout << "++++++++++++++++++++++++++++++���� ���� ����Ʈ++++++++++++++++++++++++++++++" << endl;
	cout << "----------------------------------------------------------------------------" << endl;
	cout << setw(5) << "��ȣ" << " | " << setw(10) << "�� ID" << " | " << setw(11) << "��ǰ ID" << " | " << setw(11) << "���� ��¥" << " | "
		<< setw(5) << "����" << " | " << setw(18) << "�� �ݾ�" << endl;
	cout << "----------------------------------------------------------------------------" << endl;
	for_each(shoppingList.begin(), shoppingList.end(), [](Shopping* s)
		{
			cout << setw(5) << s->getSNumber() << " | " << setw(10) << s->getSPKClient() << " | "
				<< setw(11) << s->getSPKProduct() << " | " << setw(11) << s->getSDate() <<
				" | " << setw(5) << s->getSQuan() << " | " << setw(16) << s->getSAllprice() << "��" << endl;
			cout << "----------------------------------------------------------------------------" << endl;
		});
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl << endl;
}

//���� ���� ����Ʈ ���� �Լ�
void ShoppingManager::Shopping_Display(ClientManager& _cm, ProductManager& _pm)
{
	int num = 0;
	string PKCL, PKPR;
	int sm_date, flash = 1;
	char find_c;

	cout << "++++++++++++++++++++++++++++++���� ���� ����Ʈ++++++++++++++++++++++++++++++" << endl;
	cout << "----------------------------------------------------------------------------" << endl;
	cout << setw(5) << "��ȣ" << " | " << setw(10) << "�� ID" << " | " << setw(11) << "��ǰ ID" << " | " << setw(11) << "���� ��¥" << " | "
		<< setw(5) << "����" << " | " << setw(18) << "�� �ݾ�" << endl;
	cout << "----------------------------------------------------------------------------" << endl;
	for_each(shoppingList.begin(), shoppingList.end(), [](Shopping* s)
		{
			cout << setw(5) << s->getSNumber() << " | " << setw(10) << s->getSPKClient() << " | "
				<< setw(11) << s->getSPKProduct() << " | " << setw(11) << s->getSDate() <<
				" | " << setw(5) << s->getSQuan() << " | " << setw(16) << s->getSAllprice() << "��" << endl;
			cout << "----------------------------------------------------------------------------" << endl;
		});
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl << endl;


	//���Ÿ���Ʈ ��ȸ�� client, product, ��¥�� ���� �˻�
	while (num != 4)
	{
	back_search:;
		cout << "\n���� ���� ����Ʈ���� �˻��� Ű���尡 �����ʴϱ�?" << endl;
		cout << "1. ClientID, 2. ProductID, 3. ��¥�� ���� ����, 4.���� : "; cin >> num;

		if (!cin)
		{
			cout << "\n������ ���ڸ� �Է����ֽñ� �ٶ��ϴ�." << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			goto back_search;
		}
		switch (num)
		{
			//ClientID�� ������ ������ ����� case��
		case 1:
			cout << "\nClientID�� ������ � ������ ���Ͻʴϱ�?" << endl;
			cout << "1. ClientID ����, 2. �ش� ClientID ���� ��� : "; 
			
			scanf_s("%c", &find_c);
			
			do
			{
				find_c = _getch();
				if (find_c >= '1' && find_c <= '2')
				{
					printf("%c", find_c); 
					break;
				}
			} while (true);
			//ClientID ���� ���� �Լ�
			if (find_c == '1')
			{
				cout << "\nClientID �Է� : "; cin >> pk_cl;
				cout << "\n�ش� ClientID(" << pk_cl << ")�� ������ :";
				PKCL = pk_cl;
				auto it = find_if(_cm.clientList.begin(), _cm.clientList.end(),
					[=](Client* c) {return *c == PKCL; });
				if (it != _cm.clientList.end())
				{
					Client* c = *it;
					cout << "\n�� ���� : " << c->getCName() << 
						", \n�� ��� : " << c->getCGrade() <<
						", \n�� ��ȭ��ȣ : " << c->getCPhone() << 
						", \n�� �̸��� : " << c->getCEmail() << endl << endl;
				}
			}
			//�ش� ClientID ���� ���� ����Ʈ
			else if (find_c == '2')
			{
				cout << "\nClientID �Է� : "; cin >> pk_cl;
				PKCL = pk_cl;
				cout << endl;
				auto it = find_if(_cm.clientList.begin(), _cm.clientList.end(),
					[=](Client* c) {return *c == PKCL; });
				if (it != _cm.clientList.end())
				{
					Client* c = *it;
					cout << "+++++++++++++++++++++++" << pk_cl <<"�� ���� ���� ����Ʈ++++++++++++++++++++++++" << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					cout << setw(5) << "��ȣ" << " | " << setw(10) << "�� ID" << " | " << setw(11) << "��ǰ ID" << " | " << setw(11) << "���� ��¥" << " | "
						<< setw(5) << "����" << " | " << setw(18) << "�� �ݾ�" << endl;
					for (int i = 0; i < S_Count; i++)
					{
						if (c->getCWord().compare(shoppingList.at(i)->getSPKClient()) == 0)
						{
							cout << "----------------------------------------------------------------------------" << endl;
							cout << setw(5) << shoppingList.at(i)->getSNumber() << " | " << setw(10);
							textcolor(LIGHTRED, BLACK);
							cout << shoppingList.at(i)->getSPKClient();
							textcolor(WHITE, BLACK);
							cout << " | " << setw(11) << shoppingList.at(i)->getSPKProduct() << " | " << setw(11) << shoppingList.at(i)->getSDate() << " | "
								<< setw(5) << shoppingList.at(i)->getSQuan() << " | " << setw(18) << shoppingList.at(i)->getSAllprice() << endl;
						}
					}
					cout << "----------------------------------------------------------------------------" << endl;
					cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl << endl;
				}
			}

			//�ش���� ������ ���ڴ� ��ȸ �������� ���ư�
			else
			{
				cout << "\n��ȸ �������� ���ư��ڽ��ϴ�." << endl;
				break;
			}
			break;
			//ClientID�� ������ ������ ����� case��


			//ProdcutID�� ������ ������ ����� case��
		case 2:
			cout << "\nProductID�� ������ � ������ ���Ͻʴϱ�?" << endl;
			cout << "1. ProductID ����, 2. �ش� ProductID ���� ��� : ";
			scanf_s("%c", &find_c);

			do
			{
				find_c = _getch();
				if (find_c >= '1' && find_c <= '2')
				{
					printf("%c", find_c);
					break;
				}
			} while (true);
			//�ش� ProdcutID�� ���� �˻�
			if (find_c == '1')
			{
				cout << "\nProductID �Է� :"; cin >> pk_pr;
				cout << "\n�ش� ProductID(" << pk_pr << ")�� ������ :";
				PKPR = pk_pr;
				auto it = find_if(_pm.productList.begin(), _pm.productList.end(),
					[=](Product* p) {return *p == PKPR; });
				if (it != _pm.productList.end())
				{
					Product* p = *it;
					cout << "\n��ǰ �̸� : " << p->getPName() << 
						", \n��ǰ ���� : " << p->getPPrice() << endl << endl;
				}
			}

			//�ش� ProductID�� �������� ����Ʈ ����
			else if (find_c == '2')
			{
				cout << "\nProductID �Է� : "; cin >> pk_pr;
				PKPR = pk_pr;
				cout << endl;
				auto it = find_if(_pm.productList.begin(), _pm.productList.end(),
					[=](Product* p) {return *p == PKPR; });
				if (it != _pm.productList.end())
				{
					Product* p = *it;
					cout << "++++++++++++++++++++++++" << pk_pr << "�� ���� ���� ����Ʈ+++++++++++++++++++++++++" << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					cout << setw(5) << "��ȣ" << " | " << setw(10) << "�� ID" << " | " << setw(11) << "��ǰ ID" << " | " << setw(11) << "���� ��¥" << " | "
						<< setw(5) << "����" << " | " << setw(18) << "�� �ݾ�" << endl;
					
					for (int i = 0; i < S_Count; i++)
					{
						if (p->getPId().compare(shoppingList.at(i)->getSPKProduct()) == 0)
						{
							cout << "----------------------------------------------------------------------------" << endl;
							cout << setw(5) << shoppingList.at(i)->getSNumber() << " | " << setw(10) << shoppingList.at(i)->getSPKClient() << " | ";
							textcolor(LIGHTRED, BLACK);
								cout << setw(11) << shoppingList.at(i)->getSPKProduct();
								textcolor(WHITE, BLACK);
								cout << " | " << setw(11) << shoppingList.at(i)->getSDate() << " | "
								<< setw(5) << shoppingList.at(i)->getSQuan() << " | " << setw(18) << shoppingList.at(i)->getSAllprice() << endl;
						}
						
					}
					cout << "----------------------------------------------------------------------------" << endl;
					cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl << endl;
				}
			}

			else
			{
				cout << "��ȸ �������� ���ư��ڽ��ϴ�." << endl;
				break;
			}
			break;
			//ProdcutID�� ������ ������ ����� case��


			//shopping list�� ��¥�� �������� ����Ʈ Ž/�˻�
		case 3:
		back_date:;
			cout << "\nShopping Date�Է� : "; cin >> date;
			if (!cin)
			{
				cout << "���� �Է��� ������ ������ �����Ͱ� �ƴմϴ�." << endl;
				cin.ignore(INT_MAX, '\n');
				goto back_date;
			}
			sm_date = date;
			cout << endl;
			if (flash == 1)
			{
				auto it = find_if(shoppingList.begin(), shoppingList.end(), [=](Shopping* s) {return *s == sm_date; });
				if (it != shoppingList.end())
				{
					Shopping* s = *it;
					cout << "+++++++++++++++++++++++++++" << date << " �� ���� ����Ʈ++++++++++++++++++++++++++++" << endl;
					cout << "----------------------------------------------------------------------------" << endl;
					cout << setw(5) << "��ȣ" << " | " << setw(10) << "�� ID" << " | " << setw(11) << "��ǰ ID" << " | " << setw(11) << "���� ��¥" << " | "
						<< setw(5) << "����" << " | " << setw(18) << "�� �ݾ�" << endl;
					for (int i = 0; i < S_Count; i++)
					{
						if (s->getSDate() == shoppingList.at(i)->getSDate())
						{
							cout << "----------------------------------------------------------------------------" << endl;
							cout << setw(5) << shoppingList.at(i)->getSNumber() << " | " << setw(10) << shoppingList.at(i)->getSPKClient() << " | "
								<< setw(11) << shoppingList.at(i)->getSPKProduct() << " | ";
							textcolor(LIGHTRED, BLACK);
							cout << setw(11) << shoppingList.at(i)->getSDate();
							textcolor(WHITE, BLACK);
							cout << " | "  << setw(5) << shoppingList.at(i)->getSQuan();
								cout << " | " << setw(18) << shoppingList.at(i)->getSAllprice() << endl;
						}
						
					}
					cout << "----------------------------------------------------------------------------" << endl;
					cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl << endl;
				}
			}
			break;
			//shopping list�� ��¥�� �������� ����Ʈ Ž/�˻�


		case 4:
			cout << "�˻� ���α׷� ����" << endl;
			break;
		default:
			cout << "�ش��ϴ� �˻� Ű���尡 �����ϴ�." << endl;
			break;
		}
	}
}

//���� ���� ���� �Լ�
void ShoppingManager::Shopping_Remove(int _num)
{
	for (int i = 0; i < S_Count; i++)
	{
		if (shoppingList.at(i)->getSNumber() == _num)
		{
			shoppingList.erase(shoppingList.begin() + i);
			S_Count--;
			cout << "\n���� ���� ���� �Ϸ�!" << endl;
		}
	}
}

//���� ���� ��ü ���� �Լ�
void ShoppingManager::Shopping_Remove_All(ClientManager& _cm)
{
	string EX = "EX";
	while (!shoppingList.empty())
	{
		shoppingList.erase(shoppingList.begin() + 1, shoppingList.end());
		if (shoppingList.at(0)) break;
	}
	S_Count = 1;
	Snumber = 0; //Shoppinglist count �ʱ�ȭ
	
	cout << "\n���� ���� ��ü ���� �Ϸ�!" << endl;
}

//���� ���� ���� �Լ�
void ShoppingManager::Shopping_Change(int _num, ClientManager& sh_cm, ProductManager& sh_pm)
{
	string VVIP = "VVIP";
	string VIP = "VIP";
	string Normal = "Normal";
	for (int i = 0; i < S_Count; i++)
	{
		if (shoppingList.at(i)->getSNumber() == _num)
		{
		shopping_date:;
			cout << "\n������ ��¥ : "; cin >> date;
			if (!cin)//������ ���� �ܼ� �Էºκ� ��� �˻�
			{
				cout << "\n��� ���ݿ� ������ ���ڸ� �Է����� �ʾҽ��ϴ�." << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				goto shopping_date;
			}
			shoppingList.at(i)->setSDate(date);
		shopping_quan:;
			cout << "������ ���� : "; cin >> quan;
			if (!cin)//������ ���� �ܼ� �Էºκ� ��� �˻�
			{
				cout << "\n��� ���ݿ� ������ ���ڸ� �Է����� �ʾҽ��ϴ�." << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				goto shopping_quan;
			}
			shoppingList.at(i)->setSQuan(quan);
			cout << "�� ���� ���� �Ϸ�!!" << endl;


			//�����ϴ� ���� ���� ����Ʈ������ ��� ����
			for (int j = 0; j < sh_pm.Count(); j++)
			{
				if (sh_pm.productList.at(j)->getPId().compare(shoppingList.at(i)->getSPKProduct()) == 0) //��ǰ�� ���̵�� ���� ����Ʈ�� ���̵� ��
				{
					for (int k = 0; k < sh_cm.Count(); k++)//�ش� ���� ����� ã������ for�� 
					{
						if (sh_cm.clientList.at(k)->getCWord().compare(shoppingList.at(i)->getSPKClient()) == 0) // ���� ����� ã������ ���ǹ� ����
						{
							if (sh_cm.clientList.at(k)->getCGrade().compare(VVIP) == 0) //�ش� ���� VVIP�� ���
							{
								int price = (sh_pm.productList.at(j)->getPPrice() * quan) * 0.90;
								shoppingList.at(i)->setSAllprice(price);
								cout << "���� ���� �Ϸ�" << endl;
								break;
							}
							if (sh_cm.clientList.at(k)->getCGrade().compare(VIP) == 0) //�ش� ���� VIP�� ���
							{
								int price = (sh_pm.productList.at(j)->getPPrice() * quan) * 0.95;
								shoppingList.at(i)->setSAllprice(price);
								cout << "���� ���� �Ϸ�" << endl;
								break;
							}
							if(sh_cm.clientList.at(k)->getCGrade().compare(Normal) == 0) //�ش� ���� Normal�� ���
							{
								int price = sh_pm.productList.at(j)->getPPrice() * quan;
								shoppingList.at(i)->setSAllprice(price);
								cout << "���� ���� �Ϸ�" << endl;
								break;
							}
						}
					}
				}
			}
		}
	}
}

//���� ���� ���� �Լ�
void ShoppingManager::ShoppingListSave()
{
	ofstream file;
	file.open("shoppinglist.csv");
	if (!file.fail())
	{
		for (const auto& s : shoppingList)
		{
			file << s->getSNumber() << ',';
			file << s->getSPKClient() << ',';
			file << s->getSPKProduct() << ',';
			file << s->getSDate() << ',';
			file << s->getSQuan() << ',';
			file << s->getSAllprice() << ',';
			file << S_Count << endl;
		}
		file << endl;
	}
	file.close();
	cout << "Shopping ���� ���� �Ϸ�" << endl;
}

//���� ���� �ҷ����� �Լ�
void ShoppingManager::ShoppingListLoad()
{
	ifstream file;
	file.open("shoppinglist.csv");

	if (!file.fail())
	{
		while (!file.eof())
		{
			vector<string> row = parseCSV(file, ',');
			if (row.size())
			{
				int snum = atoi(row[0].c_str());
				int date = atoi(row[3].c_str());
				int quan = atoi(row[4].c_str());
				int price = atoi(row[5].c_str());
				int count = atoi(row[6].c_str());
				Shopping* s = new Shopping(snum, row[1],
					row[2], date, quan, price);
				shoppingList.push_back(s);
				S_Count = count;
				Snumber = count;
			}
		}
	}
	file.close();
	cout << "Shopping ���� �ҷ����� �Ϸ�" << endl << endl;
}

vector<string> ShoppingManager::parseCSV(istream& file, char delimiter)
{
	stringstream ss;
	vector<string> row;
	string t = " \n\r\t";

	while (!file.eof())
	{
		char c = file.get();
		if (c == delimiter || c == '\r' || c == '\n')
		{
			if (file.peek() == '\n') file.get();
			string s = ss.str();
			s.erase(0, s.find_first_not_of(t));
			s.erase(s.find_last_not_of(t) + 1);
			row.push_back(s);
			ss.str("");
			if (c != delimiter) break;
		}
		else
		{
			ss << c;
		}
	}
	return row;
}

void ShoppingManager::setAllPrice(int _price)
{
	Allprice = _price;
}

//���� ����Ʈ�� ���� �� �ѱݾ� Ž�� �Լ� client->cprice->getCPrice(), shopping->getAllPrice()
	//�� �Լ��� ���� �߰� ���� ���� ��ɿ��� ��ɿ� ���� �� ����� �ֽ�ȭ �� �� �ֵ��� ����
void ShoppingManager::FindCPrice(ClientManager& _cm)
{
	//�ʱ�ȭ�� ������ ���� ���, ����
	string grade;
	//int cprice = 0;

	//���� client�� ������ �ִ� ��� �ݾ� �Լ� �ʱ�ȭ
	for (int i = 0; i < _cm.Count(); i++)
	{
		_cm.clientList.at(i)->setCPrice(0); //0���� �ʱ�ȭ
	}

	for (int j = 0; j < _cm.Count(); j++) //���� ������ �� ����Ʈ ���� ��ŭ for������ Ž�� ���� i
	{
		for (int i = 0; i < S_Count; i++) //���� ������ ���� ����Ʈ�� ���� ��ŭ for������ Ž�� ���������� j
		{
			if (_cm.clientList.at(j)->getCWord().compare(shoppingList.at(i)->getSPKClient()) == 0) 
				//Ž���� ���� ����Ʈ �� �� ����Ʈ�� PK�� ��ġ�ϴ� �� Ȯ���� ���� ����Ʈ�� �ѱݾ��� 
				//���ϸ� ������� �ʱ�ȭ
			{
				//���� ���� 1�࿡ �ش��ϴ� �� �ҷ����� cprice�� ����
				//cprice += shoppingList.at(i)->getSAllprice();

				//�ش��ϴ� �� �࿡ ����� �ݾ� ����
				_cm.clientList.at(j)->setAddCPrice(shoppingList.at(i)->getSAllprice());
			}
		}
	}

	//������ �ݾ� ���� ���� ���� ��� ����
	for (int i = 0; i < _cm.Count(); i++)
	{
		if (_cm.clientList.at(i)->getCPrice() >= 1000000) //�ش��ϴ� �� �������� 1,000,000 �̻��� ���
		{
			grade = "VVIP";
			_cm.clientList.at(i)->setCGrade(grade); //VVIP�� ��� ����
			//cout << "VVIP�� ����" << endl;
		}
		else if (_cm.clientList.at(i)->getCPrice() >= 500000 &&
			_cm.clientList.at(i)->getCPrice() < 1000000) //�ش��ϴ� �� �������� 500000 �̻� 1000000 �̸��� ��� 
		{
			grade = "VIP";
			_cm.clientList.at(i)->setCGrade(grade);//VIP�� ��� ����
			//cout << "VIP�� ����" << endl;
		}
		else if(_cm.clientList.at(i)->getCPrice() >= 0 && 
			_cm.clientList.at(i)->getCPrice() < 500000)
		{
			grade = "Normal"; //500000�̸��� ���
			_cm.clientList.at(i)->setCGrade(grade);//Normal�� ��� ����
			//cout << "Normal�� ����" << endl;
		}
	}
}

void textcolor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}