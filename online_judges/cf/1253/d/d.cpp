#include<bits/stdc++.h>
using namespace std;

const int N = 2 * 1e5 + 100;
int n, m, a, b, l, r;
vector<int> adj[N];
bool vis[N];

int arr[N], sz[N];

int root(int i) {
  while (arr[i] != i) {
    arr[i] = arr[arr[i]];
    i = arr[i];
  }
  return i;
}

void un(int x, int y) {
  x = root(x), y = root(y);
  if (x == y) return;
  if (sz[x] < sz[y]) swap(x, y);
  arr[y] = x;
  sz[x] += sz[y];
}

void dfs(int u) {
  r = max(r, u);
  //cerr << u << "\n";
  vis[u] = true;
  for (int v : adj[u])
    if (!vis[v])
      dfs(v);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    sz[i] = 1;
    arr[i] = i;
  }
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int i = 1;
  int ans = 0;
  while (i <= n) {
    if (!vis[i]) {
      int components = 1;
      l = r = i;
      dfs(i);
      while (i < r) {
        if (!vis[i]) {
          //cerr << i << "\n";
          components++;
          dfs(i);
        }
        ++i;
      }
      dfs(i);
      //cerr <<  l << " " << r <<  " " << components << "\n";
      ans += components - 1;
    } else {
      //cerr << i << "\n";
    } 
    ++i;
  }
  cout << ans << "\n";
  return 0;
}
