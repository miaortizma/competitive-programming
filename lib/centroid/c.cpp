#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 100;
vector<int> adj[N];

int sz[N], par[N], lvl[N];

int dfs(int u, int p) {
  sz[u] = 1;
  for (int v : adj[u])
    if (v != p && lvl[v] == 0)
      sz[u] += dfs(v, u);

  return sz[u];
}

int centroid(int u, int p, int n) {
  for (int v : adj[u])
    if (v != p && lvl[v] == 0 && sz[v] > n / 2)
      return centroid(v, u, n);

  return u;
}

void decompose(int u, int level) {
  dfs(u, u);
  int c = centroid(u, u, sz[u]);
  lvl[c] = level;
  par[c] = par[u];
  for (int v : adj[c]) {
    if (lvl[v] == 0) {
      par[v] = c;
      decompose(v, level + 1);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, a, b;
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  decompose(1, 1);
  for (int i = 1; i <= n; ++i) {
    cout << char(lvl[i] - 1 + 'A') << ' ';
  }
  return 0;
}
