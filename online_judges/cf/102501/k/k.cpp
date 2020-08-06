#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

#define PB push_back
const int N = 1e5 + 10;
typedef pair<int, int> pi;

vector<int> adj[N], radj[N], S;
bool vis[N];

int mind[N], maxd[N];

int n, m, t;

void mindfs(int u, int d) {
  vis[u] = true;
  mind[u] = min(mind[u], d);
  for (int v : radj[u]) {
    if (!vis[v]) {
      mindfs(v, d + 1);
    }
  }
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> m >> t;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].PB(v);
    radj[v].PB(u);
    if (v == t) {
      S.PB(u);
    }
  }
  int inf = n + 1;
  for (int i = 0; i < n; ++i) {
    mind[i] = inf;
  }
  mindfs(t, 0);
  vector<int> ans;
  for (int u : S) {
    bool ok = true;
    for (int v : adj[u]) {
      if (v != t && mind[v] != inf) {
        ok = false;
      }
    }
    if (ok) ans.PB(u);
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << "\n";
  for (int u : ans) {
    cout << u << "\n";
  }
  return 0;
}
