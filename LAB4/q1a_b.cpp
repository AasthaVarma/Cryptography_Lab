#include<bits/stdc++.h>
using namespace std;

int ** create_array(int r, int c)
{
	int **a = (int **)malloc(c*sizeof(int*));
	for(int i=0; i<c; i++)
		a[i] = (int *) malloc(r*sizeof(int));
	for(int i=0; i<r; i++)
	{
		for(int j=0; j<c; j++)
			a[i][j] = 0;
	}	
	return a;
}

int inv_(int a, int n)
{
	for(int i=1; i<n; i++)
	{
		if((a*i)%n==1)
			return i;
	}
}

int modular(int d, int mod)
{
	d = d%mod;
	while(d<0)
		d = d+mod;
	return d;
}

void build_coFactor_matrix(int **a, int **temp, int p, int q, int N)
{
	int c=0, r=0;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			if(i==p || j==q)
				continue;
			else
				temp[r][c] = a[i][j];
			c++;	
			if(c==N-1)
			{
				c = 0;
				r++;
			}
		}
	}
	

}

int det(int **a , int N)
{
	if(N==1)
		return a[0][0];
	int d = 0;
	int ** temp = create_array(N-1, N-1);
	int sign = 1;
	for(int i=0; i<N; i++)
	{
		sign = i%2?1:-1;
		build_coFactor_matrix(a, temp, 0, i, N);
		//display_int(temp, N-1);
		d += sign*a[0][i]*det(temp, N-1);
	}
	return d;
}

void adjoint(int **a, int **adj, int mod, int n)
{
	int sign = 1;
	int **temp = create_array(n-1, n-1);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			sign = (i+j)%2==0?1:-1;
			build_coFactor_matrix(a, temp, i, j, n);
			//cout << "For cofactor matrix: i, j:" << i <<" " << j << "\n";
			//display_int(temp, n-1);
			adj[j][i] = (sign * det(temp, n-1));
			adj[j][i] = modular(adj[j][i], mod);
		}
		
	}	
}

bool inverse(int **a, int **adj, int **inv, int mod, int n)
{
	int d = det(a, n);
//	cout << d << "\n";
	d = modular(d, mod);

	int inv_d = inv_(d, mod);
//	cout << d << " " << inv_d << "\n";
	if(d==0)
		return false;
		
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
				inv[i][j] = -(adj[i][j]*inv_d);
				inv[i][j] = modular(inv[i][j], 26);
		}
	}
	return true;
}

int ** multiply(int **a ,int ra, int ca, int **b, int rb, int cb)
{
	int **res = create_array(ra, cb);
	for(int i=0; i<ra; i++)
	{
		for(int j=0; j<cb; j++)
		{
			for(int k=0; k<rb; k++)
			{
				res[i][j] += (a[i][k]*b[k][j]);
			}
			res[i][j] = modular(res[i][j], 26);
		}
	}
	return res;
}

void print(int **a, int r, int c)
{
	for(int i=0; i<r; i++)
	{
		for(int j=0; j<c; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}

int main()
{
	string s = "codeisreadyz";
	int n = 4, l=0;
	int **p =create_array(n-1, n);
	for(int i=0; i<n-1; i++)
		for(int j=0; j<n; j++)
			p[i][j] = s[l++]-'a';
	//print(p, n-1, n);
	int **key = create_array(n, n);
	int **inv_key = create_array(n-1, n);

	//int k[n][n] = {{9, 7, 11, 13},{4, 7, 5, 6},{2, 21, 14, 9},{3, 23, 21, 8}};
				
	int k[n][n] = {{2, 15, 22, 3}, {15, 0, 19, 3}, {9, 9, 3, 11}, {17, 0, 4, 7}};
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			key[i][j] = k[i][j];
	//print(key, n, n);
	int **adj = create_array(n, n);
	adjoint(key, adj, 26, n);
	
	if(inverse(key, adj, inv_key, 26, n))
		print(inv_key, n, n);
	else
		cout << "Impossible";
	cout << "\n";
	
	int **cipher = create_array(n-1, n);
	cipher= multiply(p, n-1, n, key, n, n);
	for(int i=0; i<n-1; i++)
		for(int j=0; j<n; j++)
			cout << char('a'+cipher[i][j]);
	cout << "\n";
	
	int **decrypt = create_array(n-1, n);
	decrypt = multiply(cipher, n-1, n, inv_key, n, n);
	for(int i=0; i<n-1; i++)
		for(int j=0; j<n; j++)
			cout << char('a'+decrypt[i][j]);
	return 0;
}
