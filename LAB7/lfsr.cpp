#include<bits/stdc++.h>
using namespace std;

void shift(int a[], int n)
{
	for(int i=0; i<n-1; i++)
	{
		a[i] = a[i+1];
	}
}
int func1(int a[], int n)
{
	//cout << a[4] << " " << a[2] << " " << a[0] << " = " << ((a[4]^a[2]) ^ a[0]) << "\n";
	return ((a[4]^a[2]) ^ a[0]);
}
int func2(int a[], int n)
{
	return (a[1]^a[0]);
}
int func3(int a[], int n)
{
	return (((a[8]^a[4])^a[2])^a[0]);
}
void print(int a[], int n)
{
	for(int i=n-1; i>=0; i--)
		cout << a[i] << " ";
	cout << "\n";
}
int main()
{
	int n, x;
	cin >> n;
	int a[n];
	for(int i=n-1; i>=0; i--)
		cin >> a[i];
	vector<int> vec;	
	for(int i=0; i<20; i++)
	{
		//x = func1(a, n);
		x = func2(a, n);
		//x = func3(a, n);
		vec.push_back(x);
		shift(a, n);
		a[n-1] = x;
		cout << i+1 << ": ";
		print(a, n);
	}
	cout << "\n";
	for(auto x:vec)
		cout << x << " ";
	return 0;
}
