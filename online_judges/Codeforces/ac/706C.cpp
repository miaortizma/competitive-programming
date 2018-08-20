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

string reverse(string x){
	int n = x.size();
	string y = "";
	for(int i = n-1; i >= 0; i--) y = y + x[i];
	return y;
}

bool ordered(string x, string y){
	if(x.size() > y.size()) return false;
	int n = min(x.size(), y.size());
	for(int i = 0; i < n; i++){
		if(x[i] != y[i]){
			return y[i] > x[i];	
		}  
	}
	//son iguales
	return true;
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int n;
	ll arr[n+1];
	string str[n+1][2];
	ll dp[n+1][2];
	for(int i = 1; i <= n; i++) cin >> arr[i];
	for(int i = 1; i <= n; i++){
		cin >> str[i][0];
		str[i][1] = reverse(str[i][0]);	
	} 
	memset(dp, -1 ,sizeof(dp));
	dp[0][0] = dp[0][1] = 0;
	str[0][0] = str[0][1] = "";
	for(int i = 1; i <= n; i++){ 
		for(int j = 0; j < 2; j++){
			for(int k = 0; k < 2; k++){
				if(dp[i-1][k] != -1 && ordered(str[i-1][k], str[i][j])){
					if(dp[i][j] == -1){
						if(j == 1){
							dp[i][j] = dp[i-1][k] + arr[i];
						}else{
							dp[i][j] = dp[i-1][k];	
						}
					}else{
						if(j == 1){
							dp[i][j] = min(dp[i][j], dp[i-1][k] + arr[i]);
						}else{
							dp[i][j] = min(dp[i][j], dp[i-1][k]);	
						}
					}
				}
			}
		}
	}
	int ans = min(dp[n][0], dp[n][1]);
	if(ans == -1){
		if(dp[n][0] != -1){
			cout << dp[n][0];
		}else if(dp[n][0] != -1){
			cout << dp[n][1];
		}else{
			cout << -1;
		}
	}else{
		cout << ans;
	}
	return 0;
}

