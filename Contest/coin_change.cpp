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

const int nmax = 30000;

ll dp[nmax+1];

ll coins[] = {1,5,10,25,50};

void calc(){
	dp[0] = 1;
	for(int j = 0; j < 5; j++){
		for(int i = coins[j]; i <= 30000; i++){
			dp[i] += dp[i-coins[j]];
		}
	}
	
}


int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	int n;
	calc();
	while(cin >> n){
		ll ans = dp[n];
		if(ans == 1){
			cout << "There is only 1 way to produce " << n << " cents change.\n";
		}else{
			cout << "There are " << ans << " ways to produce " << n << " cents change.\n";
		}
	}
	return 0;
}

