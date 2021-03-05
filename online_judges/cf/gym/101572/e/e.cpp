#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

#define F first
#define S second
typedef pair<int, int> pi;
typedef pair<int, pi> pp;
typedef long long ll;
const int N = 510;

int M[N][N];
bool vis[N][N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, m, x0, y0;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> M[i][j];
    }
  }
  cin >> x0 >> y0;
  x0 -= 1;
  y0 -= 1;

  priority_queue<pair<int, pi>> pq;
  pi pa{x0, y0};
  pp root{-M[x0][y0], pa};
  pq.push(root);
  ll ans = 0;

  while(!pq.empty()) {
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    pp top = pq.top(); pq.pop();
    pi cord = top.S;

    int x = cord.F;
    int y = cord.S;

    if(vis[x][y]) continue;
    //cout << x << " " << y << "\n";
    //cout << -M[x][y] << "\n";
    vis[x][y] = true;
    ans += -M[x][y];

    for (int i = 0; i < 8; ++i) {
      int xx = x + dx[i];
      int yy = y + dy[i];

      if (M[xx][yy] >= 0) continue;
      if (!vis[xx][yy]) {

        M[xx][yy] = max(M[x][y], M[xx][yy]); 
        pp add{-M[xx][yy], {xx, yy}};
        pq.push(add);
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
