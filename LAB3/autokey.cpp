#include<bits/stdc++.h>
using namespace std;

int modular(int d, int mod)
{
	d = d%mod;
	while(d<0)
		d = d+ mod;
	return d;
}

string E(string s, int k)
{
	string e="";
	int n = s.length();
	e.push_back(char((s[0]-'a'+k)%26 + 'A'));
	for(int i=1; i<n; i++)
	{
		if(s[i]== ' ')
			e.push_back(' ');
		else
			e.push_back(char((s[i]-'a'+s[i-1]-'a')%26 + 'A'));
	}
	//cout << e << "\n";
	return e;
}

string D(string s, string e, int k)
{
	string d="";
	int n = e.length();
	d.push_back(char(modular((e[0]-'A'-k), 26)+ 'a'));
	for(int i=1; i<n; i++)
	{
		if(e[i]== ' ')
			d.push_back(' ');
		else
			d.push_back(char(modular((e[i]-'A')-(s[i-1]-'a'),26) + 'a'));
	}
	//cout << d << "\n";
	return d;
}
int main()
{
	srand(time(NULL));
	string s = "halqzt";
	int k = rand()%26;
	//int k=4;
	cout << "k: " << k << "\n";
	string e = E(s, k);
	string d = D(s, e, k);
	cout << s << " " << e << " " << d << "\n";
	return 0;
}
