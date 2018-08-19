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
	int n, a, b, mx = 0;
	cin >> n;
	typedef pair<int,int> pii;
	vector<pii> arr(n);
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		arr[i] = pii(a, b);
	}
	sort(arr.begin(), arr.end());
	bool ok = false;
	for(int i = 0; i < n; i++){
		if( i + 1 < n && arr[i+1].first != arr[i+1].first){
			mx = max(mx, arr[i].second);
		}
		if( i - 1 >= 0 && arr[i-1].first == arr[i].first) continue;
		if(arr[i].second < mx){
			ok = true;
		}
		mx = max(mx, arr[i].second);
	}
	if(ok){
		cout << "Happy Alex";
	}else{
		cout << "Poor Alex";
	}
	return 0;
}

