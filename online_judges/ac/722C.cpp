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

const int NMAX = 100000;

ll sum[NMAX+10];
int arr[NMAX+10];
int  sz[NMAX+10];

int id(int x){
	while(x != arr[x]){
		arr[x] = arr[arr[x]];
		x = arr[x];
	}
	return x;
}

ll mx;

void un(int x, int y){
	x = id(x);
	y = id(y);
	if(x == y) return;
	if(sz[y] > sz[x]){
		swap(x, y);
	}
	arr[y] = x;
	sz[x] += sz[y];
	sum[x] += sum[y];
	mx = max(sum[x], mx);
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int n;
	cin >> n;
	int del[n];
	bool on[n];
	memset(on, false, sizeof(on));
	for(int i = 0; i < n; i++){
		cin >> sum[i];
		arr[i] = i;
		sz[i] = 1;	
	}
	for(int i = 0; i < n; i++){
		cin >> del[i];	
		del[i]--;
	}
	vector<ll> ans;
	ans.push_back(0);
	for(int i = n - 1; i > 0; i--){
		int tr = del[i];
		if(tr - 1 >= 0 && on[tr-1]){
			un(tr - 1, tr);
		}
		if(tr + 1 < n  && on[tr+1]){
			un(tr + 1, tr);
		}
		mx = max(mx, sum[tr]);
		ans.push_back(mx);
		on[tr] = true;
	}
	for(int i = n - 1; i >= 0; i--){
		cout << ans[i] << '\n';
	}
	return 0;
}


