#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma
//
const int N = 2 * 1e5 + 10;
int n;
int c[N];
int up[N], down[N];
vector<int> adj[N];

int po(int u) {
  if (c[u] == 1) {
    return 1;
  } else {
    return -1;
  }
}

void dfsd(int u, int p) {
  down[u] = po(u);
  for (int v : adj[u]) {
    if (v != p) {
      dfsd(v, u);
      down[u] = max(down[u], down[u] + down[v]);
    }
  }
}

void dfsu(int u, int p) {
  for (int v : adj[u]) {
    if (v != p) {
      up[v] = max(0, up[u] + down[u] - max(0, down[v]));
      dfsu(v, u);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
  }
  int a, b;
  for (int i = 0; i < n - 1; ++i) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfsd(1, 1);
  dfsu(1, 1);
  for (int i = 1; i <= n; ++i) {
    //cout << up[i] << " " << down[i] << " " << i << " " << up[i] + down[i] << "\n";
  }
  for (int i = 1; i <= n; ++i) {
    cout << up[i] + down[i] << " ";
  }
  return 0;
}
