#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second

const int N = 2001;
typedef pair<int,int> pii;
vector<int> adj[N];
pii diam[N];

pii count(int u, int p, int c) {
  bool leaf = true;
  int a = 0, b = 0;
  for (int v : adj[u]) {
    if (v != p) {
      leaf = false;
      pii ans = count(v, u, c + 1);
      if (ans.y > b) {
        b = ans.y;
        a = ans.x;
      } else if (ans.y == b) {
        a += ans.x;
      }
    }
  }
  if (leaf) 
    return pii({1, c});
  return pii({a, b});
}

int dfs (int u, int p, int g, int c) {
  int ret = 0;
  if (c > g)
    ++ret;
  for (int v : adj[u])
    if (v != p)
      ret += dfs(v, u, g, c + 1);
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int n, K, a, b;
  cin >> n >> K;
  for (int i = 0; i < n - 1; ++i) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  a = n, b = 0;
  int c = 0;
  for (int i = 1; i <= n; ++i) {
    if (adj[i].size() == 1) {
      diam[i] = count(i, i, 0);
      if (diam[i].y > b) {
        a = diam[i].x;
        b = diam[i].y;
        c = i;
      } else if (diam[i].y == b) {
        a = min(a, diam[i].x);
      }
    }
  }
  cout << dfs(c, c, K, 0) << '\n';
  return 0;
}

