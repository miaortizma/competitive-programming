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

string reverse(string s){
	string a = "";
	for(int i = s.size() - 1; i >= 0; i--) a += s[i];
	return a;
}

bool ordered(string a, string b){
	int n = a.size(), m = b.size();
	int k = min(n,m);
	for(int i = 0; i < k; i++){
		if(a[i] != b[i]){
			return b[i] > a[i];
		}
	}
	return n <= m;
}
	
int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int n;
	cin >> n;
	ll arr[n+1][2];
	ll dp[n+1][2];
	string str[n+1][2];
	for(int i = 1; i <= n; i++){
		arr[i][0] = 0;
		cin >> arr[i][1];
	} 
	
	
	for(int i = 1; i <= n; i++){
		cin >> str[i][0];	
		str[i][1] = reverse(str[i][0]);
	}
	
	str[0][0] = str[0][1] = "";
	dp[0][0] = dp[0][1] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 2; j++){
			dp[i][j] = -1;
			for(int k = 0; k < 2; k++){
				if(dp[i-1][k] != -1 && ordered(str[i-1][k], str[i][j])){
					if(dp[i][j] == -1){
						dp[i][j] = dp[i-1][k] + arr[i][j];
					}else{
						dp[i][j] = min(dp[i][j], dp[i-1][k] + arr[i][j]);
					}
				}
			}
		}
	}
	//cout << reverse("h") << '\n';
	/*for(int i = 0; i <= n; i++){
		for(int j = 0; j < 2; j++) cout << dp[i][j] << ' ';
		cout << '\n';
	}*/
	//cout << ordered("aaa", "aa") << '\n';
	ll ans = max(dp[n][0], dp[n][1]);
	for(int i = 0; i < 2; i++){
		if(dp[n][i] != -1){
			ans = min(ans, dp[n][i]);
		}
	}
	cout << ans;
	return 0;
}

