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
string encrypt(string xyz, string key, string blocks[])
{
	int k=0;
	string e = "";
	string cipher[4];
	for(int i=0; i<4; i++)
	{
		string x = _xor_(xyz, blocks[i]);
		cipher[i] = _xor_(key.substr(k,4), x);
		k += 4;
		xyz = cipher[i];
		//cout << i << ": " << x << endl;
		e += cipher[i];
	}
	return e;
}
string decrypt(string xyz, string key, string blocks)
{
	string d = "";
	string plain[4];
	int k=0;
	for(int i=0; i<blocks.length(); i+=4)
	{
		string x = _xor_(key.substr(i,4), blocks.substr(i, 4));
		plain[k] = _xor_(xyz, x);
		xyz = blocks.substr(i, 4); 
		d += plain[k];
		k++;
	}
	return d;
}
int main()
{
	string s = "HAPPYINNOVISION";
	int n = s.length();
	int k = (n%4==0)?n/4: n/4+1; k=k*4;
	while(k!=n)
	{
		s.push_back('X');
		k--;
	}
	cout << "New string: " << s << "\n";
	string blocks[4], x;
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
	string xyz = "5678";
	cout << "key: "<< key << endl;
	cout << "IV: " << xyz << endl;
	
	string e = encrypt(xyz, key, blocks);
	cout << "Encrypted:" << e << endl;
	string d = decrypt(xyz, key, e);
	cout << "Decrypted:" << d << endl;
	
	return 0;
}
