#include "ClientManager.h"
#include "ProductManager.h"
#include "ShoppingManager.h"

int main()
{
	//main 내에 스위치 변수 절대 지우면 안됨
	int L_number, S_number;

	//client cin 정보
	string c_word, c_name, c_phone, c_email;

	//product cin 정보
	string p_id, p_name; int p_price;

	//shopping cin 정보
	string pk_cl, pk_pr; int s_date, s_quan, s_num;

	ClientManager cm;
	ProductManager pm;
	ShoppingManager sm;

	textcolor(WHITE, BLACK);

	//Client Product Shopping 텍스트 불러오기
	cm.Load();
	pm.Load();
	sm.ShoppingListLoad();

	cout << "안녕하십니까? 임플란트 전용 치과 전문 센터 입니다." << endl;
	while (true)
	{
		sm.FindCPrice(cm); //차라리 처음부터 함수를 호출하면 알아서 처리 되지 않을까
		//새로운 사실은 ShoppingManager에서 해당 PK들을 입력후 수량에 따라 가격이 변동되는데
		//이러면 함수안의 계산은 끝났으므로 다른 case문에 접근하지 못함
		//따라서 변경하는 수량에 따른 고객 등급 할인은 함수내에서 코드를 작성해야하는 조건이 주어짐
		cout << "\n아래에 해당하는 번호를 입력하여 원하시는 정보를 활용하십시오." << endl;
		cout << "1. 고객 정보 관리, 2. 상품 정보 관리, 3.구매 정보 관리, 4.종료" << endl;
		cout << "번호를 입력하여 주세요 : "; cin >> L_number;

		if (!cin) //정수형 인자 콘솔 입력부분 경계 검사
		{
			cout << "\n1 ~ 4번 까지 정수형 숫자만 입력가능 합니다." << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}

		switch (L_number)
		{

		//고객 정보 스위치
		case 1:
		client:;
			cout << "\n1.고객 정보 관리" << endl;
			cout << "1.입력, 2.조회, 3.삭제, 4.모두삭제, 5.변경" << endl;
			cout << "해당하는 번호를 입력해주세요 : "; cin >> S_number;

			if (!cin) //정수형 인자 콘솔 입력부분 경계 검사
			{
				cout << "\n고객 정보 관리에 정수형 숫자를 입력하지 않았습니다." << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				goto client;
			}

			switch (S_number)//해당하는 번호를 입력하라는 문구에 번호를 입력하면 고객 정보 입력, 조회, 변경, 삭제 문으로 넘어감
			{
			case 1: 
				cout << "\n고객 정보 입력" << endl;
				cout << "고객 등록 ID : "; cin >> c_word;
				cout << "고객 등록 이름 : "; cin >> c_name;
				cout << "고객 등록 전화번호 : "; cin >> c_phone;
				cout << "고객 등록 이메일 : "; cin >> c_email;
				cm.Client_Input(c_word, c_name, c_phone, c_email);
				break;
			case 2:
				cm.Display();
				break;
			case 3:
				cm.Display();
				cout << "\nID와 성함을 입력하면 정보가 삭제됩니다." << endl;
				cout << "삭제할 고객 ID 입력 : "; cin >> c_word;
				cout << "삭제할 고객 성함을 입력 : "; cin >> c_phone;
				cm.Client_Remove(c_word, c_phone); cout << endl;
				cm.Display();
				break;
			case 4:
				cm.RemoveAll();
				cm.Display();
				break;
			case 5:
				cm.Display();
				cout << "\nID와 성함을 입력하면 정보가 변경됩니다." << endl;
				cout << "변경될 고객 ID를 입력 : "; cin >> c_word;
				cout << "변경될 고객 성함을 입력 : "; cin >> c_name;
				cm.Client_Change(c_word, c_name); cout << endl;
				cm.Display();
				break;
			default:
				cout << "\n입력하신 고객 정보 관리 번호가 없습니다." << endl;
				break;
			}
			break;

		//상품 정보 스위치
		case 2:
		product:;
			cout << "\n2.상품 정보 관리" << endl;
			cout << "1.입력, 2.조회, 3.삭제, 4.모두삭제, 5.변경" << endl;
			cout << "해당하는 번호를 입력해주세요 : "; cin >> S_number;

			if (!cin)//정수형 인자 콘솔 입력부분 경계 검사
			{
				cout << "\n상품 정보 관리에 정수형 숫자를 입력하지 않았습니다." << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				goto product;
			}

			switch (S_number)
			{
			case 1:
			
				cout << "\n상품 정보 입력" << endl;
				cout << "상품 등록 ID : "; cin >> p_id;
				cout << "상품 등록 이름 : "; cin >> p_name;
			product_1:;
				cout << "상품 등록 가격 : "; cin >> p_price;
				if (!cin)//정수형 인자 콘솔 입력부분 경계 검사
				{
					cout << "\n등록 가격에 정수형 숫자를 입력하지 않았습니다." << endl;
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					goto product_1;
				}
				pm.Product_Input(p_id, p_name, p_price);
				break;
			case 2:
				pm.Display();
				break;
			case 3:
				pm.Display();
				cout << "\nID를 입력하면 정보가 삭제됩니다." << endl;
				cout << "삭제할 상품 ID 입력 : "; cin >> p_id;
				pm.Product_Remove(p_id); cout << endl;
				pm.Display();
				break;
			case 4:
				pm.RemoveAll();
				pm.Display();
				break;
			case 5:
				pm.Display();
				cout << "\nID를 입력하면 정보가 변경됩니다." << endl;
				cout << "변경될 상품 ID를 입력 : "; cin >> p_id;
				pm.Product_Change(p_id);
				pm.Display();
				break;
			default:
				cout << "입력하신 상품 정보 관리 번호가 없습니다." << endl;
				break;
			}
			break;


		//구매 정보 스위치
		case 3:
		shopping:;
			sm.sort(); //구매 정보 관리 창에 갈때마다 sort하여 Snumber를 순차적으로 표시
			cout << "\n3.구매 정보 관리" << endl;
			cout << "1.주문, 2.조회, 3.삭제, 4.전체삭제, 5.변경" << endl;
			cout << "번호를 입력해주세요 : "; cin >> S_number;
			if (!cin)//정수형 인자 콘솔 입력부분 경계 검사
			{
				cout << "\n구매 정보 관리에 정수형 숫자를 입력하지 않았습니다." << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				goto shopping;
			}
			switch (S_number)
			{
			case 1:
				cm.Display(); //CLientManager Display호출
				pm.Display(); //ProductManager Display 호출
				cout << "위의 리스트를 보고 해당하는 상품과 고객정보를 입력하세요." << endl;
				cout << "고객의 등록 ID : "; cin >> pk_cl;
				cout << "상품의 등록 ID : "; cin >> pk_pr;
				shopping_1:;
				cout << "구매날짜(예 : 220830, 210578, YYMMDD) : "; cin >> s_date;
				if (!cin)
				{
					cout << "\n구매날짜에 정수형 숫자를 입력하지 않았습니다." << endl;
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					goto shopping_1;
				}
				shopping_2:;
				cout << "구매수량 : "; cin >> s_quan; cout << endl;
				if (!cin)
				{
					cout << "\n구매수량에 정수형 숫자를 입력하지 않았습니다." << endl;
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					goto shopping_2;
				}
				sm.Shopping_Input(cm, pm, sm.getSNumber(), pk_cl,
					pk_pr, s_date, s_quan); cout << endl;
				//sm.FindCPrice(cm);
				break;
			case 2:
				sm.Shopping_Display(cm, pm); cout << endl;
				break;
			case 3:
				sm.Display();
			shopping_3:;
				cout << "\n삭제할 구매 번호를 입력해주세요 : "; cin >> s_num;
				if (!cin || s_num == 0)//정수형 인자 콘솔 입력부분 경계 검사
				{
					cout << "\n번호에 정수형 숫자를 입력하지 않았거나 0번째는 삭제할 수 없습니다." << endl;
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					goto shopping_3;
				}
				sm.Shopping_Remove(s_num); 
				sm.Display();
				//sm.FindCPrice(cm);
				break;
			case 4:
				sm.Shopping_Remove_All(cm);
				sm.Display();
				//sm.FindCPrice(cm);
				break;
			case 5:
			shopping_4:;
				sm.Display();
				cout << "\n변경할 구매 번호를 입력해주세요 : "; cin >> s_num;
				if (!cin)//정수형 인자 콘솔 입력부분 경계 검사
				{
					cout << "\n번호에 정수형 숫자를 입력하지 않았습니다." << endl;
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					goto shopping_4;
				}
				sm.Shopping_Change(s_num, cm, pm);
				sm.Display();
				//sm.FindCPrice(cm);
				break;
			default:
				cout << "입력하신 구매 정보 관리 번호가 없습니다." << endl;
				break;
			}
			break;

		//프로그램 종료 스위치	
		case 4:
			//프로그램 종료시 콘솔에서 실행했던 정보를 저장하는 유무를 정함.
			char push;
			cout << "\n저장후 프로그램을 종료하시겠습니까? (y/n) : "; cin >> push;
			if (push == 'y' || push == 'Y')
			{
				cm.Save();
				pm.Save();
				sm.ShoppingListSave();
				cout << "프로그램 종료!!" << endl << endl;
				exit(1);
				break;
				//콘솔에 저장되어 있는 데이터 및 정보 저장
			}
			cout << "프로그램 종료!!" << endl << endl;
			//저장하지 않고 초기화
			exit(1);
			break;

		default:
			cout << "\n해당 번호가 없습니다!\n" << endl;
			break;
		}
	}

	return 0;
}