#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

typedef long long ll;
const int N = 510;
const ll MOD = 1e9 + 7;
int dp[2][N][N];
bool vis[2][N][N];
int n, k, d;

ll go(bool flag, int sum, int i) {
  if (sum == n) {
    if (flag) {
      return 1;
    }
    return 0;
  } else if (sum > n) {
    return 0;
  }
  if (vis[flag][sum][i]) {
    return dp[flag][sum][i];
  }
  vis[flag][sum][i] = true;
  ll ans = 0;
  for (int j = 1; j <= k; ++j) {
    if (j >= d) {
      ans = (ans + go(true, sum + j, i + 1)) % MOD;
    } else {
      ans = (ans + go(flag, sum + j, i + 1)) % MOD;
    }
  }
  return dp[flag][sum][i] = ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> k >> d;
  cout << go(0, 0, 0);
  return 0;
}
