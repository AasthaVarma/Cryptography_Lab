#include<bits/stdc++.h>
using namespace std;
 // Question 2
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

string divide_rem(string a, string b)
{
	string s[2] = {"", ""};
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
	c.erase(0, 1);//c is remainder.
	return c;
}

string add_diff(string p, string b)
{
	string a = p;
	string res= "";
	for(int i=0; i<b.length()-a.length(); i++)
		res.push_back('0');
		
	res.append(a);
	a = res;
	
	res = "";
	int c = 0;
	for(int i=a.length()-1; i>=0; i--)
	{
		int q = (a[i]-'0')^(b[i]-'0');
		char p = q+'0';
		//cout << a[i] << " " << b[i] <<" " << c << " " << p << "\n";
		res.push_back(p);
	}
	reverse(res.begin(), res.end());
	return res;
}

string multiply(string a, string b)
{
	string res= "";
	for(int i=0; i<a.length(); i++)
		res.push_back('0');
	string c, d=res;
	int shift = 0;
	for(int i=b.length()-1; i>=0; i--)
	{
		if(b[i]=='0')
			c = d;
		else
			c = a;
		for(int j=1; j<=shift; j++)
			c.push_back('0');
		cout << res << " + " << c << " = ";
		res = add_diff(res, c);
		cout << res << "\n";
		shift++;
	}
	//cout << res << "\n";
	return res;
}

string mul(string a, string b, string ir)
{
	string m = multiply(b, a);
	return divide_rem(m, ir);
}
int main()
{
	string a = "100110";
	string b = "10011110";
	
	string ir = "100011011";
	
	cout << mul(a, b, ir);
	
	return 0;
}
