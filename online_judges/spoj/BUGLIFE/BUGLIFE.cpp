#include<bits/stdc++.h>
using namespace std;

const int N = 20100;
vector<int> adj[N];
int vis[N];
int T, n, m, a, b, tag, sw = 1 ^ 2;
int color[N];

bool dfs(int u, int c) {
  color[u] = c;
  vis[u] = tag;
  bool suspicious = false;
  for (int v : adj[u]) {
    if (vis[v] != tag)
      suspicious |= dfs(v, c ^ sw);
    else if (color[v] == c)
      suspicious |= true;
  }
  return suspicious;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    ++tag;
    memset(color, 0, sizeof color);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) adj[i].clear();
    for (int i = 0; i < m; ++i) {
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    bool suspicious = false;
    for (int i = 1; i <= n; ++i) {
      if (vis[i] != tag) {
        suspicious |= dfs(i, 1);
      }
    }
    cout << "Scenario #" << t << ":\n";
    if (suspicious) {
      cout << "Suspicious bugs found!\n";
    } else {
      cout << "No suspicious bugs found!\n";
    }
  }
  return 0;
}
