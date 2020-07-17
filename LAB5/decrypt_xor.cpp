#include<bits/stdc++.h>
using namespace std;

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
		cout << (k^key) <<" ";
		d.push_back(char(k^key));
	}
	return d;
}
char find_key(string s, string e)
{
	for(int i=0; i<26; i++)
	{
		char d;
		char key = char('A'+ i);
		int k = 0;
		k = e[0]-'0';
		if(e.length()>1)
		k = k*10 + e[1]-'0';
		
		d = char(k^key);
		if(d==s[0])
			return key;
	}
}
char find_key2(string s, string e)
{
	return char(s[0]^ (e[0]*10+e[1]));
}
int main()
{
	//string e = "17282121221422112129";
	//char key = 'Y';

	/*string e = "01102910089696";
	char key = 'K';
	
	string d = decrypt(e, key);
	cout << "\n" << d ;
	*/
	
	//string s = "NITRKL";
	//string e = "221712101920";
	
	//string s = "COMPUTER";
	//string e = "172931276230";
	
	//char key = find_key(s, e);
	//cout << key << "\n";
	
	string e = "19272716";
	for(int i=0; i<25; i++)
	{
		char key = char('A'+i);
		string d ="";
		for(int i=0; i<e.length(); i+=2)
		{
			int k=0;
			k = e[i]-'0';
			k = k*10 + e[i+1]-'0';
			d.push_back(char(k^key));
		}
		cout << key << " " << d << "\n";
	}
	return 0;
}
