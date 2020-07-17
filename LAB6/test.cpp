#include<bits/stdc++.h>
using namespace std;

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
int main()
{
	string a = "111";
	string b = "11";
	
	cout << add_diff("11", multiply(a, b));
	return 0;
}

