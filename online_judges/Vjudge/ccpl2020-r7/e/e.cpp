#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

const int N = 2010;
int dp[N][3];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j <= n; ++j) {
        dp[j][i] = 0;
      }
    }
    for (int i = 1; i <= n; ++i) {
      char c = s[i - 1];
      if (c == 'K') {
        dp[i][0] = 1 + dp[i - 1][0];
        dp[i][1] = dp[i - 1][1];
        dp[i][2] = dp[i - 1][1] + dp[i - 1][2];
      } else if (c == 'E') {
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][2] = dp[i - 1][2];
      } else {
        for (int j = 0; j < 3; ++j) {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
    cout << dp[n][2] << "\n";
  }

  return 0;
}
