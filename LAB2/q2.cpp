#include<bits/stdc++.h>

using namespace std;
void display_float(float **a, int N)
{
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
			cout << a[i][j] << " ";
		cout << "\n";
	}
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
float ** create_float_array(int N)
{
	float **a = (float **)malloc(N*sizeof(float*));
	for(int i=0; i<N; i++)
		a[i] = (float *) malloc(N*sizeof(float));
		
	return a;
}
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
void adjoint(int **a, int **adj, int n)
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
			adj[j][i] = sign * det(temp, n-1);
			sign = -sign;
		}
	}	
}
bool inverse(int **a, int **adj, float **inv, int n)
{
	int d = det(a, n);
	if(d==0)
		return false;
		
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			inv[i][j] = adj[i][j]/float(d);
	}
	return true;
}

int main()
{
	
	int N ;
	cout << "Enter n:\n"; 
	cin >> N;
	int **a = create_array(N);
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
			cin >> a[i][j];	
	}
	cout << "Determinant: " << det(a, N) << "\n";
	
	//display_int(a);	
	int **adj = create_array(N);
	adjoint(a, adj, N);
	//display_int(adj, N);
	float **inv = create_float_array(N);
	if(inverse(a, adj, inv, N))
		display_float(inv, N);
	else
		cout << "Inverse doesn't exist!\n";
	
	return 0;
}
