#include "ProductManager.h"

//��ǰ ������ �Է� �Լ�
void ProductManager::Product_Input(string _id, string _name, int _price)
{
	productList.push_back(new Product(_id, _name, _price));
	P_Count += 1;
	Product_PK(_id);
	cout << "\n��ǰ ���� ��� �Ϸ�!" << endl << endl;
}

//��ǰ ����Ʈ ���� �Լ�
void ProductManager::Display() const
{
	cout << "ProductCount : " << P_Count << endl;
	cout << "++++++++++++��ǰ ���� ����Ʈ+++++++++++++" << endl;
	cout << "-----------------------------------------" << endl;
	cout << setw(11) << "��ǰ ID" << " | " << setw(11) << "��ǰ �̸�" << " | " << setw(12) << "��ǰ ����" << endl;
	cout << "-----------------------------------------" << endl;
	for_each(productList.begin(), productList.end(),
		[](Product* p) { //algorithm for_each�� �Ķ���� �������� ���ٷ� ��ȯ�Ͽ� ����Ʈ ����
			cout << setw(11) << p->getPId() << " | " << setw(11) << p->getPName() << " | " 
				<< setw(10) << p->getPPrice() << "��" << endl;
			cout << "-----------------------------------------" << endl;
		});
	cout << "+++++++++++++++++++++++++++++++++++++++++" << endl << endl;
}

//��ǰ ���� ���� �Լ�
void ProductManager::Product_Remove(string _id)
{
	for (int i = 0; i < P_Count; i++)
	{
		if (productList.at(i)->getPId().compare(_id) == 0)
		{
			productList.erase(productList.begin() + i);
			P_Count -= 1;
			cout << "\n��ǰ ���� ���� �Ϸ�!" << endl;
		}
	}
}

//��ǰ ���� ��ü ���� �Լ�
void ProductManager::RemoveAll()
{
	while (!productList.empty())
	{
		productList.erase(productList.begin(), productList.end());
	}
	P_Count = 0;
	cout << "\n��ǰ ���� ��ü ���� �Ϸ�!" << endl;
}

//��ǰ ���� ���� �Լ�
void ProductManager::Product_Change(string _id)
{
	for (int i = 0; i < P_Count; i++)
	{
		if (productList.at(i)->getPId().compare(_id) == 0)
		{
			cout << "\n������ ��ǰ ID : "; cin >> ProductManager::PM_ID;
			productList.at(i)->setPId(ProductManager::PM_ID);
			cout << "������ ��ǰ �̸� : "; cin >> ProductManager::PM_Name;
			productList.at(i)->setPName(ProductManager::PM_Name);
		product_price:;
			cout << "������ ��ǰ ���� : "; cin >> ProductManager::PM_Price;
			if (!cin)//������ ���� �ܼ� �Էºκ� ��� �˻�
			{
				cout << "\n��� ���ݿ� ������ ���ڸ� �Է����� �ʾҽ��ϴ�." << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				goto product_price;
			}
			productList.at(i)->setPPrice(ProductManager::PM_Price);
			cout << "��ǰ ���� ���� �Ϸ�!" << endl;
		}
	}
}
void ProductManager::Product_PK(string _id) const
{
	string P_ID = _id;
	auto it = find_if(productList.begin(), productList.end(),
		[=](Product* p) {return *p == P_ID; });
	if (it != productList.end())
	{
		Product* p = *it;
		cout << "Product Prime Key : " << p->getPId() << endl;
	}
}

//��ǰ ���� ���Ϸ� �����ϴ� �Լ�
void ProductManager::Save() const
{
	ofstream file;
	file.open("prductlist.csv");
	if (!file.fail())
	{
		for (const auto& p : productList)
		{
			file << p->getPId() << ',';
			file << p->getPName() << ',';
			file << p->getPPrice() << ',';
			file << P_Count << endl;
		}
		file << endl;
	}
	file.close();
	cout << "Product ���� ���� �Ϸ�" << endl;
}

//��ǰ���� ���Ϸ� �ε� �Լ�
void ProductManager::Load()
{
	ifstream file;
	file.open("prductlist.csv");
	if (!file.fail())
	{
		while (!file.eof())
		{
			vector<string> row = parseCSV(file, ',');
			if (row.size())
			{
				int count = atoi(row[3].c_str());
				int price = atoi(row[2].c_str());
				Product* p = new Product(row[0], row[1], price);
				productList.push_back(p);
				P_Count = count;
			}
		}
	}
	file.close();
	cout << "Product ���� �ҷ����� �Ϸ�" << endl;
}

vector<string> ProductManager::parseCSV(istream& file, char delimiter)
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