#include<bits/stdc++.h>
using namespace std;

string encrypt(string s, char key)
{
	string e ="";
	for(int i=0; i<s.length(); i++)
	{
		e.append(to_string(key^s[i]));
	}
	return e;
}

string decrypt(string e, char key)
{
	string d = "";
	for(int i=0; i<e.length(); i+=2)
	{
		int k = 0;
		k = e[i]-'0';
		if(i+1<e.length())
		k = k*10 + e[i+1]-'0';
		//cout << k <<" ";
		//cout << (k^key) <<" ";
		d.push_back(char(k^key));
	}
	return d;
}
int main()
{
	string s = "HELLO";
	char key = 'P';
	string e = encrypt(s, key);
	string d = decrypt(e, key);
	
	cout << s << " " << e << " " << d;
	return 0;
}
