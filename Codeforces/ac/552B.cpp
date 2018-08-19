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
	ll n;
	cin >> n;
	ll pow = 10;
	ll ans = 0, i = 1;
	while(pow <= n){
		ans += (pow - pow/10)*i;
		i++;
		pow *= 10;
	}
	ans += (n - pow/10 + 1)*i;
	cout << ans << '\n';
	return 0;
}

