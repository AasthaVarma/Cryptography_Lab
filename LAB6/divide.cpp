#include<bits/stdc++.h>
using namespace std;

string xor_(string a, string b)
{
	string res="";
	for(int i=0; i<a.length(); i++)
	{
		if(a[i]==b[i])
			res.push_back('0');
		else
			res.push_back('1');
	}
	return res;
}
string* divide(string a, string b)
{
	string q = ""; //q is quotient
	string c = a.substr(0, b.length());
	c = xor_(c, b);
	q.push_back('1');
	string d = "";
	for(int i=0; i<b.length(); i++)
		d.push_back('0');
	for(int i=b.length(); i<a.length(); i++)
	{
		c.erase(0, 1);
		c.push_back(a[i]);
		if(c[0]=='0')
		{
			c = xor_(c, d);
			q.push_back('0');
		}
		else
		{
			c = xor_(c, b);
			q.push_back('1');
		}
	}
	c.erase(0, 1);
	//cout << q << " " << c << endl;
	string s[2] = {q, c};
	//cout << s[0] << " " << s[1] << endl;
	return s;
}

int main()
{
	string a = "10011";
	string b = "101";
	
	string s[2];
	string *q = divide(a, b);

	

	return 0;
}
