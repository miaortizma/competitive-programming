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
typedef pair<int,int> pii;

bool cmp(pii a, pii b){
	if(a.second == b.second){
		return a.first < b.first;
	}
	return a.second < b.second;
}


int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	ll n, r, avg;
	cin >> n >> r >> avg;
	ll a, b;
	pii arr[n];
	ll cur = 0;
	ll cost = 0;
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		arr[i] = pii(a, b);
		cur += a;
	}
	sort(arr, arr + n, cmp);
	ll obj = n*avg;
	/*cout << "cur: " << cur << '\n';
	cout << "obj: " << obj << '\n';*/
	for(int i = 0; i < n; i++){
		if(cur >= obj) break;
		ll d = max(0LL,min(r - arr[i].first, obj - cur));
		cost += arr[i].second*d;
		cur += d;
	}
	cout << cost << '\n';
	return 0;
}


