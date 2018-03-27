#include<iostream>
#include"NumberTheory.h"
using namespace std;

void InputData(PDATA* data, int n) 
{
	int temp = 0;
	*data = new DATA[n];
	
	cout << "�Է�: ";
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
		cout << "-����� ����� ���谡 ����-" << endl << endl;
		return true;
	}
	else {
		cout << "-����� ����� ���谡 �������� ����-" << endl << endl;
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
	cout << "�ִ������� " << num1 << "�Դϴ�." << endl << endl;
}

int Ext_Euc_Algorithm(int a, int b, int &sValue, int &tValue)
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

		//s, t�� ���ϱ�
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
	//"�ִ����� gcd(a, b) : a(s) + b(t) = d"
	cout << "�ִ����� gcd(a, b) : " << A << "(" << s1 << ")" << " + ";
	cout << B << "(" << t1 << ")" << " = " << a << endl;
	//s, t : ����, ����
	cout << "s, t : " << s1 << ", " << t1 << endl<<endl;

	sValue = s1;
	tValue = t1;
	return a;
}

bool Diophantus(int a, int b, int c)
{
	char * exp = new char[EXP_LEN];
	char * InitExp = new char[EXP_LEN]; //�ʱ������

	sprintf(exp, "%dx + %dy = %d", a, b, c); strcpy(InitExp, exp);
	cout << "0. ����������: " << exp << endl << endl;
	
	cout << "1. �ִ�����(d)�� s, t���� ���Ѵ�." << endl;
	int d = 0, s, t;
	d = Ext_Euc_Algorithm(a, b, s, t);
	cout << "2. " << d << "�� " << c << "(��)�� ���, ��� �������� Ȯ���Ѵ�." << endl;
	if (!Divisor_Multiple(c, d))
		return false;

	char * x = new char[10];
	char * y = new char[10];

	int m = 0;
	int x0, y0;

	m = c / d;
	sprintf(exp, "%d(%d * %d) + %d(%d * %d) = %d", a, s, m, b, t, m, d);
	cout << "3. �������ս�: " << exp << endl<<endl;

	x0 = (s * m); y0 = (t * m);
	sprintf(x, "%d + %dk", x0, b / d); sprintf(y, "%d - %dk", y0, a / d);
	cout << "4. " << InitExp << "�� �Ϲ��ش� ������ ����." << endl;
	cout << "x = " << x << ", " << "y = " << y << endl << endl;

	return true;
}
