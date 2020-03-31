#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
int n, m, k;
const int N = 18;
ll adj[N][N], val[N];

ll dp[1 << N][N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i)
    cin >> val[i];
  for (int i = 0; i < k; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a - 1][b - 1] = c;
  }
  for (int i = 0; i < n; ++i) {
    dp[1 << i][i] = val[i];
  }
  for (int mask = 0; mask < (1 << n); ++mask) {
    for (int i = 0; i < n; ++i) {
      if ((1 << i) & mask) {
        for (int j = 0; j < n; ++j) {
          if (((1 << j) & mask) == 0) {
            int nmask = mask | (1 << j);
            dp[nmask][j] = max(dp[nmask][j], dp[mask][i] + adj[i][j] + val[j]);
          }
        }
      }
    }
  }
  ll ans = 0;
  for (int mask = 0; mask < (1 << n); ++mask) {
    int len = __builtin_popcount(mask);
    if (len == m) {
      for (int i = 0; i < n; ++i) {
        ans = max(ans, dp[mask][i]);
      }
    }
  }
  cout << ans;
  return 0;
}
