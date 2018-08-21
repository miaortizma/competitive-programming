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
	int n, l , r, L, R;
	cin >> n;
	typedef pair<int,int> pii;
	pii arr[n];
	cin >> l >> r;
	L = l;
	R = r;
	arr[0] = pii(l,r);
	for(int i = 1; i < n; i++){
		cin >> l >> r;
		arr[i] = pii(l,r);
		L = min(l, L);
		R = max(r, R);
	}
	int ans = -1;
	for(int i = 0; i < n; i++){
		if(arr[i].first == L &&  arr[i].second == R){
			ans = i+1;
		}
	}
	cout << ans << '\n';
	return 0;
}


