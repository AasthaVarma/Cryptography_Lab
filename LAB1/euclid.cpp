#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	if(b==0)
		return a;
	return gcd(b, a%b);
}

int main()
{
	int a, b;
	cin >> a >> b;
	if(a>b)
	{
		int t = a;
		a = b;
		b = t;
	}
	cout << gcd(a, b) << "\n";
	return 0;
}

