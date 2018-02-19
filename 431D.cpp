#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long

ll bits(ll x){
	ll i = 0;
	while(x > 0){
		if(x & 1){
			i++;
		}
		x = x >> 1;
	}
	return i;
}

ll f(ll n, ll k){
	ll a = 0;
	for(int  i = n + 1; i <= 2*n; i++){
		if(bits(i) == k){
			a++;
		}
	}
	return a;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll m, k;
	cin >> m >> k;
	ll lo = 0, hi = 1000000000000000000, x, val;
	//ll lo = 0, hi = 10000000, x, val;
	while(hi - lo > 1){
		x = (hi + lo) >> 1;
		cout << x << '\n';
		val = f(x,k);
		if(val == m){
			cout << x;
			break;
		}
		if(val < m){
			lo = x;
		}else{
			hi = x;
		}
	}
	
	return 0;
}


