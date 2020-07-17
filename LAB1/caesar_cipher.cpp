#include<bits/stdc++.h>
using namespace std;
string E(string s)
{
	string e;
	for(int i=0; i<s.length(); i++)
		e.push_back(char('A'+ (s[i]-'A'+3)%26));

	return e;
}
string D(string e)
{
	string p;
	for(int i=0; i<e.length(); i++)
		p.push_back(char('A'+(e[i]-'A'-3+26)%26));
	p.push_back('\0');
	//cout << "Decrypted: " << p << "\n";
	return p;
}
int main()
{
	string s;
	cin >> s;
	
	string encrypted = E(s);
	string decrypted = D(encrypted);
	
	cout << s << " " << encrypted << " " << decrypted <<"\n";
	return 0;
}
