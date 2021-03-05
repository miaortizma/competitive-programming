#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

#define PB push_back
#define F first
#define S second
typedef long long ll;
const int N = 1e5 + 10;
typedef pair<int, int> pi;
typedef tuple<ll, ll, ll> tup;

int subtree[N];
vector<pi> adj[N];

ll C = 0;
priority_queue<tup> pq;

ll diff(ll w, ll c) {
  return c * w - c * (w >> 1);
}

void dfs(int u, int p) {
  subtree[u] = 0;
  bool leaf = true;
  for (auto pa : adj[u]) {
    int v = pa.F;
    if (v != p) {
      leaf = false;
      dfs(v, u);
      subtree[u] += subtree[v];
    }
  }
  if (leaf) subtree[u] = 1;
  for (auto pa : adj[u]) {
    int v = pa.F;
    if (v != p) {
      //cout << pa.S << " " << subtree[v] << "\n";
      pq.push({diff(pa.S, subtree[v]), pa.S, subtree[v]});
      C += pa.S * 1ll * subtree[v];
    }
  }
}

typedef long long ll;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    ll S;
    cin >> n >> S;
    int u, v, w;

    //clean
    for (int i = 1; i <= n; ++i) adj[i].clear();
    while(!pq.empty()) pq.pop();
    C = 0;

    for (int i = 0; i < n - 1; ++i) {
      cin >> u >> v >> w;
      adj[u].PB({v, w});
      adj[v].PB({u, w});
    }
    dfs(1, 1);
    int ans = 0;
    //cout << "-------\n";
    //cout << C << "\n";
    while (C > S) {
      tup top = pq.top(); pq.pop();
      ll d = get<0>(top);
      C -= d;
      //cout << d << "d\n";
      //cout << C << "C\n";
      //cout << "\n";
      ll w = get<1>(top);
      w >>= 1;
      ll c = get<2>(top);
      pq.push({diff(w, c), w, c});
      ans += 1;
    }
    cout << ans << "\n";
    //cout << "@@@@@\n";
  }
  return 0;
}
