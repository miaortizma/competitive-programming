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
int n;
pii arr[5010];

bool cmp(pii a, pii b){
	if(a.second == b.second){
		return a.first < b.first;
	}
	return a.second < b.second;
}

bool can(int i){
	for(int j = 0; j < n; j++){
		if(arr[i].first < i){
			continue;
		}else{
			
		}
	}
	return true;	
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int  a, b; 
	cin >> n;
	int lo = 1, hi = 1;
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		arr[i] = pii(a, b);
		lo = max(lo, b);
		hi = max(hi, a);
	}
	sort(arr, arr + n, cmp);
	int mid;
	while(lo < hi){
		mid = (lo + hi)/2;
		if(can(mid)){
			hi = mid;
		}else{
			lo = mid + 1;
		}
	}
	int last = arr[0].first, ans = arr[0].second;
	for(int i = 1; i < n; i++){
		if(arr[i].first < last){
			ans = last;
		}else{
			ans = arr[i].second;
		}
		//cout << arr[i].first << ' '<<  arr[i].second << '\n';
		last = max(last, arr[i].first);
	}
	cout << ans;
	return 0;
}

