#include<iostream>
#include"NumberTheory.h"
using namespace std;

void ProjectInterface(void) //프로젝트 앱 목록 
{
	int choice;

	while (1)
	{
		cout << "**********정수론 프로젝트**********" << endl;
		cout << "1. 정수" << endl;
		cout << "2. 합동식" << endl;
		cout << "3. 합동식과 암호" << endl;
		cout << "4. 페르마와 오일러 정리" << endl;
		cout << "5. 원시근" << endl;
		cout << "6. 이차잉여" << endl;
		cout << "0. 화면 지우기" << endl;
		cout << "(Enter the number, -1, to exit the program)" << endl;
		cout << ">> ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			system("cls");
			IntegerContents();
			break;
		case 2:
			cout << "준비중.. " << endl << endl;
			break;
		case 3:
			cout << "준비중.. " << endl << endl;
			break;
		case 4:
			cout << "준비중.. " << endl << endl;
			break;
		case 5:
			cout << "준비중.. " << endl << endl;
			break;
		case 6:
			cout << "준비중.. " << endl << endl;
			break;
		case 0:
			system("cls");
			break;
		case -1:
			return;
		default:
			break;
		}
	}
}

void IntegerContents(void)
{
	int choice;
	PDATA data = NULL; //입력값 배열
	int s, t;

	while (1)
	{
		cout << "**********정수론 프로젝트**********"				<< endl;
		cout << "1. 유클리드 알고리즘"								<< endl;
		cout << "2. 약수와 배수 성립되는지 판단"					<< endl;
		cout << "3. 최대공약수 알고리즘"							<< endl;
		cout << "4. 확장된 유클리드 알고리즘"						<< endl;
		cout << "5. 선형 디오판투스 방정식 구하기"					<< endl;
		cout << "0. 화면 지우기"									<< endl;
		cout << "(Enter the number, -1, to move to Main Interface)" << endl;
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
			Exp_Euc_Algorithm(data[0], data[1], s, t);
			break;
		case 5:
			InputData(&data, 3);
			Diophantus(data[0], data[1], data[2]);
			break;
		case 0:
			system("cls");
			break;
		case -1:
			system("cls");
			return;
		default:
			cout << "잘못된 입력입니다." << endl << endl;
		}
	}
}

void InputData(PDATA* data, int n) 
{
	int temp = 0;
	*data = new DATA[n];
	
	cout << "입력: ";
	for (int i = 0; i < n; i++) {
		cin >> (*data)[i];
	}

	if (n == 2) {
		if ((*data)[0] < (*data)[1])
		{
			temp = (*data)[0];
			(*data)[0] = (*data)[1];
			(*data)[1] = temp;
		}
	}
}
//정수
int Euclid_Algorithm(int a, int b)
{
	int r;
	int A = a, B = b;

	cout << "gcd(" << a << ", " << b << ")" << endl;

	while (b!=0)
	{
		r = a % b;
		a = b;
		b = r;
		cout << "gcd(" << a << ", " << b << ")" << endl;
		//(a,b) -> (b,r)
	}

	cout << "gcd(" << A << ", " << B << ") = " << a << endl << endl;
	return a;
}

bool Divisor_Multiple(int num1, int num2)
{
	if (num1 % num2 == 0) {
		cout << "-약수와 배수의 관계가 성립-" << endl << endl;
		return true;
	}
	else {
		cout << "-약수와 배수의 관계가 성립되지 않음-" << endl << endl;
		return false;
	}
}

void Get_Gcd(int num1, int num2)
{
	int temp;
	cout << endl;
	cout << "(" << num1 << ", " << num2 << ")" << endl;

	while (num2 != 0)
	{
		num1 = num1 - num2;

		if (num1 < num2)
		{
			temp = num1;
			num1 = num2;
			num2 = temp;
		}
		cout << "(" << num1 << ", " << num2 << ")" << endl;
	}
	cout << "최대공약수는 " << num1 << "입니다." << endl << endl;
}

