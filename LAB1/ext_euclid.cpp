#include<bits/stdc++.h>
using namespace std;

void ext_euclid(int a, int b)
{
	int q, r, s, t;
	int r1, r2, s1, s2, t1, t2;
	//initialisation
	r1 = a; r2 = b; s1 = 1; s2 = 0;	t1 = 0; t2 = 1;
	q = r1/r2;
	r = r1%r2;
	s = s1 - q*s2;
	t = t1 - q*t2;
	cout << r1 << " " << r2 << " " << r << " " << s1 << " " << s2 << " " << s << " " << t1 << " " << t2 << " " << t <<"\n";
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
		 
		cout << r1 << " " << r2 << " " << r << " " << s1 << " " << s2 << " " << s << " " << t1 << " " << t2 << " " << t <<"\n";
	}
	
	cout << r2 << " " << s2 << " " << t2 << "\n";
}
int main()
{
	int a, b;
	cin >> a >> b;
	ext_euclid(a, b);
	return 0;
}
