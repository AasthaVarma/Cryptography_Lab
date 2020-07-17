//this program only deals with unique characters in stringi.e., no repeat of same characters at a time.
#include<bits/stdc++.h>
#define n1 5
using namespace std;
int modular(int d, int mod)
{
	d = d%mod;
	while(d<0)
		d = d+ mod;
	return d;
}
void print(char a[n1][n1])
{
	for(int i=0; i<n1; i++)
	{
		for(int j=0; j<n1; j++)
			cout << a[i][j] << " ";
		cout << "\n";
	}
}

void position(int res[], char c[n1][n1], char s)
{
	if(s=='J')
		s = 'I';
	for(int i=0; i<n1; i++)
	{
		for(int j=0; j<n1; j++)
		{
			if(c[i][j]==s)
			{
				res[0] = i;
				res[1] = j;
				return ;
			}
		}
	}
}

string E(char c[n1][n1], string s, int a[], int k)
{
	string e ="";
	int n = s.length();
	for(int i=0; i<n; i+=2)
	{
		char a = s[i];
		char b = s[i+1];
		
		int a_pos[2];
		position(a_pos, c, a);
		int b_pos[2];
		position(b_pos, c, b);
		
		//cout << a << " " << a_pos[0] << " " << a_pos[1] << " ; " << b << " "<< b_pos[0] << " " << b_pos[1] << "\n";
		
		if(a_pos[0]==b_pos[0] && a_pos[1]==b_pos[1])
		{
			e.push_back(c[(a_pos[0]+1)%5][(a_pos[1]+1)%5]);
			e.push_back(c[(b_pos[0]+1)%5][(b_pos[1]+1)%5]);
		}
		else if(a_pos[0]==b_pos[0])
		{
			e.push_back(c[a_pos[0]][(a_pos[1]+1)%5]);
			e.push_back(c[b_pos[0]][(b_pos[1]+1)%5]);
		}
		else if(a_pos[1]==b_pos[1])
		{
			e.push_back(c[(a_pos[0]+1)%5][a_pos[1]]);
			e.push_back(c[(b_pos[0]+1)%5][b_pos[1]]);
		}
		else
		{
			e.push_back(c[b_pos[0]][a_pos[1]]);
			e.push_back(c[a_pos[0]][b_pos[1]]);
		}
	}
	//cout << e << "\n";
	return e;
}

string D(char c[n1][n1], string e, int a[], int k)
{
	string d = "";
	int n = e.length();
	for(int i=0; i<n; i+=2)
	{
		char a = e[i];
		char b = e[i+1];
		
		int a_pos[2];
		position(a_pos, c, a);
		int b_pos[2];
		position(b_pos, c, b);
		
		//cout << a << " " << a_pos[0] << " " << a_pos[1] << " ; " << b << " "<< b_pos[0] << " " << b_pos[1] << "\n";
		
		if(a_pos[0]==b_pos[0] && a_pos[1]==b_pos[1])
		{
			d.push_back(c[modular(a_pos[0]-1, 5)][modular(a_pos[1]-1, 5)]);
			d.push_back(c[modular(b_pos[0]-1, 5)][modular(b_pos[1]-1, 5)]);
		}
		else if(a_pos[0]==b_pos[0])
		{
			d.push_back(c[a_pos[0]][modular(a_pos[0]-1, 5)]);
			d.push_back(c[b_pos[0]][modular(b_pos[0]-1, 5)]);
		}
		else if(a_pos[1]==b_pos[1])
		{
			d.push_back(c[modular(a_pos[0]-1, 5)][a_pos[1]]);
			d.push_back(c[modular(b_pos[0]-1, 5)][b_pos[1]]);
		}
		else
		{
			d.push_back(c[b_pos[0]][a_pos[1]]);
			d.push_back(c[a_pos[0]][b_pos[1]]);
		}
	}
	//cout << d << "\n";
	d.erase(d.begin()+k);
	return d;
}
int main()
{
	
	char c[5][5] = {{'L', 'G', 'D', 'B', 'A'},
					{'Q', 'M', 'H', 'E', 'C'},
					{'U', 'R', 'N', 'I', 'F'},
					{'X', 'V', 'S', 'O', 'K'},
					{'Z', 'Y', 'W', 'T', 'P'}};
	//print(c);
	srand(time(NULL));
	string s = "EINST";
	string new_str = "";
	int n = s.length();
	//int k = rand()%n;
	int k = n-1;
	int k1 = k;
	int a[n+1];
	if(n%2!=0)
	{
		for(int i=0; i<n; i++)
		{
			if(i==k)
			{
				new_str.push_back('X');
				i = k-1;
				k = -2;
			}
			else
				new_str.push_back(s[i]);
		}
		for(int i=0; i<=n; i++)
		{
			if(i==k)
				a[i] = -1;
			else
				a[i] = s[i]-'a';
		} 
	}
	else
	{
		new_str += s;
		new_str.push_back('Z');
	}
	
	cout << s << " " << new_str << " " <<  k1 << "\n";
	string e = E(c, new_str, a, k1);
	string d = D(c, e, a, k1);
	
	cout << s << " " << e << " " << d <<"\n";
	return 0;
}
