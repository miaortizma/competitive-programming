#include<bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 1e5+100;
 
int mark = 1, level = 1;
//par is direct parent in centroid decomposition, dist is distance to direct parent in centroid descomposition, lvl is depth in centroid decomposition
int ans[N], sz[N], par[N], vis[N], lvl[N];
map<int,int> dist[N];
vector<int> adj[N];
 
void dfs(int u){
	vis[u] = mark;
	sz[u] = 1;
	for (int v : adj[u]) {
		if (vis[v] != mark && lvl[v] == 0) {
			dfs(v);
			sz[u] += sz[v]; 
		}
	}
}
 
int find_centroid(int n, int u) {
	bool ok = false;
  while (!ok) {
    ok = true;
    vis[u] = mark;
    int s = n - sz[u], idx = u;
    
    for (int v : adj[u]) {
      if (lvl[v] == 0 && vis[v] != mark && sz[v] > s) {
        s = sz[v];
        idx = v;
      }	
    }
	
    if (s > n / 2)
		  u = idx;
	}

	return u;
}
 
void set_dists(int c, int u, int d) {
	vis[u] = mark;
	dist[u][c] = d; 

	for (int v : adj[u])
		if (lvl[v] == 0 && vis[v] != mark)
			set_dists(c, v, d + 1);
}
 
int main() {
	int n, m, a, b;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n - 1; i++){
		scanf("%d %d", &a, &b);
		adj[a].pb(b);
		adj[b].pb(a);
	}

	queue<int> q;
	q.push(1);
	
  // set base answers to queries
  int dd = 0;
	while (!q.empty()) {
		int x = q.size();
		for (int i = 0; i < x; i++) {
			int u = q.front();
			q.pop();
			vis[u] = mark;
			ans[u] = dd;
			for (int v : adj[u])
				if (vis[v] != mark)
					q.push(v);
		}
		dd++;
	}

  // decompose
	mark++;
	q.push(1);
	while (!q.empty()) {
		int x = q.size();
		for (int i = 0; i < x; i++) {
			int u = q.front();
			q.pop();
			//dfs to find size of trees
			dfs(u);
			mark++;
			//dfs to find centroid of tree
			int c = find_centroid(sz[u], u);
			mark++;
			//dfs to precalculate dists to centroid
			set_dists(c, c, 0);
			mark++;
			lvl[c] = level;
			par[c] = par[u];
			for (int v : adj[c]) {
				if (lvl[v] == 0) {
					par[v] = c;
					q.push(v);	
				}
			}
		}
		level++;
		mark++;
	}

  // lvl is used to find LCA
	while (m--) {
		scanf("%d %d", &a, &b);
		if (a == 1) {
			ans[b] = 0;
			int u = b;
			while (lvl[u] != 1) {
				ans[par[u]] = min(ans[par[u]], dist[b][par[u]]); 
				u = par[u];
			} 
		} else {
			int out = ans[b], u = b;
			while (lvl[u] != 1) {
				out = min(out, dist[b][par[u]] + ans[par[u]]); 
				u = par[u];
			}
			printf("%d\n", out); 
		}
	}

	return 0;
}
