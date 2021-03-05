#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

typedef pair<int, int> pi;
typedef pair<pi, int> e;
#define PB push_back
#define F first
#define S second

const int N = 1e4, K = 11;
const int oo = 1e9;
int n, m, u, v, w;
int alice, bob, freek;
vector<pi> adj[N], radj[N];
int dpA[K][N], rdpA[K][N];
int dpB[K][N], rdpB[K][N];

auto compare = [](e A, e B) { return A.F > B.F; };

void dijkstra(int source, int dp[K][N], vector<pi> adj[N]) {
  for (int i = 0; i <= freek; ++i) {
    for (int j = 0; j < n; ++j) {
      dp[i][j] = oo;
    }
  }
  priority_queue<e, vector<e>, decltype(compare)> pq(compare);
  pq.push({{0, 0}, source});
  while (!pq.empty()) {
    e top = pq.top(); pq.pop();
    int d = top.F.F, k = top.F.S, u = top.S;
    if (d >= dp[k][u]) continue;
    dp[k][u] = d;
    for (pi pa : adj[u]) {
      int v = pa.F, w = pa.S;
      // use free ticket
      if (k < freek) {
        if (d < dp[k + 1][v]) {
          pq.push({{d, k + 1}, v});
        }
      }
      // go as normal
      if (d + w < dp[k][v]) {
        pq.push({{d + w, k}, v});
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> m;
  cin >> alice >> bob >> freek;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v >> w;
    adj[u].PB({v, w});
    radj[v].PB({u, w});
  }
  dijkstra(alice, dpA, adj);
  dijkstra(alice, rdpA, radj);
  dijkstra(bob, dpB, adj);
  dijkstra(bob, rdpB, radj);
  int bestU = -1, bestW = oo;
  /*
  cout << dpA[0][2] << "@@@\n";
  cout << rdpA[0][2] << "@@@\n";
  cout << dpB[0][2] << "@@@\n";
  cout << rdpB[0][2] << "@@@\n";
  */
  for (int i = 0; i < n; ++i) {
    if (i == alice || i == bob) continue;
    int A = oo;
    int B = oo;
    for (int j = 0; j <= freek; ++j) {
      for (int k = 0; k <= freek - j; ++k) {
        A = min(A, dpA[j][i] + rdpA[k][i]);
        B = min(B, dpB[j][i] + rdpB[k][i]);
        /*
        cout << "j: " << j << "\n";
        cout << "k: " << k << "\n";
        cout << "A: " << A << "\n";
        cout << "B: " << B << "\n";
        */
      }
    }
    //cout << i << " " << A + B << "\n";
    if (A + B < bestW) {
      bestW = A + B;
      bestU = i;
    }
  }
  if (bestU == -1) {
    cout << ">:(";
  } else {
    cout << bestU << " " << bestW;
  }
  return 0;
}
