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
	int arr[n];
	ll sum[n];
	memset(sum, 0, sizeof(sum));
	for(int i = 0; i < n; i++) cin >> arr[i];
	sum[0] = arr[0];
	for(int i = 1; i < n; i++){
		sum[i] = arr[i] + sum[i - 1];
	}
	ll ans = 0;
	int a = 0;
	int b = 0;
	
	for(int i = 1; i < n - 1; i++){
		if(3*sum[i - 1] == sum[n - 1]){
			a++;
		}
		if(3*(sum[n - 1] - sum[i]) == sum[n - 1]){
			ans += a;
		}
	}
	
	cout << ans;
	return 0;
}


