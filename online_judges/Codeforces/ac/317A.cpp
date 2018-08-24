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
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	ll x, y, m;
	cin >> x >> y >> m;
	if(x >= m || y >= m){
		cout << 0 << '\n';
	}else if(x <= 0 && y <= 0){
		cout << -1 << '\n';
	}else{
		ll a = min(x, y), b = max(x, y);
		ll steps = 0;
		if(a < 0){
			steps = (-a + b - 1)/b;
			a = a + b*steps; 
		}
		while(b < m){
			ll t = b;
			b = a + b;
			a = t;
			steps++;
		}
		cout << steps << '\n';
	}
	return 0;
}


