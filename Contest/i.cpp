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
	ll n, k, q, c, d;
	cin >> n >> k >> q;
	k = k%n;
	while(q--){
		cin >> c >> d;
		if(k == 0){
			if(d == 0){
				cout << c << '\n';
			}else{
				cout << 0 << '\n';
			}
			continue;
		}
		ll laps = c/n;
		ll left = c%n;
		ll next = ((d + k - 1)/k)*k;
		ll row = next - d;
		if(left > row*(n/k)+next/k){
			laps++;	
		}
		cout << laps << '\n';
	}
	return 0;
}

