#include<bits/stdc++.h>
using namespace std;

const int N = 501;
int n, m, b, MOD;

int bugs[N];
int dp[2][N][N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> m >> b >> MOD;
  for (int i = 0; i < n; ++i)
    cin >> bugs[i];
  
  dp[0][0][0] = 1;
  for (int ii = 1; ii <= n; ++ii) {
    int i = ii & 1;
    for (int j = 0; j <= m; ++j) {
      for (int k = 0; k <= b; ++k) {
        dp[i][j][k] = dp[i ^ 1][j][k];
        if (j > 0 && k - bugs[ii - 1] >= 0)
          dp[i][j][k] = ( dp[i][j][k] + dp[i][j-1][k - bugs[ii-1]]) % MOD;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i <= b; ++i) {
    ans = (ans + dp[n & 1][m][i]) % MOD;
  }
  
  cout << ans;

  return 0;
}
