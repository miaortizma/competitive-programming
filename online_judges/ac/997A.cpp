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
	ll n, a, b;
	cin >> n >> a >> b;
	string s;
	cin >> s;
	int l = 0, r = n - 1;
	while(s[l] == '1'){
		l++;
	}
	while(s[r] == '1'){
		r--;
	}
	ll x = 0;
	ll y = 0;
	while(l <= r){
		if(s[l] == '1'){
			while(l <= r && s[l] == '1'){
				l++;
			}
			x++;
		}else{
			y++;
			l++;
		}	
	}
	ll ans;
	if(y == 0){
		ans = 0;	
	}else if(y == n){
		ans = b;
	}else if(a < b){
		ans = a*x + b;
	}else{
		ans = b*x + b;
	}
	cout << ans << '\n';
	return 0;
}


