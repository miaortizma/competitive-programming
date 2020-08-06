#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma
//
const int N = 1010;
const int INF = N * N * N;
int C[N][2]; // number of black cells
int dp[N][N][2];
int n, m, x, y;


int cost(int l, int r, int c) {
  if (l > 0) {
    assert(r >= l);
    if (C[r][c] - C[l - 1][c] < 0) {
      cerr << " r:" << r << " l:" << l << " c:" << c << "\n";
    }
    assert(C[r][c] - C[l - 1][c] >= 0);
    return C[r][c] - C[l - 1][c];
  }
  return C[r][c];
}

int go(int i, int h, int c) {
  if (i == m - 1 && h >= x && h <= y) return 0;
  if (i >= m) return INF;
  if (dp[i][h][c] != -1) {
    return dp[i][h][c];
  }
  int &v = dp[i][h][c];
  v = INF;
  if (h < x && i + x - 1 < m) {
    return v = go(i + x - 1, x, c) + cost(i, i + x - 1, c);
  }
  if (i + 1 < m && h + 1 <= y) {
    v = min(v, go(i + 1, h + 1, c) + cost(i + 1, i + 1, c));
  }
  v = min(v, go(i + 1, 0, c ^ 1));
  return v;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> m >> x >> y;
  string row;
  for (int i = 0; i < n; ++i) {
    cin >> row;
    for (int j = 0; j < m; ++j) {
      if (row[j] == '#') {
        C[j][1]++;
      } else {
        C[j][0]++;
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    C[i + 1][0] += C[i][0];
    C[i + 1][1] += C[i][1];
  }
  memset(dp, -1, sizeof dp);
  int ans = min(go(0, 0, 1), go(0, 0, 0));
  cout << ans << "\n";
  return 0;
}
