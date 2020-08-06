#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e5 + 100;
int n, m, a, b;
int out[N], label[N];
vector<int> adj[N];
bool vis[N];
priority_queue<int> pq;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    adj[b].push_back(a);
    out[a]++;
  }
  for (int i = 1; i <= n; ++i)
    if (out[i] == 0) pq.push(i);
  int I = n;
  while (pq.size()) {
    int u = pq.top(); pq.pop();
    label[u] = I--;
    for (int v : adj[u]) {
      out[v]--;
      if (out[v] == 0) pq.push(v);
    }
  }
  
  for (int i = 1; i <= n; ++i) {
    cout << label[i] << " ";
  }
  return 0;
}
