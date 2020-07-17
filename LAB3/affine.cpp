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
int modular(int d, int mod)
{
	d = d%mod;
	while(d<0)
		d = d+ mod;
	return d;
}
string E(string s, int k1, int k2)
{
	string e = "";
	int n = s.length();
	int t, c;
	for(int i=0; i<n; i++)
	{
		if(s[i]== ' ')
			e.push_back(' ');
		else
		{
			t = ((s[i]-'a')*k1)%26;
			c = (t+k2)%26;
		
			e.push_back(char(c+'A'));
		}
		
	}
	//cout << e << "\n";
	return e;
}

string D(string e, int k1, int k2)
{
	string d = "";
	int n = e.length();
	int p, t;
	int k1_inv = inv(k1, 26);
	int k2_inv = k2;
	for(int i=0; i<n; i++)
	{
		if(e[i]== ' ')
			d.push_back(' ');
		else
		{
			t = modular((e[i]-'A'-k2), 26);
			p = (t*k1_inv)%26;
			d.push_back(char(p+'a'));	
		}
		
	}
	//cout << d << "\n";
	return d;
}
int main()
{
	string s = "hello there";
	int k1;// = 15;
	int k2;// = 4;
	cout << "Enter k1 and k2: ";
	cin >> k1 >> k2;
	int g;
	g = gcd(26, k1);
	if(g!=1)
	{
		cout << "k1 doesn't have any inverse!";
		return 0;
	}
	string e = E(s, k1, k2);
	string d = D(e, k1, k2);
	cout << s << " " << e << " " << d << "\n";
	return 0;
}
