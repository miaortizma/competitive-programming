#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma
//
typedef long long ll;
const int N = 1005;
ll M[N][N];
ll dp[4][N][N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> M[i][j];
    }
  }
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < m - 1; ++j) {
      ll &v = dp[0][i][j];
      v = M[i][j];
      if (i - 1 >= 0) v = max(v, M[i][j] + dp[0][i - 1][j]);
      if (j - 1 >= 0) v = max(v, M[i][j] + dp[0][i][j - 1]);
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    for (int j = m - 1; j >= 0; --j) {
      ll &v = dp[1][i][j];
      v = M[i][j];
      if (i + 1 < n) v = max(v, M[i][j] + dp[1][i + 1][j]);
      if (j + 1 < m) v = max(v, M[i][j] + dp[1][i][j + 1]);
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < m; ++j) {
      ll &v = dp[2][i][j];
      v = M[i][j];
      if (i + 1 < n) {
        v = max(v, M[i][j] + dp[2][i + 1][j]);
      }
      if (j + 1 < m) {
        v = max(v, M[i][j] + dp[2][i][j + 1]);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = m - 1; j >= 0; --j) {
      ll &v = dp[3][i][j];
      v = M[i][j];
      if (i - 1 >= 0) {
        v = max(v, M[i][j] + dp[3][i - 1][j]);
      }
      if (j + 1 < m) {
        v = max(v, M[i][j] + dp[3][i][j + 1]);
      }
    }
  }
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      ll a = max(i - 1 >= 0 ? dp[0][i - 1][j] : 0, j - 1 >= 0 ? dp[0][i][j - 1] : 0) + max(i + 1 < n ? dp[1][i + 1][j] : 0, j + 1 < m ? dp[1][i][j + 1] : 0);
      ll b = max(i + 1 < n ? dp[2][i + 1][j] : 0, j - 1 >= 0  ? dp[2][i][j - 1] : 0) + max(i - 1 >= 0 ? dp[3][i - 1][j] : 0, j + 1 < m ? dp[3][i][j + 1] : 0);
      ll tmp = max(i - 1 >= 0 ? dp[0][i - 1][j] : 0 + i + 1 < n ? dp[1][i + 1][j] : 0 + j - 1 >= 0 ? dp[2][i][j - 1] : 0 + j + 1 < m ? dp[3][i][j + 1] : 0,
          j - 1 >= 0 ? dp[0][i][j - 1] : 0 + j + 1 < m ? dp[1][i][j + 1] : 0 + i + 1 < n ? dp[2][i + 1][j] : 0 + i - 1 >= 0 ? dp[3][i - 1][j] : 0);
      cerr << i << " " << j << " " << tmp <<  " " << a + b <<" \n";
      ans = max(ans, tmp);
    }
  }
  //cerr << dp[0][0][1] << " " << dp[1][2][1] << "@@@\n";
  //cerr << dp[2][1][0] << " " << dp[3][1][2] << "@@@\n";
  if (n >= 4) {
    cerr << "@@@@@@\n";
    cerr << dp[3][2][0] << "\n";
    cerr << dp[3][3][1] << "\n"; 
  }
  cout << ans << "\n";
  return 0;
}
