#include<bits/stdc++.h>
using namespace std;

string encrypt(string s, map<char, char>m)
{
	string e="";
	for(int i=0; i<s.length(); i++)
	{
		e.push_back(m[s[i]]);
	}
	return e;
}
string decrypt(string e, map<char, char>m)
{
	string d="";
	for(int i=0; i<e.length(); i++)
	{
		d.push_back(m[e[i]]);
	}
	return d;
}
int main()
{
	string s = "CODINGISFUN";
	string temp;
	string e_key = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	temp = e_key;
	reverse(temp.begin(), temp.end());
	string d_key = temp;
	//cout << e_key << "\n" << d_key;
	map<char, char> m;
	for(int i=0; i<e_key.length(); i++)
		m[e_key[i]] = d_key[i];
	
	string e = encrypt(s, m);
	string d = decrypt(e, m);
	
	cout << s <<" " << e << " " << d;
	
	return 0;
}
