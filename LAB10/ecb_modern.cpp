#include<bits/stdc++.h>
using namespace std;

string _xor_(string key, string block)
{
	string x ="";
	for(int i=0; i<4; i++)
	{
		x.push_back(char(key[i]^block[i]));
	}
	return x;
}
string encrypt(string key, string blocks[])
{
	string e = "";
	int k=0;
	for(int i=0; i<4; i++)
	{
		string x = _xor_(key.substr(k, 4), blocks[i]);
		k+=4;
		cout << blocks[i] << ": " << x << endl;
		e += x;
	}
	return e;
}
string decrypt(string key, string blocks)
{
	string d = "";
	for(int i=0; i<blocks.length(); i+=4)
	{
		d += _xor_(key.substr(i,4), blocks.substr(i, 4));
	}
	return d;
}
int main()
{
	string s = "MONDAYMORNING";
	int n = s.length();
	int k = (n%4==0)?n/4: n/4+1;
	k=k*4;
	while(k!=n)
	{
		s.push_back('X');
		k--;
	}
	cout << s << "\n";
	string blocks[4];
	string x;
	k=0;
	for(int i=0; i<n; i+=4)
	{
		x = "";
		x.push_back(s[i]);
		x.push_back(s[i+1]);
		x.push_back(s[i+2]);
		x.push_back(s[i+3]);
		
		blocks[k++] = x;
	}
	for(int i=0; i<4; i++)
		cout << blocks[i] << " ";
	cout << endl;	
	
	
	string key = "";
	for(int i=0; i<16; i++)
		key.push_back(i+'0');
	cout << "key: "<< key << endl;
	string e = encrypt(key, blocks);
	cout << "Encrypted: " << e << endl;
	string d = decrypt(key, e);
	cout << "Decrypted: "<< d << endl;
	return 0;
}
