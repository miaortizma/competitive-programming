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
	int n, t;
	cin >> n;
	typedef pair<int,int> pii;
	pii arr[n];
	for(int i = 0; i < n; i++){
		cin >> t;
		arr[i] = pii(t, i);
	}
	sort(arr, arr + n);
	ll ans = 0;
	for(int i = 1; i < n; i++){
		ans += abs(arr[i].second - arr[i-1].second);
		//cout << arr[i].first << ' ' << arr[i].second << '\n';
	}
	cout << ans << '\n';
	return 0;
}


