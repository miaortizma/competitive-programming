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

int ways(int n, int k){
	if(n == 0){
		return 1;
	}
	if(k == 0 && n != 0){
		return 0;
	} 
	int ans = 0;
	for(int i = 0; i <= n; i++){
		ans += ways(n - i, k - 1);
	}
	return ans;
}


const int nmax = 100;

int dp[nmax+1][nmax+1];

void calc(){
	for(int i = 0; i <= 100; i++){
		dp[0][i] = 1;
	}
	for(int k = 1; k <= nmax; k++){
		for(int i = 1; i <= nmax; i++){
			for(int j = 0; j <= i; j++){
				dp[i][k] =  (dp[i][k] + dp[i-j][k-1])%1000000;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	int n, k;
	calc();
	while(cin >> n >> k){
		if(n == 0 && k == 0) break;
		cout << dp[n][k] << '\n';	
	}
	return 0;
}

