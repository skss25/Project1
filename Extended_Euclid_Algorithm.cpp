#include<iostream>
#include<iomanip>
using namespace std;

int Ext_Euc_Al(int a, int b, int &ps, int &pt);

int main(void)
{
	int a = 0, b = 0; 
	int s = 0, t = 0; //d=(a*s)+(b*t)
	int d = 0;

	cout << "�� ������ �Է��Ͻʽÿ�: ";
	cin >> a >> b;

	d = Ext_Euc_Al(a, b, s, t);

	cout << "-------------------------------------" << endl;
	//"�ִ����� gcd(a, b) : a(s) + b(t) = d"
	cout << "�ִ����� gcd(a, b) : " << a << "(" << s << ")" << " + ";
	cout << b << "(" << t << ")" << " = " << d << endl; 
	//s, t : ����, ����
	cout << "s, t : " << s << ", " << t << endl;
	return 0;
}

int Ext_Euc_Al(int a, int b, int &ps,  int &pt)
{
	int r;

	int q;
	int s, s1 = 1, s2 = 0;
	int t, t1 = 0, t2 = 1;

	cout << "q";
	cout.width(4); cout << "a";  cout.width(4); cout << "b"; cout.width(4); cout << "r";
	cout.width(4); cout << "s1"; cout.width(4); cout << "s2"; cout.width(4); cout << "s";
	cout.width(4); cout << "t1"; cout.width(4); cout << "t2"; cout.width(4); cout << "t"<< endl;

	while (1)
	{
		q = a / b;
		r = a % b;

		cout << q; cout.width(4); cout << a; cout.width(4); cout << b; cout.width(4); cout << r;

		a = b;
		b = r;
		//(a,b) -> (b,r)

		//s�� ���ϱ�
		s = s1 - (s2*q);
		t = t1 - (t2*q);
		
		cout.width(4); cout << s1; cout.width(4); cout << s2; cout.width(4); cout << s;
		cout.width(4); cout << t1; cout.width(4); cout << t2; cout.width(4); cout << t << endl;

		s1 = s2;
		s2 = s;

		//t�� ���ϱ�
		t1 = t2;
		t2 = t;

		if (b == 0) //������ 0�̸� �������� �ִ�����
		{
			q = 0; //0���� �������� ������� ���� �߻�(����ó���ؾ��ҵ�)
			s = s1 - (s2*q); 
			t = t1 - (t2*q);

			cout << q; cout.width(4); cout << a; cout.width(4); cout << b; cout.width(4); cout << r;
			cout.width(4); cout << s1; cout.width(4); cout << s2; cout.width(4); cout << s;
			cout.width(4); cout << t1; cout.width(4); cout << t2; cout.width(4); cout << t << endl;

			ps = s1;
			pt = t1;

			return a;
		}
	}
}
