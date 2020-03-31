#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

const int N = 2 * 1e5 + 10;
int arr[N], dp[N];
int n, p, k;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> p >> k;
    for (int i = 1; i <= n; ++i) cin >> arr[i];
    sort(arr + 1, arr + n + 1);
    memset(dp, 0, sizeof dp);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      dp[i] = arr[i] + dp[i - 1];
      if (i - k >= 0) {
        dp[i] = min(dp[i], arr[i] + dp[i - k]);
      }
      if (dp[i] <= p) {
        ans++;
      } else {
        break;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
