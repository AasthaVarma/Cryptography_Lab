#include<bits/stdc++.h>
using namespace std;
int ** create_array(int N)
{
	int **a = (int **)malloc(N*sizeof(int*));
	for(int i=0; i<N; i++)
		a[i] = (int *) malloc(N*sizeof(int));
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
			a[i][j] = 0;
		}	
	return a;
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
	int ** temp = create_array(N-1);
	int sign = 1;
	for(int i=0; i<N; i++)
	{
		build_coFactor_matrix(a, temp, 0, i, N);
		
		//display_int(temp, N-1);
		
		d += sign*a[0][i]*det(temp, N-1);
		sign = -sign;
	}
	return d;
}
void adjoint(int **a, int **adj, int mod, int n)
{
	int sign = 1;
	int **temp = create_array(n-1);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			build_coFactor_matrix(a, temp, i, j, n);
			//cout << "For cofactor matrix: i, j:" << i <<" " << j << "\n";
			//display_int(temp, n-1);
			adj[j][i] = (sign * det(temp, n-1))%mod;
			sign = -sign;
		}
	}	
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
		d = d+ mod;
	return d;
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
			inv[i][j] = (adj[i][j]*inv_d)%mod;
	}
	return true;
}
int *multiply(int **a, int *d, int mod, int n)
{
	int *res = (int *)malloc(n*sizeof(int));
	int col = 0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			res[i] += a[i][j] * d[j];
		res[i] = modular(res[i], mod);
	}
	return res;
}
void display_int(int **a, int N)
{
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
			cout << a[i][j] << " ";
		cout << "\n";
	}
}
int main()
{
	int n, mod;
	cin >> n >> mod;
	//n = 3; mod= 16;
	int **a = create_array(n);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			cin >> a[i][j];
	}
	int *d = (int *)malloc(n*sizeof(int));
	for(int i=0; i<n; i++)
		cin >> d[i];
	int *res = (int *)malloc(n*sizeof(int));
	int **adj = create_array(n);
	adjoint(a, adj, mod, n);
	//display_int(adj, n);
	int **inv_a = create_array(n);
	if(!inverse(a, adj, inv_a, mod, n))
		cout << "Not possible!\n";
	else
	{
		//display_int(inv_a, n);
		res = multiply(inv_a, d, mod, n);
	}
	for(int i=0; i<n; i++)
		cout << res[i] << " ";
	return 0;
}
