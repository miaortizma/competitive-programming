#include<bits/stdc++.h>
using namespace std;

const int N = 2 * 1e5 + 100;

typedef pair<int, int> pii;

struct edge {
  int a, b, t;
};

vector<edge> esp;
vector<int> adj[N];
int color[N], sw = 1 ^ 2;
bool ok = true;
int tot = 0, colored = 0;

void dfs(int u, int c) {
  //cout << "dfs: " << u << ' ' << c << '\n';
  if (!ok)
    return;
  if (color[u] != 0 && color[u] != c) {
    ok = false;
    return;
  }
  if (color[u] == c)
    return;
  color[u] = c;
  if (color[u] == 2) {
    ++colored;
    ++tot;
  } else {
    ++tot;
  }
    
  for (int v : adj[u]) {
    //cout << "v: " << v << "\n";
    dfs(v, c ^ sw);
  }
}



int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, m, a, b, t;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b >> t;
    if (t == 0 || t == 2) {
      edge e{a, b, t};
      esp.push_back(e);
    } else {
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
  }
  int ans = 0;
  for (edge e : esp) {
    if (e.t == 2) {
      dfs(e.a, 2);
      dfs(e.b, 2);
    } else {
      dfs(e.a, 1);
      dfs(e.b, 1);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (color[i] == 2)
      ++ans;
  }
  // components without especial edges
  for (int i = 1; i <= n; ++i) {
    if (color[i] == 0) {
      tot = colored = 0;
      dfs(i, 2);
      ans += min(tot - colored, colored);
    }
  }
  if (ok) {
    cout << ans;
  } else {
    cout << "impossible";
  }
  return 0;
}
