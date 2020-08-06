#include<bits/stdc++.h>
using namespace std;

const int NN = 200;

vector<int> g[NN], rg[NN], order;
int vis[NN], mark;

void dfs1(int u) {
  vis[u] = mark;
  for (int v : g[u])
    if (vis[v] != mark)
      dfs1(v);
 
  order.push_back(u);
}

void dfs2(int u) {
  vis[u] = mark;
  for (int v : rg[u])
    if (vis[v] != mark)
      dfs2(v);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  int N;
  cin >> N;
  while(N--) {
    int n, e, x, y;
    cin >> n;
    cin >> e;
    
    order.clear();
    for (int i = 0; i < n; ++i) {
      g[i].clear();
      rg[i].clear();
    }

    for (int i = 0; i < e; ++i) {
      cin >> x >> y;
      g[x].push_back(y);
      rg[y].push_back(x);
    }
    
    ++mark;
    for (int i = 0; i < n; ++i)
      if (vis[i] != mark)
        dfs1(i);

    int ans = 0;
    ++mark;
    for (int i = n - 1; i >= 0; --i) {
      int u = order[i];
      if (vis[u] != mark) {
        ++ans;
        dfs2(u);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
