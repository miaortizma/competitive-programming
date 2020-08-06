#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct point {
  ll x, y;

  point (ll x, ll y) : x(x), y(y) {}
};


ll sq(ll x) {
  return x * x;
}

ll distsq(point A, point B) {
  return sq(A.x - B.x) + sq(A.y - B.y);
}


ll n, m, k, x, y, s;
const int N = 1100;
vector<point> points;
vector<ll> cap, capsq;
vector<int> adj[N];
bool vis[N];

void dfs(int u) {
  vis[u] = true;
  for (int v : adj[u])
    if (!vis[v])
      dfs(v);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> m >> k;
  points.push_back({0, 0});
  capsq.push_back(0);
  cap.push_back(0);
  for (int i = 1; i <= k; ++i) {
    cin >> x >> y >> s;
    points.push_back(point(x, y));
    cap.push_back(s);
    capsq.push_back(sq(s));
  }
  // side 0 is y = 0, x = n
  // side n + 1 is y = m, x = 0
  for (int i = 1; i <= k; ++i) {
    point A = points[i];
    /*
    if (i == 2) {
      cerr << sq(A.y) << " " << capsq[i] << "<\n";
    }
    */
    if (sq(A.y) <= capsq[i] || sq(n - A.x) <= capsq[i]) {
      adj[i].push_back(k + 1);
    }
    if (sq(m - A.y) <= capsq[i] || sq(A.x) <= capsq[i]) {
      adj[0].push_back(i);
    }
    for (int j = i + 1; j <= k; ++j) {
      if (distsq(points[i], points[j]) <= sq(cap[i] + cap[j])) {
        adj[i].push_back(j);
        adj[j].push_back(i);
      }
    }
    /*
    cerr << i << "\n";
    for (int x : adj[i]) {
      cerr << x << " ";
    }
    cerr << "\n";
    */
  }
  dfs(0);
  //cerr << vis[k + 1] << "<<\n";
  if (vis[k + 1]) {
    cout << "N\n";
  } else {
    cout << "S\n";
  }
  return 0;
}
