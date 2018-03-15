#include<iostream>
#include<cstring>
using namespace std;

/*
It's for C/C++ Practice

This program provides some bank options
especially, making an account and put money
into the account and withdraw your money from it.

Don't check whether the account number
(It's not string, but int data type) is same or not
Finding an account by Its name
*/

#define ACC_NUM	100
#define NAME_NUM 100

namespace BANK_FUNCTION {
	enum {
		CREATE_ACCOUNT=1,
		DEPOSIT,
		WITHDRAW,
		SHOW_ALL_AC,
		CLEAR_SCREEN,
		Exit
	};
}

//고객 정보
class Account
{
private:
	char * name;			//이름
	int number;				//계좌번호
	int balance;			//잔액

public:
	Account(void) :name(NULL), number(0), balance(0) { /*empty*/ }

	Account(char * name, int number) //계좌개설
		:number(number)
	{
		int len = strlen(name) + 1;
		this->name = new char[len];
		strcpy(this->name, name);

		this->number = number;
		balance = 0;
	}

	char* GetAccName(void)
	{
		return this->name;
	}
	int GetAccNum(void)
	{
		return this->number;
	}
	int GetAccBal(void)
	{
		return this->balance;
	}

	void GetMoney(int money)
	{
		balance += money;
	}

	void GiveMoney(int money)
	{
		balance -= money;
	}

	~Account(void)
	{
		delete name;
	}
};

class Bank_System//control class
{
private:
	Account * acc[ACC_NUM];
	Account * target;
	int numOfAcc;
public:
	Bank_System(void) : numOfAcc(0)
	{
		target = NULL;
	}

	int ShowBankOptions(void)
	{
		int choice;

		cout << "-----Menu-----" << endl;
		cout << "1. 계좌개설" << endl;
		cout << "2. 입금" << endl;
		cout << "3. 출금" << endl;
		cout << "4. 계좌정보 전체 출력" << endl;
		cout << "5. 모니터 지우기" << endl;
		cout << "6. 프로그램 종료" << endl;
		cout << "선택: ";
		cin >> choice;
		
		return choice;
	}

	bool GetAccInfo(char * name);
	bool CreateAcc(void); //계좌 생성
	bool Deposit(void);//입금
	bool WithDraw(void);//출금
	void ShowAllAcc(void);//전체고객 잔액조회

	void ShowAccNum(void) const {
		cout << "은행에 존재하는 계좌의 갯수는 " << numOfAcc << "개 입니다." << endl;
	}
};

int main(void)
{
	Bank_System bank1;
	int option_num;
	char answer;

	while (1)
	{
		option_num = bank1.ShowBankOptions();

		switch (option_num)
		{
		case BANK_FUNCTION::CREATE_ACCOUNT:
			if (bank1.CreateAcc())
				cout << "계좌가 생성되었습니다." << endl;
			break;
		case BANK_FUNCTION::DEPOSIT:
			if (bank1.Deposit())
				cout << "입금을 완료하였습니다." << endl;
			break;
		case BANK_FUNCTION::WITHDRAW:
			if (bank1.WithDraw())
				cout << "출금을 완료하였습니다." << endl;
			break;
		case BANK_FUNCTION::SHOW_ALL_AC:
			bank1.ShowAllAcc();
			cout << "계속하시겠습니까? (Y or N) : ";
			cin >> answer;
			if (answer == 'N' || answer == 'n')
			{
				cout << "프로그램을 종료합니다." << endl;
				return 0;
			}
			break;
		case BANK_FUNCTION::CLEAR_SCREEN:
			system("cls");
			break;
		case BANK_FUNCTION::Exit:
			cout << "프로그램을 종료합니다." << endl;
			return 0;
		default:
			cout << "잘못된 입력입니다." << endl;
			cout << "계속하시겠습니까? (Y or N) : ";
			cin >> answer;
			if (answer == 'N' || answer == 'n')
			{
				cout << "프로그램을 종료합니다." << endl;
				return 0;
			}
			break;
		}

		cout << endl;
	}

	return 0;
}

bool Bank_System::GetAccInfo(char * name)
{
	int len = sizeof(acc) / sizeof(Account);

	for (int i = 0; i < len; i++)
	{
		if (!strcmp(acc[i]->GetAccName(), name)) //탐색성공
		{
			target = acc[i];
			return true;
		}
	}

	return false;
}

bool Bank_System::CreateAcc(void)
{
	if (numOfAcc >= ACC_NUM)
	{
		cout << "더 이상 계좌를 만들 수 없습니다." << endl;
		return false;
	}

	char acc_name[NAME_NUM];
	int acc_number;

	cout << "계좌 소유자 이름: "; cin >> acc_name;
	cout << "계좌 번호: "; cin >> acc_number;

	//계좌 생성
	acc[numOfAcc] = new Account(acc_name, acc_number);
	numOfAcc++;

	return true;
}

bool Bank_System::Deposit(void)
{
	char name[NAME_NUM];
	int money;

	cout << "입금하실 계좌 소유자명을 입력하십시요 : ";
	cin >> name;

	if (!Bank_System::GetAccInfo(name))
	{
		cout << "입력하신 이름에 해당하는 계정이 존재하지 않습니다." << endl;
		return false;
	}

	cout << "금액을 입력하여 주십시요 : ";
	cin >> money;

	target->GetMoney(money);

	cout << "계좌 소유자 : " << target->GetAccName() << endl;
	cout << "계좌 번호 : " << target->GetAccNum() << endl;
	cout << "계좌 잔액 : " << target->GetAccBal() << endl;

	return true;
}

bool Bank_System::WithDraw()//출금
{
	char name[NAME_NUM];
	int money;

	cout << "출금하실 계좌 소유자명을 입력하십시요 : ";
	cin >> name;

	if (!Bank_System::GetAccInfo(name))
	{
		cout << "입력하신 이름에 해당하는 계정이 존재하지 않습니다." << endl;
		return false;
	}

	cout << "출금할 금액을 입력하여 주십시요 : ";
	cin >> money;

	target->GiveMoney(money);

	cout << "계좌 소유자 : " << target->GetAccName() << endl;
	cout << "계좌 번호 : " << target->GetAccNum() << endl;
	cout << "계좌 잔액 : " << target->GetAccBal() << endl;

	return true;
}


void Bank_System::ShowAllAcc(void)//전체고객 잔액조회
{
	system("cls");
	cout << "<전체 고객의 잔액을 조회합니다.>" << endl;
	cout << "--------------------------------" << endl;
	for (int i = 0; i < numOfAcc; i++)
	{
		cout << "Number: " << i << endl;
		cout << "고객성함: " << acc[i]->GetAccName() << endl;
		cout << "계좌번호: " << acc[i]->GetAccNum() << endl;
		cout << "잔액: " << acc[i]->GetAccBal() << endl;
		cout << "------------------------------" << endl;
	}
}
