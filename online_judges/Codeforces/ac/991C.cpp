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

bool can(ll n, ll k){
	ll N = n;
	ll a = 0, b = 0;
	while(n){
		a += min(n, k);
		n -= min(n, k);
		ll c = n/10;
		if(c > 0){
			n -= c;
			b += c;
		}
	}
	return a*2 >= N;
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
	ll l = 1;
	ll h = n;
	ll mid;
	while(l < h){
		mid = (l + h) >> 1;
		if(can(n, mid)){
			h = mid;
		}else{
			l = mid + 1;
		}
	}
	cout << l << '\n';
	return 0;
}


