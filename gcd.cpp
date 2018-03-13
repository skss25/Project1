//최대공약수구하기

//Greatest Common Divisor By Division Relation
int GetGCDivisor(int a, int b)
{
	int gcd = 0;
	int r;

	while (1)
	{
		r = a % b;
		a = b;
		b = r;
		//(a,b) -> (b,r)

		if (b == 0)
		{
			gcd = a;
			return gcd;
		}
	}
}
