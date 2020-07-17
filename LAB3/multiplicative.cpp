#include<bits/stdc++.h>
using namespace std;
int inv(int a, int n)
{
	for(int i=1; i<n; i++)
	{
		if((a*i)%n==1)
			return i;
	}
}
int gcd(int a, int b)
{
	if(b==0)
		return a;
	return gcd(b, a%b);
}
string E(string s, int k)
{
	int n = s.length();
	string e = "";
	for(int i=0; i<n; i++)
	{
		if(s[i]== ' ')
			e.push_back(' ');
		else
		{
			int c = ((s[i]-'a')*k)%26;
			e.push_back(char(c+'A'));
		}
	}
	//cout << e << "\n";
	return e;
}
string D(string e, int k)
{
	int n = e.length();
	string d="";
	int k_inv = inv(k, 26);
	for(int i=0; i<n; i++)
	{
		if(e[i]== ' ')
			d.push_back(' ');
		else
		{
			int c = ((e[i]-'A')*k_inv)%26;
			d.push_back(char(c+'a'));
		}
		
	}
	//cout << d << "\n";
	return d;
}
int main()
{
	string s = "hello there";
	int k ;
	cout << "Enter k such that k belongs to [1, 25]:";
	cin >> k;
	int g;
	g = gcd(26, k);
	if(g!=1)
	{
		cout << "k doesn't have any inverse!";
		return 0;
	}
	string e = E(s, k);
	string d = D(e, k);
	cout << s << " " << e << " " << d << "\n";
	return 0;
}
