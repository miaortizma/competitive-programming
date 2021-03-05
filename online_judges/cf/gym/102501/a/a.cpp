#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma
#define F first
#define S second
#define PB push_back
typedef pair<int, int> pt;
typedef tuple<int, int, int> tup;

int sq(int x) {
  return x * x;
}

int dist(pt a, pt b) {
  return ceil(sqrt(sq(a.F - b.F) + sq(a.S - b.S)));
}

ostream& operator<< (ostream& os, tup x) {
  os << get<0>(x) << " " << get<1>(x) << " " << get<2>(x);
  return os;
}

ostream& operator<< (ostream& os, pt x) {
  os << x.F << " " << x.S;
  return os;
}


const int INF = 1e9;
int B, T, N, C[101];
vector<pt> stations;
vector<pt> links[1000];

priority_queue<tup, vector<tup>, greater<tup>> pq, pq2;
vector<tup> adj[1002], adj2[1002];
int D[1002][101];

int dijkstra(int s, int d) {
  pq.push({0, 0, s});
  for (int i = 0; i <= N + 1; ++i) {
    for (int j = 0; j <= B; ++j) {
      D[i][j] = INF;
    }
  }
  D[s][0] = 0;
  int ans = INF;
  while (!pq.empty()) {
    tup top = pq.top(); pq.pop();
    int cC = get<0>(top);
    int cD = get<1>(top);
    int u = get<2>(top);
    //cerr << u << "\n";
    if (cC > D[u][cD]) continue;
    for (auto tu : adj[u]) {
      int tC = get<0>(tu);
      int tD = get<1>(tu);
      int v = get<2>(tu);
      pt td{cC + tC, cD + tD};
      //cerr << v << " " << td.S << "\n";
      //cerr << D[v][td.S] << "\n"; 
      if (td.F < D[v][td.S] && cD + tD <= B) {
        D[v][td.S] = td.F;
        if (v == d) {
          ans = min(ans, td.F);
          continue;
        }
        pq.push({td.F, td.S, v});
      }
    }
  }
  if (ans == INF) return -1;
  else return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int x, y, l, u, v, t, d;
  cin >> x >> y;
  pt home{x, y};
  cin >> x >> y;
  pt dest{x, y};
  cin >> B;
  cin >> C[0];
  cin >> T;
  for (int i = 0; i < T; ++i) {
    cin >> C[i + 1];
  }
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> x >> y >> l;
    pt station{x, y};
    stations.PB(station);
    for (int j = 0; j < l; ++j) {
      cin >> v >> t;
      links[i].PB({v, t});
      links[v].PB({i, t});
    }
  }
  for (int i = 0; i < N; ++i) {
    // add inter station edges
    u = (i + 1);
    for (auto pa : links[i]) {
      v = pa.F;
      t = pa.S;
      d = dist(stations[i], stations[v]);
      if (d > B) continue;
      adj[u].PB({d * C[t], d, v + 1});
    }
    // add home to stations edges
    d = dist(home, stations[i]);
    if (d <= B) {
      adj[0].PB({d * C[0], d, u});
    }
    // add stations to destination edges
    d = dist(stations[i], dest);
    if (d <= B) {
      adj[u].PB({d * C[0], d, N + 1});
    }
  }
  d = dist(home, dest);
  if (d <= B) {
    adj[0].PB({d * C[0], d, N + 1});
  }
  int ans = dijkstra(0, N + 1);
  cout << ans;
  return 0;
}
