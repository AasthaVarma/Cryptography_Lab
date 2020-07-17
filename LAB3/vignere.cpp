#include<bits/stdc++.h>
using namespace std;
int modular(int d, int mod)
{
	d = d%mod;
	while(d<0)
		d = d+ mod;
	return d;
}
string E(string s, string key)
{
	string e="";
	int n = s.length();
	int k = 0;
	for(int i=0; i<n; i++)
	{
		if(k==key.length())
			k=0;
		if(s[i]== ' ')
			e.push_back(' ');
		else
		{
			e.push_back(char((s[i]-'a'+key[k]-'a')%26 + 'A'));
		
			k++;
		}
		
	}
	cout << e << "\n";
	return e;
}
string D(string e, string key)
{
	string d="";
	int n = e.length();
	int k=0;  
	for(int i=0; i<n; i++)
	{
		if(k==key.length())
			k=0;
		
		if(e[i]== ' ')
			d.push_back(' ');
		else
		{
			d.push_back(char(modular(e[i]-'A'-(key[k]-'a'), 26)+'a'));
		
			k++;
		}
		
	}
	cout << d << "\n";
	return d;
}
int main()
{
	string s = "hello";
	string key = "pascal";
	
	string e = E(s, key);
	string d = D(e, key);
	
	cout << s << " " << e << " " << d << "\n";
	return 0;
}
