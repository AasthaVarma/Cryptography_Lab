#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> w)
{
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			cout << w[i][j];
		}
		cout << "\t";
	}
	cout << "\n";
}
void _xor_(vector<int> &a, vector<int> &b)
{
	//vector<>
	for(int i=0; i<4; i++)
	{
		b[i] = int_to_hex(b[i]^a[i]);
	}
}
int main()
{
	int key[16] = {0x24, 0x75, 0xA2, 0xB3,
	               0x34, 0x75, 0x56, 0x88, 
				   0x31, 0xE2, 0x12, 0x00, 
				   0x13, 0xAA, 0x54, 0x87};
				   
	int round_const[10] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1B, 0x36};
	
	vector<vector<int> > w(4, vector<int>(4));
	int k=0;
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			w[i][j] = key[k];
			k++;
		}
	}
	//print the words.
	print(w);
	
	
	for(int round=1; round<=10; round++)
	{
		vector<int> t = generate(w[3]);
		_xor_(t, w[0]);
		_xor_(w[0], w[1]);
		_xor_(w[1], w[2]);
		_xor_(w[2], w[3]);
		
		print(w);
	}
	return 0;
}
