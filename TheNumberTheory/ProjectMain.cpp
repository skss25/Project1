#include<iostream>
#include"NumberTheory.h"
using namespace std;

int main(void)
{
	PDATA data = NULL; //입력값 배열
	int choice = 0;
	int s, t;

	while (1)
	{
		cout << "**********정수론 프로젝트**********"			<< endl;
		cout << "1. 유클리드 알고리즘"							<< endl;
		cout << "2. 약수와 배수 성립되는지 판단"				<< endl;
		cout << "3. 최대공약수 알고리즘"						<< endl;
		cout << "4. 확장된 유클리드 알고리즘"					<< endl;
		cout << "5. 선형 디오판투스 방정식 구하기"				<< endl;
		cout << "0. 화면 지우기"								<< endl;
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
				cout << "따라서 해가 존재하지 않는다." << endl << endl;
			break;
		case 0:
			system("cls");
			break;
		case -1:
			cout << "프로그램을 종료합니다." << endl;
			return 0;
		default:
			cout << "잘못된 입력입니다." << endl << endl;
			break;
		}
	}
	return 0;
}


