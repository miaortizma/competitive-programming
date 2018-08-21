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

const int NMAX = (int)1e5;
ll BIT[NMAX+5], n;
int arr[NMAX+5];

void update(int x, ll delta){
    for(; x <= n; x += x&-x) BIT[x] = max(BIT[x], delta);
}
ll query(int x){
    ll mx = 0;
    for(; x > 0; x -= x&-x) mx = max(BIT[x], mx);
    return mx;
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int m, t;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> t;	
		update(i,t);
	} 
	cin >> m;
	ll w, h;
	ll mmx = 0;
	while(m--){
		cin >> w >> h;
		ll mx = query(w);
		cout << max(mmx, mx) << '\n';
		//cout << "update: " << h + max(mmx,mx) << '\n';
		update(w, h + max(mmx,mx));
		mmx = max(mmx, h + max(mmx,mx));
	}
	return 0;
}
