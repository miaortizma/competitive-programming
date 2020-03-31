#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
const int N = 1e5 + 100;
int n, m;

ll dp[N][2][2];
bool vis[N][2][2];

ll go(int i, bool fulfilled, bool last) {
  if (i >= m) {
    if (fulfilled)
      return 1;
    else
      return 0;
  }
  if (vis[i][fulfilled][last])
    return dp[i][fulfilled][last];
  vis[i][fulfilled][last] = true;
  ll ans = 0;
  if (last) {
    // place, skip
    ans = (ans + go(i + 2, fulfilled | true, false)) % MOD;
    // don't
    ans = (ans + go(i + 1, fulfilled, false)) % MOD;
  } else {
    // place
    ans = (ans + go(i + 1, fulfilled, true)) % MOD;
    // skip, place
    ans = (ans + go(i + 2, fulfilled | true, true)) % MOD;
  }
  return dp[i][fulfilled][last] = ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> m;
  if (n > m) swap(n, m);
  ll chess = 1, domino = 0;
  for (int i = 0; i < n - 1; ++i) {
    ll chessn = (chess + domino) % MOD, dominon = (chess);
    chess = chessn, domino = dominon;
  }
  ll ans = (chess + domino) % MOD;
  //cout << "pre: " << ans << "\n";
  //cout << "add: " << go(1, false, true) << "\n";
  ans = (ans + go(1, false, true)) % MOD;
  ans = (ans * 2) % MOD;
  cout << ans << "\n";
  return 0;
}
