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

const int NMAX = 1e5+1;

vector<int> adj[NMAX];
bool visited[NMAX];
int color[NMAX];
ll A, B;

void DFS(int u, int c){
	visited[u] = true;
	color[u] = c;
	if(c == 1){
		A++;
	}else{
		B++;
	}
	for(int v : adj[u]){
		if(!visited[v]){
			if(c == 1){
				DFS(v, 2);
			}else{
				DFS(v, 1);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int n, u, v;
	cin >> n;
	for(int i = 0; i < n - 1; i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	DFS(1, 1);
	ll ans = 0;
	//cout << A << ' ' << B << '\n';
	for(int i = 1; i <= n; i++){
		if(color[i] == 1){
			ans += B - adj[i].size()*1LL;
		}
	}
	cout << ans;
	return 0;
}

