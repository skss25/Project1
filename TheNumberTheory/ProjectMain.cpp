#include<iostream>
#include"NumberTheory.h"
using namespace std;

int main(void)
{
	PDATA data = NULL; //�Է°� �迭
	int choice = 0;
	int s, t;

	while (1)
	{
		cout << "**********������ ������Ʈ**********"			<< endl;
		cout << "1. ��Ŭ���� �˰���"							<< endl;
		cout << "2. ����� ��� �����Ǵ��� �Ǵ�"				<< endl;
		cout << "3. �ִ����� �˰���"						<< endl;
		cout << "4. Ȯ��� ��Ŭ���� �˰���"					<< endl;
		cout << "5. ���� ��������� ������ ���ϱ�"				<< endl;
		cout << "0. ȭ�� �����"								<< endl;
		cout << "(Enter the number, -1, to exit the program)"	<< endl;
		cout << ">> ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			InputData(&data, 2);
			Euclid_Algorithm(data[0], data[1]);
			break;
		case 2:
			InputData(&data, 2);
			Divisor_Multiple(data[0], data[1]);
			break;
		case 3:
			InputData(&data, 2);
			Get_Gcd(data[0], data[1]);
			break;
		case 4:
			InputData(&data, 2);
			Ext_Euc_Algorithm(data[0], data[1], s, t);
			break;
		case 5:
			InputData(&data, 3);
			if (!Diophantus(data[0], data[1], data[2]))
				cout << "���� �ذ� �������� �ʴ´�." << endl << endl;
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


