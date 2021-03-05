#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma
#define PB push_back

vector<vector<int>> adj;
const int N = 3 * 1e5 + 10;
int diameter = 0;
priority_queue<int, vector<int>, greater<int>> pq[N];

int dfs(int u, int p) {
  int ans = 1;
  for (auto v : adj[u]) {
    if (v != p) {
      int c = dfs(v, u);
      if (pq[u].size() < 2) {
        pq[u].push(c);
      } else if (pq[u].top() < c) {
        pq[u].pop();
        pq[u].push(c);
      }
      ans = max(ans, 1 + c);
    }
  }
  if (pq[u].size() == 2) {
    int max1 = pq[u].top(); pq[u].pop();
    int max2 = pq[u].top();
    diameter = max(diameter, max1 + max2);
  } else if (pq[u].size() == 1) {
    int max1 = pq[u].top();
    diameter = max(diameter, max1);
  }
  return ans;
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
  cout << diameter * 3;
  return 0;
}
