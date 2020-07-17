#include<bits/stdc++.h>
using namespace std;
string E(string s, int r)
{
	string e;
	for(int i=0; i<s.length(); i++)
		e.push_back(char('A'+ (s[i]-'A'+r)%26));
	e.push_back(char('A'+r));
	//cout << "Encrypted: " << e << "\n";
	return e;
}
string D(string e)
{
	int r = e[e.length()-1]-'A';
	cout << "Decrypted r:" << r << "\n";
	string p;
	for(int i=0; i<e.length()-1; i++)
		p.push_back(char('A'+(e[i]-'A'-r+26)%26));
	p.push_back('\0');
	//cout << "Decrypted: " << p << "\n";
	return p;
}
int main()
{
	string s;
	cin >> s;
	//s = "HELLO";
	srand(time(NULL));	
	int r = rand()%26;
	cout << "Random r: " << r << "\n";
	//int r = 15;
	string encrypted = E(s, r);
	string decrypted = D(encrypted);
	
	cout << s << " " << encrypted << " " << decrypted <<"\n";
	return 0;
}
