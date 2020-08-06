#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

const int N = 1e5 + 10;
int population[N], happiness[N], pass[N], happy[N];
vector<int> adj[N];
bool ok;


void dfs(int u, int p) {
  pass[u] = population[u];
  for (int v : adj[u]) {
    if (v != p) {
      dfs(v, u);
      if (!ok) return;
      pass[u] += pass[v];
    }
  }
  // happiness[i] = happy[i] - unhappy[i]
  // pass[i] = happy[i] + unhappy[i]
  if (abs(happiness[u]) > pass[u]) {
    ok = false;
    return;
  }
  if ((happiness[u] + pass[u]) % 2 != 0) {
    ok = false;
    return;
  }
  happy[u] = (happiness[u] + pass[u]) / 2;
  int dhappy = 0;
  for (int v : adj[u]) {
    if (v != p) {
      dhappy += happy[v];
    }
  }
  if (dhappy > happy[u]) {
    ok = false;
    return;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    // read
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
      cin >> population[i];
    }
    for (int i = 1; i <= n; ++i) {
      cin >> happiness[i];
    }
    int u, v;
    for (int i = 0; i < n - 1; ++i) {
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    ok = true;
    // calculate pass[i], happy[i], unhappy[i]

    dfs(1, 1);
    if (ok) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }

    // clean
    for (int i = 1; i <= n; ++i) {
      adj[i].clear();
    }

  }
  return 0;
}
