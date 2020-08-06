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

double dp[2001][2001];

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	cout << fixed << showpoint;
	cout << setprecision(6);
	int n, t;
	double p;
	cin >> n >> p >> t;
	dp[1][0] = (1.0 - p);
	dp[1][1] = p;
	for(int i = 2; i <= t; i++){
		for(int j = 0; j <= n; j++){
			if(j > 0){
				dp[i][j] += dp[i-1][j-1]*p;
			}
			if(j == n){
				dp[i][j] += dp[i-1][j];
			}else{
				dp[i][j] += dp[i-1][j]*(1.0 - p);	
			}
			//cout << dp[i][j] << ' ';
		}
		//cout << '\n';
	}
	double ans = 0;
	for(int i = 1; i <= n; i++){
		ans += dp[t][i]*i;
	}
	cout << ans << '\n';
	return 0;
}

