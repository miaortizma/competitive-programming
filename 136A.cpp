#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	cout << fixed << showpoint;
	cout << setprecision(3);
	int n;
	cin >> n;
	int arr[n + 1];
	for(int i = 0; i < n; i++){
		int t;
		cin >> t;
		arr[t] = i + 1;
	}
	for(int i = 1; i <= n; i++){
		cout << arr[i] << ' ';
	}cout << '\n';
	return 0;
}


