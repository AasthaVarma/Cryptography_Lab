#include<bits/stdc++.h>
using namespace std;

string encrypt(string s, int key[])
{
	string e = "";
	for(int i=0; i<5; i++)
	{
		e.push_back(s[key[i]-1]);
	}
	return e;
}

void decKey(int a[], int dk[], int n)
{
	for(int i=0; i<5; i++)
		dk[a[i]-1] = i+1;
}

int main()
{
	string s = "enemyattackstonightz";
	int n = s.length();
	
	int enc_key[] = {3, 2, 1, 5, 4};
	//int dec_key[] = {2, 5, 1, 3, 4};
	
	int dec_key[5];
	decKey(enc_key, dec_key, n);
	string e = "";
	for(int i=0; i<n; i+=5)
	{
		string t = encrypt(s.substr(i, 5), enc_key);
		//cout << s.substr(i, 5) << " " << t << "\n"; 
		e.append(t);
	}
	string d = "";
	for(int i=0; i<n; i+=5)
	{
		string t= encrypt(e.substr(i, 5), dec_key);
		d.append(t);
	}
	cout << s << " " << e << " " << d;
	return 0;
}
