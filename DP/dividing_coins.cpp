#include <bits/stdc++.h>
using namespace std;

bool dp[110][25010];

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
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
