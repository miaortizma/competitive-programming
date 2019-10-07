#include<bits/stdc++.h>
using namespace std;

const int N = 2 * 1e5 + 10;

int arr[N], sum[N], offer[N];

int dp[2010];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);

  int n, m, k, a, b;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i)
    cin >> arr[i];
  sort(arr + 1, arr + 1 + n);
  for (int i = 1; i <= n; ++i)
    sum[i] = sum[i - 1] + arr[i];

  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    offer[a] = max(offer[a], b);
  }
  for (int i = 1; i <= k; ++i) {
    dp[i] = dp[i - 1] + arr[i];
    for (int j = 1; j <= i; ++j) {
      int free = offer[i - j + 1];
      dp[i] = min(dp[i], dp[j - 1] + sum[i] - sum[j - 1 + free]);
    }
  }
  cout << dp[k];
  return 0;
}
