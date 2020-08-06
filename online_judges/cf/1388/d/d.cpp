#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma
const int N = 2 * 1e5 + 10;
typedef long long ll;
ll arr[N];
int adj[N];
bool vis[N];
vector<int> topo;
int n;

void dfs(int u) {
  vis[u] = true;
  if (adj[u] != -1 && !vis[adj[u]]) {
    dfs(adj[u]);
  }
  topo.push_back(u);
}

void topological_sort() {
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      dfs(i);
    }
  }
  reverse(topo.begin(), topo.end());
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> adj[i];
  }
  topological_sort();
  ll ans = 0;
  vector<int> pos, neg;
  for (auto u : topo) {
    ans += arr[u];
    if (arr[u] > 0) {
      if (adj[u] != -1) {
        arr[adj[u]] += arr[u];
      }
      pos.push_back(u);
    } else {
      neg.push_back(u);
    }
  }
  reverse(neg.begin(), neg.end());
  cout << ans << "\n";
  for (auto u : pos) {
    cout << u << " ";
  }
  for (auto u : neg) {
    cout << u << " ";
  }
  return 0;
}
