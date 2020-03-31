#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma
//
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, h, t;
  cin >> n >> h;
  vector<ll> M[n], dp[n];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < h; ++j) {
      cin >> t;
      M[i].push_back(t);
      dp[i].push_back(0);
    }
  }

  for (int j = 0; j < h; ++j) {
    for (int i = n - 1; i >= 0; --i) {
      ll v = 0;
      if (j - 1 >= 0) {
        v = max(v, dp[i][j - 1]);
        if (i + 1 < n) v = max(v, dp[i + 1][j - 1]);
        if (i - 1 >= 0) v = max(v, dp[i - 1][j - 1]);
      }
      dp[i][j] = M[i][j] + v;
    }
  }
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    ans = max(ans, dp[i][h - 1]);
  }
  cout << ans << "\n";
  return 0;
}
