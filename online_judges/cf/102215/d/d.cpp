#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

const int N = 2 * 1e5 + 10;
const int K = 18;
int n;
vector<int> adj[N];

int timer;
int tin[N], tout[N];
int up[N][K+1];

void dfs(int u, int p) {
  tin[u] = ++timer;
  up[u][0] = p;
  for (int i = 1; i <= K; ++i) {
    up[u][i] = up[up[u][i - 1]][i - 1];
  }
  for (int v : adj[u]) {
    if (v != p) {
      dfs(v, u);
    }
  }
  tout[u] = ++timer;
}

bool is_ancestor(int u, int v) {
  return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
  if (is_ancestor(u, v)) return u;
  if (is_ancestor(v, u)) return v;
  for (int i = K; i >= 0; --i) {
    if (!is_ancestor(up[u][i], v))
      u = up[u][i];
  }
  return up[u][0];
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  int u, v;
  for (int i = 0; i < n - 1; ++i) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 1);
  int preds;
  cin >> preds;
  while (preds--) {
    int r, b;
    cin >> r >> b;
    vector<pair<int, char>> colors;
    vector<int> reds, blues;
    for (int i = 0; i < r; ++i) {
      cin >> u;
      reds.push_back(u);
    }
    for (int i = 0; i < b; ++i) {
      cin >> u;
      blues.push_back(u);
    }
    int rLCA = reds[0], bLCA = blues[0];
    for (size_t i = 1; i < reds.size(); ++i) {
      rLCA = lca(rLCA, reds[i]);
    }
    for (size_t i = 1; i < blues.size(); ++i) {
      bLCA = lca(bLCA, blues[i]);
    }
    bool ok = true;
    if (rLCA == bLCA) {
      ok = false;
    } else {
      if (is_ancestor(rLCA, bLCA)) {
        for (auto u : reds) {
          if (is_ancestor(bLCA, u)) ok = false;
        }
      } else if (is_ancestor(bLCA, rLCA)) {
        for (auto u : blues) {
          if (is_ancestor(rLCA, u)) ok = false;
        }
      }
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";
  }

  return 0;
}
