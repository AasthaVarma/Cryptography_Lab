#include<bits/stdc++.h>
using namespace std;

//Question 1
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
string divide_quo(string a, string b)
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
	return q;
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
	//length of p is smaller than b.
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
		int q = (a[i]-'0')^(b[i]-'0')^c;
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
		//cout << res << " + " << c << " = ";
		res = add_diff(res, c);
		//cout << res << "\n";
		shift++;
	}
	//cout << res << "\n";
	return res;
}
string add(string a, string b)
{
	
}
int val(string s)
{
	int sum=0, p=1;
	for(int i=s.length()-1; i>=0; i--)
	{
		sum += p*(s[i]-'0');
		p = p*2;
	}
	return sum;
}
string mul_inv(string r1, string r2)
{
	string t1 = "0";
	string t2 = "1";
	string t="", r="1", q="";
	string *s;
	int flag=1;
	//cout << q << " " << r1 << " " << r2 << " " << r << " " << t1 << " " << t2 << " " << t << "\n";
	while(flag)
	{
		cout << "hi!\n";
		q = divide_quo(r1, r2);
		r = divide_rem(r1, r2);
		//cout << "1. " << q << " " << r << "\n";
		string m = multiply(q, t2);
		//cout << "2. " << m << "\n";
		t = add_diff(t1, m);
		//cout << "3. " << t << " " << t1 << " " << t2 << " " << m << "\n\n";
		cout << q << " " << r1 << " " << r2 << " " << r << " " << t1 << " " << t2 << " " << t << "\n\n";
		r1 = r2;
		r2 = r;
		
		t1 = t2;
		t2 = t;
		int cnt=0;
		for(int i=0; i<r.length(); i++)
		{
			if(r[i]=='0')
				cnt++;
		}
		if(cnt==r.length())
			flag=0;
		if(r=="")
			flag=0;
	}
	
	cout << t2 << "\n";
	return t2;
}
int main()
{
	string r2 = "101";
	string r1 = "10011";
	
	string t = mul_inv(r1, r2);
	//cout << val(r1);
	return 0;
}
