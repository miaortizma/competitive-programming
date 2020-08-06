#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e5 + 100;
int n, m, a, b;
int in[N], label[N];
vector<int> adj[N], adj1[N];
bool vis[N];
priority_queue<int, vector<int>, greater<int> > pq, labels;

void dfs(int u) {
  vis[u] = true;
  if (in[u] == 0) pq.push(u);
  for (int v : adj1[u]) {
    if (!vis[v]) dfs(v);
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj1[a].push_back(b);
    adj1[b].push_back(a);
    in[b]++;
  }
  
  int I = 1;
  for (int i = 1; i <= n; ++i) {
    if (in[i] != 0) {
      dfs(i);
      while (pq.size()) {
        int u = pq.top(); pq.pop();
        if (u < i) continue;
        label[u] = I++;
        for (int v : adj[u]) {
          in[v]--;
          if (in[v] == 0) pq.push(v);
        }
      }
    } else if (label[i] == 0){
      label[i] = I++;
      for (int v : adj[i]) {
        in[v]--;
        if (in[v] == 0) {
          pq.push(v);
          vis[v] = true;
        };
      }
    }
  }
  
  for (int i = 1; i <= n; ++i) {
    cout << label[i] << " ";
  }
  return 0;
}
