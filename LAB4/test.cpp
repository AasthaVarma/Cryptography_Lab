#include<bits/stdc++.h>
using namespace std;

void print(int a[], int n)
{
	for(int i=0; i<n; i++)
		cout << a[i] << " ";
	cout << "\n";
}
int main()
{
	srand(time(NULL));
	
	int a[] = {3, 2, 4, 1, 5};
	int n = sizeof(a)/sizeof(a[0]);
	int k = rand()%10+1;
	do{
		
	}while(k-- && next_permutation(a, a+5));
	
	print(a, n);
	
	int ek[5];
	int dk[5];
	

	for(int i=0; i<5; i++)
	{
		ek[i] = a[i];
		dk[a[i]-1] = i+1;
	}
	print(ek, n);
	print(dk, n);
	return 0;
}
