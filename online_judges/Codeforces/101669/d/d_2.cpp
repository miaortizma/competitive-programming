#include<bits/stdc++.h>
using namespace std;

const int N = 2 * 1e5 + 100;

int m, n, k, p;
vector<int> adj[N];
bool vis[N];

int dfs(int u) {
  int ans = (u > n) ? (0) : (1);
  vis[u] = true;
  for (int v : adj[u])
    if (!vis[v]) ans += dfs(v);
  return ans;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    //cerr << i << "\n";
    scanf("%d", &k);
    if (k == 0) continue;
    for (int j = 0; j < k; ++j) {
      scanf("%d", &p);
      adj[i].push_back(n + p);
      adj[n + p].push_back(i); 
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (adj[i].size() && !vis[i]) {
      int compSize = dfs(i);
      ans += compSize - 1;
    }
  }
  printf("%d", ans);
  return 0;
}
