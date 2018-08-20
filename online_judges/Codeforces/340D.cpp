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

const int NMAX = 1e5;
int dp[NMAX];

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	cout << fixed << showpoint;
	cout << setprecision(3);
	int n, tmp, length = 1;
	cin >> n >> tmp;
	dp[0] = tmp;
	for(int i = 1; i < n; i++){
		cin >> tmp;
		if(tmp < dp[0]){
			dp[0] = tmp;
		}else if(tmp > dp[length - 1]){
			dp[length++] = tmp;
		}else{
			dp[upper_bound(dp, dp + length, tmp) - dp] = tmp;
		}
	}
	cout << length;
	return 0;
}

