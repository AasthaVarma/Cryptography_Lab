#include<bits/stdc++.h>
using namespace std;

string hex_to_bin(string s)
{
	unordered_map<char, string> mp; 
	mp['0']= "0000"; 
	mp['1']= "0001"; 
	mp['2']= "0010"; 
	mp['3']= "0011"; 
	mp['4']= "0100"; 
	mp['5']= "0101"; 
	mp['6']= "0110"; 
	mp['7']= "0111"; 
	mp['8']= "1000"; 
	mp['9']= "1001"; 
	mp['A']= "1010"; 
	mp['B']= "1011"; 
	mp['C']= "1100"; 
	
	mp['D']= "1101"; 
	mp['E']= "1110"; 
	mp['F']= "1111"; 
	string bin=""; 
	for(int i=0; i<s.size(); i++){ 
		//cout << s[i] << "->" << mp[s[i]] << "\n";
		bin+= mp[s[i]]; 
	} 
	return bin; 
}

string bin_to_hex(string s)
{
	map<string, string> m;
	m["0000"] = "0";
	m["0001"] = "1";
	m["0010"] = "2";
	m["0011"] = "3";
	m["0100"] = "4";
	m["0101"] = "5";
	m["0110"] = "6";
	m["0111"] = "7";
	m["1000"] = "8";
	m["1001"] = "9";
	m["1010"] = "A";
	m["1011"] = "B";
	m["1100"] = "C";
	m["1101"] = "D";
	m["1110"] = "E";
	m["1111"] = "F";
	
	string res = "";
	for(int i=0; i<s.length(); i+= 4)
	{
		string t = "";
		t += s[i];
		t += s[i+1];
		t += s[i+2];
		t += s[i+3];
		
		res += m[t];
	}
	
	return res;
}

string shift_left(string s)
{
	string res = "";
	for(int i=0; i<s.length(); i++)
	{
		res.push_back(s[(i+1)%s.length()]);
	}
	return res;
}

string compression(string s)
{
	int d_box[] = {14, 17, 11, 24, 1, 5, 3, 28,
				   15, 6, 21, 10, 23, 19, 12, 4,
				   26, 8, 16, 7, 27, 20, 13, 2,
				   31, 52, 31, 37, 47, 55, 30, 46,
				   51, 45, 33, 48, 44, 49, 39, 56,
				   34, 53, 46, 42, 50, 36, 29, 32};
				   
	string r = "";
	for(int i=0; i<48; i++)
	{
		r.push_back(s[d_box[i]-1]);
	}
	return r;
} 

void generate_keys(string key, int parity[], string round_key[16])
{
	key = hex_to_bin(key);	
	//cout << key.length() << " " << key << "\n\n";	   
	string new_key = "";
	int n = 56;
	for(int i=0; i<n; i++)
	{
		new_key.push_back(key[parity[i]-1]);
	}
	//cout << new_key.length() << " " << new_key << "\n";
	
	string lh = new_key.substr(0, 28);
	string rh = new_key.substr(28);
	
	//cout << lh.length() << " " << lh << " " << rh.length() << " " << rh << endl;
	
	int num_rounds = 1;
	
	for(int i=1; i<=16; i++)
	{
		if(i==1 || i==2 || i==9 || i==16)
			num_rounds=1;
		else
			num_rounds=2;
		string k = "";
		for(int i=1; i<=num_rounds; i++)
		{
			lh = shift_left(lh);
			rh = shift_left(rh);
			//cout << lh << " " << rh << "\n";
		}
		k += lh;
		k += rh;

		k = compression(k);
		round_key[i-1] = bin_to_hex(k);
		//round_key[i-1] = (k);
		//cout << round_key[i-1] << "\n";
	}
}

int main()
{
	string key = "AABB09182736CCDD";
	string ptext = "123456ABCD132536";
	
	int parity[] = {57, 49, 41, 33, 25, 17, 9, 1,
					58, 50, 42, 34, 26, 18, 10, 2,
					59, 51, 43, 35, 27, 19, 11, 3,
					60, 52, 44, 36, 63, 55, 47, 39,
					31, 23, 15, 7, 62, 54, 46, 38,
					30, 22, 14, 6, 61, 53, 45, 37,
					29, 21, 13, 5, 28, 20, 12, 4};
					
	string round_key[16];				
	generate_keys(key, parity, round_key);
	for(int i=0; i<16; i++)
		cout << "Round " << i+1 << "-" << round_key[i]  << "\n\n";
		
	
	return 0;
}
