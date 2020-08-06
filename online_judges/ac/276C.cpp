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

const int nmax = 2e5;

int arr[nmax+5];
int frq[nmax+5];

bool cmp(int a, int b){
	return a > b;
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int n, q, l, r;
	cin >> n >> q;
	for(int i = 0; i < n; i++) cin >> arr[i];
	for(int i = 0; i < q; i++){
		cin >> l >> r;
		l--;
		r--;
		frq[l]+=1;
		frq[r+1]-=1;
	}
	for(int i = 1; i < n; i++){
		frq[i]+=frq[i-1];
	}
	sort(arr, arr + n, cmp);
	sort(frq, frq + n, cmp);
	ll ans = 0;
	for(int i = 0; i < n; i++){
		ans += (1LL*arr[i])*frq[i];
	}
	cout << ans << '\n';
	return 0;
}


