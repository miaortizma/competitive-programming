#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

#define PB push_back

const int N = 50010;
vector<int> adj[N];
vector<int> co(N);
bool ok = true;

void dfs(int u, int p, int c) {
  co[u] = c;
  for (int v : adj[u]) {
    if (co[v] != -1) {
      if (co[v] != (c ^ 1)) {
        ok = false;
      }
    } else {
      dfs(v, u, c ^ 1);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int n, m;
    cin >> n >> m;
    ok = true;
    for (int i = 1; i <= n; ++i) {
      adj[i].clear();
      co[i] = -1;
    }
    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      adj[u].PB(v);
      adj[v].PB(u);
    }
    for (int i = 1; i <= n; ++i) {
      if (co[i] == -1) {
        dfs(i, i, 0);
      }
    }
    cout << "Scenario #" << t << ":\n";
    if (ok) {
      cout << "No suspicious bugs found!\n";
    } else {
      cout << "Suspicious bugs found!\n";
    }
  }
  return 0;
}
