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

const int NMAX = 200000;
int arr[NMAX+10];
ll sz[NMAX+10];

int id(int x){
	while(x != arr[x]){
		arr[x] = arr[arr[x]];
		x  = arr[x];
	}
	return x;
}

void un(int x, int y){
	x = id(x); 
	y = id(y);
	if(x == y){
		return;
	}
	if(sz[x] < sz[y]){
		swap(x, y);
	}
	arr[y] = x;
	sz[x] += sz[y];
}

void reset(int n){
	for(int i = 1; i <= n; i++){
		arr[i] = i;
		sz[i] = 1;
	}
}

vector<int> groups[NMAX+10]; 
bool used[NMAX+10];

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int n, m, k;
	cin >> n >> m >> k;
	int color[n+1];
	reset(n);
	for(int i = 1; i <= n; i++){
		cin >> color[i];
	}
	int l, r;
	for(int i = 0; i < m; i++){
		cin >> l >> r;
		used[l] = true;
		used[r] = true;
		un(l, r);
	}
	vector<int> leads;
	for(int i = 1; i <= n; i++){
		if(!used[i]){
			continue;
		}
		int xid = id(arr[i]);
		groups[xid].push_back(i);
		if(xid == i){
			leads.push_back(i);
		}
	}
	ll ans = 0; 
	for(int i = 0; i < leads.size(); i++){
		int lead = leads[i];
		vector<int> group = groups[lead];
		vector<int> gcolor(group.size());
		for(int j = 0; j < group.size(); j++){
			gcolor[j] = color[group[j]];
		}
		sort(gcolor.begin(), gcolor.end());
		ll mx = 1, cur = 1;
		for(int j = 1; j < group.size(); j++){
			if(gcolor[j] == gcolor[j-1]){
				cur++;
				mx = max(mx, cur);
			}else{
				cur = 1LL;
			}
		}
		mx = max(mx, cur);
		ans += group.size() - mx;
	}
	cout << ans << '\n';
	return 0;
}


