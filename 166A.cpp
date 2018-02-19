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

bool equal(pii a, pii b){
	return a.first == b.first && a.second == b.second;
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int n, k, a, b;
	cin >> n >> k;
	k--;
	vector<pii> arr(n);
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		arr[i] = pii(a, -b);
	}
	sort(arr.rbegin(), arr.rend());
	int ans = 0, i = k - 1;
	while(i >= 0 && equal(arr[i], arr[k])){
		//cout << arr[i].first << ' ' << arr[i].second << '\n';
		ans++;
		i--;
	}
	i = k;
	while(i < n && equal(arr[i], arr[k])){
		//cout << arr[i].first << ' ' << arr[i].second << '\n';
		ans++;
		i++;
	}
	cout << ans;
	return 0;
}

