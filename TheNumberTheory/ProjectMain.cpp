#include<iostream>
#include"NumberTheory.h"
using namespace std;

int main(void)
{
	DATA num1, num2; //입력되는 데이터 값
	int choice = 0;

	while (1)
	{
		cout << "**********정수론 프로젝트**********"			<< endl;
		cout << "1. 유클리드 알고리즘"							<< endl;
		cout << "2. 약수와 배수 성립되는지 판단"				<< endl;
		cout << "3. 최대공약수 알고리즘"						<< endl;
		cout << "4. 확장된 유클리드 알고리즘"					<< endl;
		cout << "0. 화면 지우기"								<< endl;
		cout << "(종료: -1)>> ";
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
			cout << "프로그램을 종료합니다." << endl;
			return 0;
		default:
			cout << "잘못된 입력입니다." << endl << endl;
			break;
		}
	}
	return 0;
}


