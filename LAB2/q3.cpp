#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
	if(b==0)
		return a;
	return gcd(b, a%b);
}
int inv(int a, int n)
{
	for(int i=1; i<n; i++)
	{
		if((a*i)%n==1)
			return i;
	}
}
int solve()
{
	int a, b, n;
	cin >> a >> b >> n;
	
	int d;
	if(a<b) 
		d = gcd(n, a);
	else
		d = gcd(a, n);
	
	if(b%d==0)
	{
		int x[d];
		cout << "There exists solution\n";
		cout << "gcd: " << d << "\n";
		int inverse = inv(a/d, n/d);
		cout << "Inverse: " << inverse << "\n";
		x[0] = ((b/d)*inverse)%n;
		for(int i=1; i<d; i++)
		{
			x[i] = x[0] + i*(n/d);
		}
		for(int i=0; i<d; i++)
			cout << x[i] << " ";
		cout << "\n"; 
	}
	else
		cout << "No solution\n";
}
int main()
{
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
