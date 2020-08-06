#include<bits/stdc++.h>
using namespace std;

const int N = 5001;
int n, b, d, c, p;
vector<int> adj[N];
int C[N], D[N], sz[N], dp[N][N], dpt[N];


void dfs(int u) {
  dp[u][1] = C[u];
  sz[u] = 1;
  for (int v : adj[u]) {
    dfs(v);
    sz[u] += sz[v];
  }
}

int main() {
  scanf("%d %d", &n, &b);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d", &C[i], &D[i]);
    if (i > 1) {
      scanf("%d", &p);
      adj[p].push_back(i);
    }
  }
  dfs(1);
  
  return 0;
}
