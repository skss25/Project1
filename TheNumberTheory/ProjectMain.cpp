#include<iostream>
#include"NumberTheory.h"
using namespace std;

int main(void)
{
	DATA num1, num2; //�ԷµǴ� ������ ��
	int choice = 0;

	while (1)
	{
		cout << "**********������ ������Ʈ**********"			<< endl;
		cout << "1. ��Ŭ���� �˰���"							<< endl;
		cout << "2. ����� ��� �����Ǵ��� �Ǵ�"				<< endl;
		cout << "3. �ִ����� �˰���"						<< endl;
		cout << "4. Ȯ��� ��Ŭ���� �˰���"					<< endl;
		cout << "0. ȭ�� �����"								<< endl;
		cout << "(����: -1)>> ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			InputTwoData(num1, num2);
			Euclid_Algorithm(num1, num2);
			break;
		case 2:
			InputTwoData(num1, num2);
			divisor_multiple(num1, num2);
			break;
		case 3:
			InputTwoData(num1, num2);
			get_gcd(num1, num2);
			break;
		case 4:
			InputTwoData(num1, num2);
			Ext_Euc_Algorithm(num1, num2);
			break;
		case 0:
			system("cls");
			break;
		case -1:
			cout << "���α׷��� �����մϴ�." << endl;
			return 0;
		default:
			cout << "�߸��� �Է��Դϴ�." << endl << endl;
			break;
		}
	}
	return 0;
}


