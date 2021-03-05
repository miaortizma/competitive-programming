#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma
#define PB push_back

vector<vector<int>> adj;
const int N = 3 * 1e5 + 10;
int diameter = 0;
priority_queue<int, vector<int>, greater<int>> pq[N];
vector<int> lmax[N], rmax[N];
int down[N], up[N];

int dfs(int u, int p) {
  int ans = 1;
  int n = adj[u].size();
  lmax[u].resize(n);
  rmax[u].resize(n);
  for (int i = 0; i < n; ++i) {
    int v = adj[u][i];
    if (v != p) {
      int c = dfs(v, u);
      lmax[u][i] = c;
      rmax[u][i] = c;
      if (pq[u].size() < 2) {
        pq[u].push(c);
      } else if (pq[u].top() < c) {
        pq[u].pop();
        pq[u].push(c);
      }
      ans = max(ans, 1 + c);
    }
  }
  for (int i = 1; i < n; ++i) {
    lmax[u][i] = max(lmax[u][i], lmax[u][i - 1]);
  }
  for (int i = n - 2; i >= 0; --i) {
    rmax[u][i] = max(rmax[u][i], rmax[u][i + 1]);
  }
  if (pq[u].size() == 2) {
    int max1 = pq[u].top(); pq[u].pop();
    int max2 = pq[u].top();
    diameter = max(diameter, max1 + max2);
  } else if (pq[u].size() == 1) {
    int max1 = pq[u].top();
    diameter = max(diameter, max1);
  }
  return down[u] = ans;
}

void dfsup(int u, int p) {
  int n = adj[u].size();
  for (int i = 0; i < n; ++i) {
    int v = adj[u][i];
    if (v != p) {
      int l = 0, r = 0;
      if (i > 0) {
        l = lmax[u][i - 1];
      }
      if (i < n - 1) {
        r = rmax[u][i + 1];
      }
      up[v] = max(up[u] + 1, 1 + max(l, r));
      dfsup(v, u);
    }
  }
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, u, v;
  cin >> n;
  adj.resize(n + 1);

  for (int i = 0; i < n - 1; ++i) {
    cin >> u >> v;
    adj[u].PB(v);
    adj[v].PB(u);
  }
  dfs(1, 1);
  for (int i = 1; i <= n; ++i) {
    down[i] -= 1;
  }
  up[1] = 0;
  dfsup(1, 1);
  for (int i = 1; i <= n; ++i) {
    //cout << "i: " << i << " up: " << up[i] << " down: " << down[i]  << "\n";
    int m = adj[i].size();
    int cur = diameter;
    cur = max(cur, 1 + up[i]);
    cur = max(cur, 1 + down[i]);
    cout << cur << "\n";
  }
  return 0;
}
