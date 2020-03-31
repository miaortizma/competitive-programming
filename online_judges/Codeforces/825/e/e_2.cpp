#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int n, m, a, b;
int in[N], label[N];
vector<int> adj[N];
priority_queue<int, vector<int>, greater<int> > pq;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    adj[a].push_back(b);
    in[b]++;
  }
  for (int i = 1; i <= n; ++i) {
    if (in[i] == 0)
      pq.push(i);
  }
  int I = 1;
  while (!pq.empty()) {
    int u = pq.top(); pq.pop();
    label[u] = I++;
    for (int v : adj[u]) {
      in[v]--;
      if (in[v] == 0) {
        pq.push(v);
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << label[i] << " ";
  }
  return 0;
}
