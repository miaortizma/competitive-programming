#include <bits/stdc++.h>
using namespace std;
<<<<<<< HEAD
#define ll long long
#define pb push_back
#ifdef PAPITAS
	#define DEBUG 1
#else
	#define DEBUG 0
#endif
#define _DO_(x) if(DEBUG) x

const int NMAX = 100*500;
bool dp[NMAX+10];

=======

bool dp[110][25010];
>>>>>>> refs/remotes/origin/master

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
<<<<<<< HEAD
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int arr[n];
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j <= NMAX; j++){
				if(dp[j]){
					dp[]
				}
			}
		}
	}
	return 0;
}

=======
	int n;
	cin >> n;
	while(n--){
		int m;
		cin >> m;
		int s = 0;
		int arr[m+1];
		for(int i = 1; i <= m; i++){
			cin >> arr[i];
			s += arr[i];
		}
		memset(dp, false, sizeof(dp));
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= s/2 + 1; j++){
				dp[i][j] = dp[i-1][j] || dp[i][j];
				bool a = j+arr[i] <= s/2+1;
				if(dp[i-1][j] && a){
					dp[i][j+arr[i]] = true;
				}
			}
			dp[i][arr[i]] = true;
		}
		int ans = s;
		for(int i = s/2 + 1; i >= 1; i--){
			if(dp[m][i]){
				int a = (s - (s-i));
				int b = (s-i);
				ans = min(ans, abs(a - b));
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
>>>>>>> refs/remotes/origin/master
