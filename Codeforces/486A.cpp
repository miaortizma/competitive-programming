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

const ll nmax = 1e15;

ll f(ll s){
	ll odd, pair, c;
	if(s%2 == 0){
		c = (s/2);
	}else{
		c = (s/2)+1;
	}
	pair = (2+(s/2)*2)*(s/4);
	if((s/2)%2 != 0){
		pair += s/2 + 1;
	}
	odd = -(c)*(c);
	ll ans = odd+pair;
	return ans;
}


int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	ll s = 0;
	cin >> s;
	cout << f(s);
	return 0;
}
