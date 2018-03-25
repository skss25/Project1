#include<iostream>
#include"NumberTheory.h"
using namespace std;

void InputTwoData(DATA & n1, DATA & n2)
{
	int temp = 0;
	cout << "입력: ";
	cin >> n1 >> n2;
	
	if (n1 < n2)
	{
		temp = n1;
		n1 = n2;
		n2 = n1;
	}
}

void Euclid_Algorithm(int a, int b)
{
	int r;
	int A = a, B = b;

	cout << endl; cout << "유클리드 알고리즘" << endl;
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
}


void divisor_multiple(int num1, int num2)
{
	cout << endl; cout << "약수와 배수 성립되는지 판단" << endl;
	if (num1 % num2 == 0)
		printf("약수와 배수의 관계가 성립됩니다.\n\n");
	else
		printf("약수와 배수의 관계가 성립되지 않습니다.\n\n");
}

void get_gcd(int num1, int num2)
{
	int temp;
	cout << endl; cout << "최대공약수 알고리즘" << endl;
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

void Ext_Euc_Algorithm(int a, int b)
{
	
	int A = a, B = b;

	int r, q;
	int s, s1 = 1, s2 = 0;
	int t, t1 = 0, t2 = 1;
	cout << endl; cout << "확장된 유클리드 알고리즘" << endl; cout << "q";
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
}
