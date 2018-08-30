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

const int nmax = 1e5;
int arr[nmax+5];
ll pre[nmax+5];
ll powers[100];

map<ll, int> times;

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	cout << fixed << showpoint;
	cout << setprecision(3);
	ll n, k;
	cin >> n >> k;
	ll pos = 0, neg = 0;
	ll mx = 0;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		pre[i] = arr[i] + pre[i - 1];
		pos += arr[i];
		pos = max(0LL, pos);
		neg += arr[i];
		neg = min(0LL, neg);
		mx = max(mx, max(pos, - neg));
	}
	powers[0] = 1;
	ll p = 1;
	while(abs(k) != 1 && abs(powers[p - 1]) <  mx){
		powers[p] = powers[p - 1] * k;
		p++;
	}
	if(k == -1){
		powers[1] = -1;
	    p++;
	}
	ll ans = 0;
	for(int i = n; i >= 1; i--){
		for(int j = 0; j < p; j++){
			if(arr[i] == powers[j]){
				ans++;
			}
			ans += times[powers[j] + pre[i - 1]];
		}
		times[pre[i]]++;
	}
	cout << ans;
	return 0;
}

