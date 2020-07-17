#include<bits/stdc++.h>
using namespace std;

#define pair<int, int> Pair;
struct comp{
	bool operator()(const Pair &a, const Pair &b)
	{
		return a.second < b.second;
	}
};
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int a[n];
		unordered_map<int, int> m;
		for(int i=0; i<n; i++)
		{
			cin >> a[i];
			m.insert({a[i], i});
		}
		sort(m.begin(), m.end(), comp());
		
		for(auto x:m)
			cout << x.second << " ";
		
		cout << "\n";
		
	}
	return 0;
}
