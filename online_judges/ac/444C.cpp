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
int n, m, l, r, q, c;

const int len = ceil(sqrt(nmax));
//block query ans
ll e[len+10];
//block colorfulness
ll d[len+10];
//block color
int co[len+10];
//colorfulness
ll b[nmax+10];
//color
int a[nmax+10];

void paint(int l, int r, int c){
	for(int i = l; i <= r; ){
		int x = i/len;
		if(i % len == 0 && i + len - 1 <= r ){
			if(co[x] != - 1){
				e[x] += abs(co[x] - c)*1LL*len;
				d[x] += abs(co[x] - c);
			}else{
				for(int j = x*len; j < n && j < (x+1)*len; j++){
					e[x] += abs(a[j] - c);
					b[j] += abs(a[j] - c);
				}
			}
			co[x] = c;
			i += len;
		}else{
			if(co[x] != -1 && co[x] != c){
				for(int j = x*len; j < n && j < (x+1)*len; j++){
					a[j] = co[x];
				}
				co[x] = -1;
			}
			//cout << "updating: " << i << '\n';
			e[x] += abs(a[i] - c);
			b[i] += abs(a[i] - c);
			//cout << "b[i]: " << b[i] << '\n';
			a[i] = c;
			i++;
		}
	}
}

ll query(int l, int r){
	ll ans = 0;
	for(int i = l; i <= r; ){
		int x = i/len;
		if(i % len == 0 && i + len - 1 <= r ){
			ans += e[x];
			i += len;
		}else{
			ans += d[x] + b[i];
			i++;
		}
	}
	return ans;
}


int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	memset(co, -1, sizeof(co));
	cout << fixed << showpoint;
	cout << setprecision(3);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		a[i] = i + 1;
	}
	//cout << len << '\n';
	while(m--){
		cin >> q >> l >> r;
		l--;
		r--;
		if(q == 1){
			cin >> c;
			paint(l, r, c);
		}else{
			ll ans = query(l, r);
			cout << ans << '\n';
		}
	}
	return 0;
}