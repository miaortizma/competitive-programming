#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5 * 1e4 + 100;
vector<int> adj[N];
ll down[N][510];
ll up[N][510];
int n, k, a, b;

void dfsLower(int u, int p) { 
  down[u][0] = 1;
  for (int v : adj[u]) {
    if (v != p) {
      dfsLower(v, u);
      for (int i = 1; i <= k; ++i)
        down[u][i] += down[v][i - 1];
    }
  }
}

void dfsUpper(int u, int p) {
  up[u][0] = 1;
  for (int v : adj[u]) {
    if (v != p) {
      for (int i = 1; i <= k; ++i)
        up[v][i] = up[u][i - 1] + ((i > 1) ? (down[u][i - 1] - down[v][i - 2]) : (0)); 
      dfsUpper(v, u);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> k;
  for (int i = 0; i < n - 1; ++i) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfsLower(1, 1);
  dfsUpper(1, 1);
  ll res = 0;
  for (int i = 1; i <= n; ++i)
    res += down[i][k] + up[i][k];
  cout << res / 2LL << "\n";
  return 0;
}
