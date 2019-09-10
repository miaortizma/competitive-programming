#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> adj[N+1];
int road[N];
bool fix[N], ans[N+1];

void dfs(int u, int p, int candidate) {
  for (int i : adj[u]) {
    if (i != p) {
      int v = road[i] ^ u;
      if (fix[i]) {
        ans[v] = true;
        if (candidate != 0)
          ans[candidate] = false;
        dfs(v, i, v);
      } else {
        dfs(v, i, candidate);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int x, y, c, n;
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    cin >> x >> y >> c;
    adj[x].push_back(i);
    adj[y].push_back(i);
    road[i] = x ^ y;
    if (c == 2)
      fix[i] = true;
  }
  dfs(1, -1, 0);
  vector<int> v;
  for (int i = 1; i <= n; ++i) {
    if (ans[i])
      v.push_back(i);
  }
  cout << v.size() << '\n';
  for (int val : v) {
    cout << val << ' ';
  }
  return 0;
}
