#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 100;
ll down[N][20][2], up[N][20][2];
int val[N], digs[N][20];
vector<int> adj[N];
int n, a, b;

void printAns() {
  for (int i = 1; i <= n; ++i) {
    cout << "i: " << i << "\n";
    cout << "lower\n";
    for (int j = 0; j < 5; ++j)
      cout << "j: " << (1 << j)  << " " << down[i][j][0] << " " << down[i][j][1] << "\n";
    cout << "upper\n";
    for (int j = 0; j < 5; ++j)
      cout << "j: " << (1 << j)  << " " << up[i][j][0] << " " << up[i][j][1] << "\n";
    cout << "\n";
  }
}

void dfsLower(int u, int p) {
  for (int v : adj[u]) {
    if (v != p) {
      dfsLower(v, u);
      for (int i = 0; i < 20; ++i) {
        down[u][i][digs[u][i] ^ 0] += down[v][i][0];
        down[u][i][digs[u][i] ^ 1] += down[v][i][1];
      }
    }
  }
}

void dfsUpper(int u, int p) {
  for (int v : adj[u]) {
    if (v != p) {
      for (int i = 0; i < 20; ++i) {
        up[v][i][digs[v][i] ^ 0] = up[u][i][0] + down[u][i][0] - down[v][i][digs[u][i] ^ 0];
        up[v][i][digs[v][i] ^ 1] = up[u][i][1] + down[u][i][1] - down[v][i][digs[u][i] ^ 1];
      }
      dfsUpper(v, u);
    }
  }
  for (int i = 0; i < 20; ++i)
    ++up[u][i][digs[u][i]];
}



int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> val[i];
    int d = 0;
    while (val[i]) {
      digs[i][d] = val[i] & 1;
      down[i][d++][val[i] & 1] = 1;
      val[i] >>= 1;
    }
    while (d < 20)
      down[i][d++][0] = 1;
  }
  for (int i = 0; i < n - 1; ++i) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfsLower(1, 1);
  dfsUpper(1, 1);
  ll res = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < 20; ++j)
      res += (down[i][j][1] + up[i][j][1]) * (1 << j);
  cout << res / 2LL;
  return 0;
}