int Exp_Euc_Algorithm(int a, int b, int &sValue, int &tValue)
{
	
	int A = a, B = b;

	int r, q;
	int s, s1 = 1, s2 = 0;
	int t, t1 = 0, t2 = 1;
	cout << "q";
	cout.width(4); cout << "a";  cout.width(4); cout << "b"; cout.width(4); cout << "r";
	cout.width(4); cout << "s1"; cout.width(4); cout << "s2"; cout.width(4); cout << "s";
	cout.width(4); cout << "t1"; cout.width(4); cout << "t2"; cout.width(4); cout << "t" << endl;

	while (b != 0)
	{
		q = a / b;
		r = a % b;

		//s, t값 구하기
		s = s1 - (s2*q);
		t = t1 - (t2*q);

		cout << q; cout.width(4); cout << a; cout.width(4); cout << b; cout.width(4); cout << r;
		cout.width(4); cout << s1; cout.width(4); cout << s2; cout.width(4); cout << s;
		cout.width(4); cout << t1; cout.width(4); cout << t2; cout.width(4); cout << t << endl;

		//(a,b) -> (b,r)
		a = b;
		b = r;

		//s2->s1, s->s2
		s1 = s2;
		s2 = s;
		//t2->t1, t->t2
		t1 = t2;
		t2 = t;
	}

	cout.width(5); cout << a; cout.width(4); cout << b;
	cout.width(8); cout << s1; cout.width(4); cout << s2; cout.width(4);
	cout.width(8); cout << t1; cout.width(4); cout << t2; cout.width(4); cout << endl;


	cout << "--------------------------------------" << endl;
	//"최대공약수 gcd(a, b) : a(s) + b(t) = d"
	cout << "최대공약수 gcd(a, b) : " << A << "(" << s1 << ")" << " + ";
	cout << B << "(" << t1 << ")" << " = " << a << endl;
	//s, t : 정수, 정수
	cout << "s, t : " << s1 << ", " << t1 << endl<<endl;

	sValue = s1;
	tValue = t1;
	return a;
}

bool Diophantus(int a, int b, int c)
{
	char * exp = new char[EXP_LEN];
	char * InitExp = new char[EXP_LEN]; //초기방정식

	sprintf(exp, "%dx + %dy = %d", a, b, c); strcpy(InitExp, exp);
	cout << "0. 부정방정식: " << exp << endl << endl;
	
	cout << "1. 최대공약수(d)와 s, t값을 구한다." << endl;
	int d = 0, s, t;
	d = Ext_Euc_Algorithm(a, b, s, t);
	cout << "2. " << d << "와 " << c << "(이)가 약수, 배수 관계인지 확인한다." << endl;
	if (!Divisor_Multiple(c, d))
		return false;

	char * x = new char[10];
	char * y = new char[10];

	int m = 0;
	int x0, y0;

	m = c / d;
	sprintf(exp, "%d(%d * %d) + %d(%d * %d) = %d", a, s, m, b, t, m, d);
	cout << "3. 일차결합식: " << exp << endl<<endl;

	x0 = (s * m); y0 = (t * m);
	sprintf(x, "%d + %dk", x0, b / d); sprintf(y, "%d - %dk", y0, a / d);
	cout << "4. " << InitExp << "의 일반해는 다음과 같다." << endl;
	cout << "x = " << x << ", " << "y = " << y << endl << endl;

	return true;
}

//합동식
PDATA Reduced_Residue_System(int m) 
{
	//나머지 집합(완전잉여계) : 음의정수가 아닌 가장 작은 양의 정수
	DATA * data = new DATA[m]; 
	DATA * rrs = NULL; //기약잉여계
	int len = 0;

	for (int i = 0; i < m; i++) {
		data[i] = i;
		if (Euclid_Algorithm(m, i) == 1) {
			len += 1;
		}
	}

	rrs = new DATA[len];
	for (int i = 0; i < m; i++) {
		if (Euclid_Algorithm(m, i) == 1) {
			rrs[i] = i;
		}
	}

	return rrs;
}