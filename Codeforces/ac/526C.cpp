#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	cout << fixed << showpoint;
	cout << setprecision(3);
	ll ca, joyr, joyb, weir, weib;
	cin >> ca >> joyr >> joyb >> weir >> weib;
	if(joyr == joyb && weir == weib){
		cout << joyr*(ca/weir) << '\n';
		return 0;
	}
	int chr = joyr/weir, chb = joyb/weib;
	if(chr  == chb){
		ll ans = 0;
		ll last = 0;
		ll x = (ca/weir), y = 0;
		for(ll i = x; i >= 0; i--){
			ll  y = (ca - i*weir)/weib;
			ll t = i *joyr + y*joyb;
		
			cout << i << "," << y << " t:" << t << '\n';
			if(t > ans){
				ans = t;
			}
			if(t < last) break;
			last = t;
		}
		y = (ca/weib);
		last = 0;
		for(ll i = y; i >= 0; i--){
			ll  x = (ca - i*weib)/weir;
			ll t = x*joyr + i*joyb;
		
			cout << x << "," << i << " t:" << t << '\n';
			if(t > ans){
				ans = t;
			}
			if(t < last) break;
			last = t;
		}
		cout << ans << '\n';
		}
	return 0;
}


