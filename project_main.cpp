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

//�� ����
class Account
{
private:
	char * name;			//�̸�
	int number;				//���¹�ȣ
	int balance;			//�ܾ�

public:
	Account(void) :name(NULL), number(0), balance(0) { /*empty*/ }

	Account(char * name, int number) //���°���
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
		cout << "1. ���°���" << endl;
		cout << "2. �Ա�" << endl;
		cout << "3. ���" << endl;
		cout << "4. �������� ��ü ���" << endl;
		cout << "5. ����� �����" << endl;
		cout << "6. ���α׷� ����" << endl;
		cout << "����: ";
		cin >> choice;
		
		return choice;
	}

	bool GetAccInfo(char * name);
	bool CreateAcc(void); //���� ����
	bool Deposit(void);//�Ա�
	bool WithDraw(void);//���
	void ShowAllAcc(void);//��ü�� �ܾ���ȸ

	void ShowAccNum(void) const {
		cout << "���࿡ �����ϴ� ������ ������ " << numOfAcc << "�� �Դϴ�." << endl;
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
				cout << "���°� �����Ǿ����ϴ�." << endl;
			break;
		case BANK_FUNCTION::DEPOSIT:
			if (bank1.Deposit())
				cout << "�Ա��� �Ϸ��Ͽ����ϴ�." << endl;
			break;
		case BANK_FUNCTION::WITHDRAW:
			if (bank1.WithDraw())
				cout << "����� �Ϸ��Ͽ����ϴ�." << endl;
			break;
		case BANK_FUNCTION::SHOW_ALL_AC:
			bank1.ShowAllAcc();
			cout << "����Ͻðڽ��ϱ�? (Y or N) : ";
			cin >> answer;
			if (answer == 'N' || answer == 'n')
			{
				cout << "���α׷��� �����մϴ�." << endl;
				return 0;
			}
			break;
		case BANK_FUNCTION::CLEAR_SCREEN:
			system("cls");
			break;
		case BANK_FUNCTION::Exit:
			cout << "���α׷��� �����մϴ�." << endl;
			return 0;
		default:
			cout << "�߸��� �Է��Դϴ�." << endl;
			cout << "����Ͻðڽ��ϱ�? (Y or N) : ";
			cin >> answer;
			if (answer == 'N' || answer == 'n')
			{
				cout << "���α׷��� �����մϴ�." << endl;
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
		if (!strcmp(acc[i]->GetAccName(), name)) //Ž������
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
		cout << "�� �̻� ���¸� ���� �� �����ϴ�." << endl;
		return false;
	}

	char acc_name[NAME_NUM];
	int acc_number;

	cout << "���� ������ �̸�: "; cin >> acc_name;
	cout << "���� ��ȣ: "; cin >> acc_number;

	//���� ����
	acc[numOfAcc] = new Account(acc_name, acc_number);
	numOfAcc++;

	return true;
}

bool Bank_System::Deposit(void)
{
	char name[NAME_NUM];
	int money;

	cout << "�Ա��Ͻ� ���� �����ڸ��� �Է��Ͻʽÿ� : ";
	cin >> name;

	if (!Bank_System::GetAccInfo(name))
	{
		cout << "�Է��Ͻ� �̸��� �ش��ϴ� ������ �������� �ʽ��ϴ�." << endl;
		return false;
	}

	cout << "�ݾ��� �Է��Ͽ� �ֽʽÿ� : ";
	cin >> money;

	target->GetMoney(money);

	cout << "���� ������ : " << target->GetAccName() << endl;
	cout << "���� ��ȣ : " << target->GetAccNum() << endl;
	cout << "���� �ܾ� : " << target->GetAccBal() << endl;

	return true;
}

bool Bank_System::WithDraw()//���
{
	char name[NAME_NUM];
	int money;

	cout << "����Ͻ� ���� �����ڸ��� �Է��Ͻʽÿ� : ";
	cin >> name;

	if (!Bank_System::GetAccInfo(name))
	{
		cout << "�Է��Ͻ� �̸��� �ش��ϴ� ������ �������� �ʽ��ϴ�." << endl;
		return false;
	}

	cout << "����� �ݾ��� �Է��Ͽ� �ֽʽÿ� : ";
	cin >> money;

	target->GiveMoney(money);

	cout << "���� ������ : " << target->GetAccName() << endl;
	cout << "���� ��ȣ : " << target->GetAccNum() << endl;
	cout << "���� �ܾ� : " << target->GetAccBal() << endl;

	return true;
}


void Bank_System::ShowAllAcc(void)//��ü�� �ܾ���ȸ
{
	system("cls");
	cout << "<��ü ���� �ܾ��� ��ȸ�մϴ�.>" << endl;
	cout << "--------------------------------" << endl;
	for (int i = 0; i < numOfAcc; i++)
	{
		cout << "Number: " << i << endl;
		cout << "������: " << acc[i]->GetAccName() << endl;
		cout << "���¹�ȣ: " << acc[i]->GetAccNum() << endl;
		cout << "�ܾ�: " << acc[i]->GetAccBal() << endl;
		cout << "------------------------------" << endl;
	}
}
