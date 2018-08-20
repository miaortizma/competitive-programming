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

int dp[1010][31];

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int T;
	cin >> T;
	while(T--){
		memset(dp, 0, sizeof(dp));
		int N, a, G;
		cin >> N;
		int arr[N+1][2];
		for(int i = 1; i <= N; i++ ){
			cin >> arr[i][0] >> arr[i][1];
		}
		for(int i = 1; i <= N; i++ ){
			for(int j = 1; j <= 30; j++){
				dp[i][j] = dp[i-1][j];
				if(j - arr[i][1] >= 0){
					dp[i][j] = max(dp[i][j], dp[i-1][j - arr[i][1]] + arr[i][0]);
				}
			}
		}
		cin >> G;
		int ans = 0;
		for(int i = 0; i < G; i++){
			cin >> a;
			ans += dp[N][a];
		}
		cout << ans << '\n';
	}
	cout << fixed << showpoint;
	cout << setprecision(3);
	return 0;
}
