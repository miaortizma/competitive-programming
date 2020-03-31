#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
bool cat[N];
int n, m;
vector<int> adj[N];

int dfs(int v, int p, int c) {
  if (cat[v]) c++;
  else c = 0;
  if (c > m) return 0;
  bool leaf = true;
  int ans = 0;
  for (int u : adj[v]) {
    if (u != p) {
      leaf = false;
      ans += dfs(u, v, c);
    }
  }
  if (leaf) return 1;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> m;
  int t;
  for (int i = 0; i < n; ++i) {
    cin >> t;
    cat[i + 1] = t == 1;
  }
  int x, y;
  for (int i = 0; i < n - 1; ++i) {
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  int ans = dfs(1, 1, 0);
  cout << ans << "\n";
  return 0;
}
