#include<bits/stdc++.h>
using namespace std;
map<char, string> m;
void permute(int a[], int i, int n, int &cnt)
{
	if(cnt==26)
		return;
	if(i==n)
	{
		string s = "";
		for(int i=0; i<n; i++)
			s.push_back((a[i]+'0'));
		char c = char('A'+cnt);
		
		m[c] = s;
		cnt++;
		return;
	}
	a[i] = 0;
	permute(a, i+1, n, cnt);
	a[i] = 1;
	permute(a, i+1, n, cnt);
}
void shift(int a[], int n)
{
	for(int i=0; i<n-1; i++)
	{
		a[i] = a[i+1];
	}
}
int func1(int a[], int n)
{
	//cout << a[4] << " " << a[2] << " " << a[0] << " = " << ((a[4]^a[2]) ^ a[0]) << "\n";
	return ((a[4]^a[2]) ^ a[0]);
}
void print(int a[], int n)
{
	for(int i=n-1; i>=0; i--)
		cout << a[i] << " ";
	cout << "\n";
}


int main()
{
	int n = 5;
	int a[n] = {0, 0, 0, 0, 0};
	int cnt=0;
	permute(a, 0, n, cnt);
	for(auto i = m.begin(); i!=m.end(); i++)
		cout << (*i).first << " " << (*i).second << "\n";
	cout << "\n";	
	
/*	string s = "CG";
	string str="";
	for(int i=0; i<s.length(); i++)
	{
		str.append(m[s[i]]);
	}
*/	
	string str = "1111111111";
	int b[n] ={1, 0, 0, 0, 1};
	cout << str << "\n";
	vector<int> vec;
	int x;	
	for(int i=0; i<20; i++)
	{
		x = func1(b, n);
		vec.push_back(x);
		shift(b, n);
		b[n-1] = x;
	}
	string e = "";
	for(int i=0; i<str.length(); i++)
	{
		e.push_back(((str[i]-'0')^vec[i])+'0');
	}
	cout << e << "\n";
	string d = "";
	for(int i=0; i<str.length(); i++)
	{
		d.push_back(((e[i]-'0')^vec[i])+'0');
	}
	cout << d << "\n";
	return 0;
}
