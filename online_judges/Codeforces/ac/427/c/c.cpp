#include<bits/stdc++.h>
using namespace std;

const int N = 1e5, mod = 1e9 + 7;

vector<int> g[N + 1], gr[N + 1];
int used[N + 1], cost[N + 1], mark, count_, minimum;
vector<int> order;

void dfs1 (int v) {
  used[v] = mark;
  for (size_t i = 0; i < g[v].size(); ++i)
    if (used[ g[v][i] ] != mark)
      dfs1(g[v][i]);

   order.push_back (v);
}

void dfs2 (int v) {
  used[v] = mark;
  if (cost[v] < minimum) {
    minimum = cost[v];
    count_ = 1;
  } else if (cost[v] == minimum) {
    ++ count_;
  }

  for (size_t i = 0; i < gr[v].size(); ++i) {
    if (used[ gr[v][i] ] != mark)
      dfs2 (gr[v][i]);
  }

}

int modpow(int x, int n) {
  long long ans = 1;
  while (n) {
    if (n & 1)
      ans = (ans * x) % mod;
    x = (x * x) % mod;
    n >>= 1;
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  int n, m, a, b;
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> cost[i];
  
  cin >> m;

  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    g[a].push_back(b);
    gr[b].push_back(a);
  }

  mark = 1;
  for (int i = 1; i <= n; ++i)
    if (used[i] != mark)
      dfs1(i);

  mark = 2;
  long long total = 0, ans = 1;
  for (int i = 0; i < n; ++i) {
    int v = order[n - 1 - i];
    if (used[v] != mark) {
      count_ = 0;
      minimum = 1e9 + 100;
      dfs2(v);
      ans = (ans * count_) % mod;
      total += minimum;
    }
  }

  cout << total << ' ' <<  ans;

  return 0;
}
