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

const int NMAX = (int)1e5 + 10;
typedef pair<ll,ll> pii;

struct edge{
	int base;
	ll cost;
	ll prestige;
};

pii  CW[NMAX+10];
vector< edge > adj[NMAX+10];
map< int, string > names;
map< string, int > id;

bool zero(pii x){
	return x.first == 0 && x.second == 0;
}

pii cost(int u){
	if(!zero(CW[u])){
		return CW[u];
	}else if(adj[u].size() == 0){
		return pii(0, 0);
	}
	pii ans;
	for(int i = 0; i < adj[u].size(); i++){
		edge edg = adj[u][i];
		pii co = cost(edg.base);
		if(i != 0){
			if(co.first + edg.cost < ans.first ){
				ans.first = co.first + edg.cost;
				ans.second = co.second + edg.prestige;
			}else if(co.first + edg.cost == ans.first){
				ans.second = max(ans.second, co.second + edg.prestige);
			}
		}else{
			ans = pii(co.first + edg.cost, co.second + edg.prestige); 
		}
	}
	return CW[u] = ans;
}


int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int W, N;
	cin >> W >> N;
	string r, b, in;
	int c, p;
	int I = 0;
	for(int i = 0; i < N; i++){
		cin >> r >> b >> in >> c >> p;
		edge edg;
		if(id.count(r) == 0){
			id[r] = I++;
		}
		if(id.count(b) == 0){
			id[b] = I++;
		}
		edg.base = id[b];
		edg.cost = c;
		edg.prestige = p;
		adj[id[r]].push_back(edg);
	}
	vector<pii> data;
	data.push_back(pii(0,0));
	pii co = cost(0);
	for(int i = 0; i < I; i++){
		pii co = cost(i);
		if(!zero(co)){
			data.push_back(co);	
		}
	}
	int n = data.size() - 1;
	ll DP[n+1][W+1];
	
	memset(DP, 0, sizeof(DP));
	ll mx = 0;
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= W; j++){
			if(data[i].first > j){
				DP[i][j] = DP[i-1][j];
			}else{
				DP[i][j] = max(DP[i-1][j], DP[i-1][j - data[i].first] + data[i].second);
			}
			if(DP[i][j] > mx){
				mx = DP[i][j];
				ans = j;	
			}else if(DP[i][j] == mx && j < ans){
				ans = j;
			}
		}
	}
	
	cout << DP[n][W] << '\n';
	cout << ans << '\n';
	
	return 0;
}


