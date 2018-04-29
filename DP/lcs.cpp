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
	string a, b;
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	while(getline(cin, a)){
		getline(cin, b);
		int n = a.size(), m = b.size();
		int dp[n+1][m+1];
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(a[i-1] == b[j-1]){
					dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
				}else{
					dp[i][j] = max(dp[i][j-1], dp[i-1][j]);	
				}
			}
		}
		cout << dp[n][m] << '\n';
	}
	return 0;
}

