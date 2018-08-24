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

const ll inf = 1e15;

ll	 digitsum(ll x){
	int ans = 0;
	while(x){
		ans += x%10;
		x /= 10;
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	ll n;
	cin >> n;
	ll root = sqrt(n);
	ll best = inf;
	for(ll i = root; i > 0 && i > root - 50; i--){
		if((i * (i + digitsum(i))) == n){
			best = i;
		}	
	}
	for(ll i = root; i < root + 50; i++){
		if((i * (i + digitsum(i))) == n){
			best = i;
		}
	}
	if(best == inf){
		cout << -1;
	}else{
		cout << best;
	}
	return 0;
}


