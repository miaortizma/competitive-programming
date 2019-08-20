#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int N = 410;

int adj[N][N], vis[N];

int main() {
  int n, m, a, b;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d %d", &a, &b);
    adj[a][b] = 1;
    adj[b][a] = 1;
  }

  int c = adj[1][n] ? 0 : 1;
  
  queue<pii> q;
  q.push(pii({0, 1}));
  while(q.size()) {
    pii front = q.front();
    q.pop();
    int d = front.first, u = front.second;

    if(!vis[u])
      vis[u] = 1;
    else
      continue;
    for (int i = 1; i <= n; ++i) {
      if (i != u && adj[u][i] == c && !vis[i]) {
        if (i == n) {
          cout << d + 1;
          return 0;
        }
        q.push(pii({d + 1, i}));
      }
    }  
  }

  cout << -1;

  return 0;
}
