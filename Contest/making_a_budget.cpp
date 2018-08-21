#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#ifdef PAPITAS
	#define DEBUG 0
#else
	#define DEBUG 0
#endif
#define _DO_(x) if(DEBUG) x

int hire, salary, fire;

int cost(int a, int b){
	if(a == b){
		return salary*a;
	}else if(a < b){
		return salary*b + hire*(b - a);
	}else{
		return salary*b + fire*(a - b);
	}
}

int main()
{
	//ios::sync_with_stdio(false);//cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int n;
	ll T = 1;
	while(cin >> n){
		if(n == 0) break;
		cin >> hire >> salary >> fire;
		ll arr[n+1];
		ll mn = 10000, mx = -1;
		for(ll i = 1; i <= n; i++){
			cin >> arr[i];
			mn = min(arr[i], mn);
			mx = max(arr[i], mx);	
		}
		
		ll dp[n+1][mx+1];
		memset(dp, 0, sizeof(dp));
		for(ll i = 1; i <= n; i++){
			for(ll j = arr[i]; j <= mx; j++){
				if(i == 1){
					dp[i][j] = cost(0, j);
					continue;
				}
				dp[i][j] = dp[i-1][arr[i-1]] + cost(arr[i-1], j);	
				for(ll k = arr[i-1]; k <= mx; k++){
					dp[i][j] = min(dp[i][j], dp[i-1][k] + cost(k, j));
				}
			}
		}
		ll ans = dp[n][arr[n]];
		cout << "Case " << T++ << ", cost = $" << ans << '\n'; 
	}
	return 0;
}

