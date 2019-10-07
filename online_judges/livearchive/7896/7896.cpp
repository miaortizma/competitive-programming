#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 60 * 2, INF = 100000;
int capacity[N][N], parent[N];
vector<int> adj[N];
bool use[N];

int bfs(int s, int t) {
  //cout << "BFS:\n";
  for (int i = 0; i < N; ++i) parent[i] = -1;
  parent[s] = -2;
  queue<pii> q;
  q.push({s, INF});

  while (!q.empty()) {
    int cur = q.front().first;
    int flow = q.front().second;
    //cout << "cur: " << cur << ", flow" << flow<< '\n';
    q.pop();

    for (int next : adj[cur]) {
      if (parent[next] == -1 && capacity[cur][next]) {
        parent[next] = cur;
        int new_flow = min(flow, capacity[cur][next]);
        //cout << "cur\tnext\tnew_flow\n";
        //cout << cur << '\t' << next <<'\t'<<new_flow<< '\n';

        if (next == t)
          return new_flow;
        q.push({next, new_flow});
      }
    }
  }

  return 0;
}

int maxFlow(int s, int t) {
  int flow = 0;
  int new_flow;
  
  while (new_flow = bfs(s, t)) {
    flow += new_flow;
    int cur = t;
    //cout << "new_flow: " << new_flow<< "\n";
    while (cur != s) {
      //cout << cur << ' ';
      int prev = parent[cur];
      capacity[prev][cur] -= new_flow;
      capacity[cur][prev] += new_flow;
      cur = prev;
    }
    //cout << '\n';
  }

  return flow;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, a, b, ans, residual, against, flow, s, t;
  while (cin >> n) {
    s = 0;
    t = 2 * n + 1;
    adj[s].clear();
    adj[t].clear();
    for (int i = 1; i <= n; ++i) {
      cin >> a >> b;
      adj[i].clear();
      adj[i + n].clear();

      adj[i].push_back(n + a);
      adj[i].push_back(n + b);

      adj[s].push_back(i);
      adj[i + n].push_back(t);
    }
    ans = 0;
    for (int i = 1; i <= n; ++i) {
      residual = 0;
      memset(use, false, sizeof use);
      memset(capacity, 0, sizeof capacity);
      for (int j = 1; j <= n; ++j) {
        if (i != j && i + n != adj[j][0] && i + n != adj[j][1])
          use[j] = true;
        else
          ++residual;
      }
      against = residual - 1;
      //cout << i << ' ' << against << '\n';
       if (against <= 1) { // 0 or 1
        ++ans;
        cout << i << " wins\n";
        continue;
      }
      for (int j = 1; j <= n; ++j) {
        capacity[j + n][t] = against - 1;
        if (use[j]) {
          //cout << "use: " << j << '\n';
          capacity[s][j] = 1;
          capacity[j][adj[j][0]] = 1;
          capacity[j][adj[j][1]] = 1;
        }
      }
      capacity[adj[i][0]][t] = max(0, against - 2);
      capacity[adj[i][1]][t] = max(0, against - 2);
      flow = maxFlow(s, t);
      cout << "flow:" << flow << ' ' << n - residual <<  '\n';
      if (flow != n - residual) {
        ++ans;
      } else {
        cout << i << " loses\n";
        for (int j = 1; j <= n; ++j) {
          if (j == i) {
            cout << i << ' ' << against << " votes\n";
          } else {
            cout << j << ' ' << capacity[t][j+n] << " votes\n";
          }
        }
      }
    }
    cout << ans << '\n';
    //return 0;
  }
  return 0;
}
