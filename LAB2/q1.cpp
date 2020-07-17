#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
	if(b==0)
		return a;
	return gcd(b, a%b);
}
int* ext_euclid(int a, int b)
{
	int q, r, s, t;
	int r1, r2, s1, s2, t1, t2;
	//initialisation
	r1 = a; r2 = b; s1 = 1; s2 = 0;	t1 = 0; t2 = 1;
	q = r1/r2;
	r = r1%r2;
	s = s1 - q*s2;
	t = t1 - q*t2;
	//cout << r1 << " " << r2 << " " << r << " " << s1 << " " << s2 << " " << s << " " << t1 << " " << t2 << " " << t <<"\n";
	while(r!=0)
	{
		r1 = r2;
		r2 = r;
		
		s1 = s2;
		s2 = s;
		
		t1 = t2;
		t2 = t;
	
		q = r1/r2;
		r = r1%r2;
		s = s1 - q*s2;
		t = t1 - q*t2; 
		 
		//cout << r1 << " " << r2 << " " << r << " " << s1 << " " << s2 << " " << s << " " << t1 << " " << t2 << " " << t <<"\n";
	}
	int res[2];
	res[0] = s2;
	res[1] = t2;
	//cout << r2 << " " << s2 << " " << t2 << "\n";
	return res;
}
void solve()
{
	int a, b, d;
	cin >> a >> b >> d;
	
	int g;
	if(a>b)
		g = gcd(a, b);
	else
		g = gcd(b, a);
	
	int *res = ext_euclid(a, b);
//	cout << res[0] << " " << res[1] << "\n";

	int s = res[0], t= res[1];
	
	int x0, y0, x[5], y[5];
	x0 = (d/g)*s;
	y0 = (d/g)*t;
	
	for(int i=0; i<5; i++)
	{
		x[i] = x0 + (i+1)*(b/g);
		y[i] = y0 - (i+1)*(a/g); 
	}
	
	cout << "Particular solution: " << x0 << " " << y0 << "\n";
	cout << "General solution: \n";
	for(int i=0; i<5; i++)
		cout << x[i] << " " << y[i] << "\n";
}
int main()
{
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0; 
}
