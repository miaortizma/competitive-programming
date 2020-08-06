#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#ifdef PAPITAS
	#define DEBUG 1
#else
	#define DEBUG 0
#endif
#define _DO_(x) if(DEBUG) x

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	cout << fixed << showpoint;
	cout << setprecision(3);
	int n;
	cin >> n;
	int arr[n];
	int dp[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		dp[i] = 1;
	}
	int ans = 1;
	for(int i = 1; i < n; i++){
		if(arr[i - 1] >= (arr[i] + 1)/2){
			dp[i] = dp[i-1] + 1;
		}
		ans = max(ans, dp[i]);
		//cout << dp[i] << ' ';
	}
	//cout << '\n';
	cout << ans;
	return 0;
}

