#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

const int N = 2 * 1e5 + 100;
const int OO = 1e9 + 100;
#define PB push_back
#define F first
#define S second

typedef pair<int, int> pi;
typedef pair<int, char> pic;
typedef pair<pic, int> state;

struct edge {
  int u, v;
  char c;
};

int get(int u, edge e) {
  if (e.u == u) {
    return e.v;
  } else {
    return e.u;
  }
}

vector<edge> edges;
vector<bool> use;

vector<int> adj[N];
int dist[N];

void dijkstra(int source, int dest) {
  for (int i = 0; i < N; ++i) {
    dist[i] = OO;
  }
  priority_queue<pi, vector<pi>, greater<pi>> pq;
  pq.push({0, source});
  dist[source] = 0;
  while (pq.size()) {
    pi top = pq.top(); pq.pop();
    int d = top.F;
    int u = top.S;
    for (int eid : adj[u]) {
      edge e = edges[eid];
      int v = get(u, e);
      if (d + 1 < dist[v]) {
        dist[v] = d + 1;
        use[eid] = true;
        pq.push({d + 1, v});
      }
      if (d + 1 == dist[v]) {
        use[eid] = true;
      }
    }
  }
}

pic par[N];
bool vis[N];
bool cmp(int a, int b) {
  return edges[a].c < edges[b].c;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, m;
  char c;
  cin >> n >> m;
  int u, v;

  edges.resize(m);
  use.resize(m);
  for (int i = 0; i < m; ++i) {
    cin >> u >> v >> c;
    edges[i] = {u, v, c};
    adj[u].PB(i);
    adj[v].PB(i);
  }

  dijkstra(1, n);
  for (int i = 1; i < n; ++i) {
    sort(adj[i].begin(), adj[i].end(), cmp);
    /*
    cout << i << "\n";
    for (int eid : adj[i]) {
      if (use[eid]) {
        edge e = edges[eid];
        cout << e.u << " " << e.v << " " << e.c << "\n";
      }
    }
    */
  }

  queue<int> q;
  q.push(1);
  vis[1] = true;
  while(!q.empty()) {
    int u = q.front(); q.pop();
    for (int eid : adj[u]) {
      edge e = edges[eid];
      int v = get(u, e);
      if (use[eid] && !vis[v]) {
        par[v] = {u, e.c};
        vis[v] = true;
        q.push(v);
      }
    }
  }
  int cur = n;
  vector<int> pathu;
  vector<char> pathc;
  while (cur && cur != 1) {
    pic p = par[cur];
    pathc.PB(p.S);
    pathu.PB(p.F);
    cur = p.F;
  }
  reverse(pathu.begin(), pathu.end());
  reverse(pathc.begin(), pathc.end());
  cout << pathu.size() << "\n";
  for (auto u : pathu) {
    cout << u << " ";
  }
  cout << n << "\n";
  for (auto u : pathc) {
    cout << u;
  }
  return 0;
}
