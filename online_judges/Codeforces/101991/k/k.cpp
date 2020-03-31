#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 100, mod = 1e9 + 7;


int n, K, L, R, I, V;
// flag, m, i, k
int dp[2][3][N][N];
int cnt[3];

int multp(int a, int b) {
  return (a * b) % mod;
}

ll f(ll x) {
  return x * (x + 1) / 2;
}

int go(int i, int m, int k, bool flag) {
  if (flag) {
    // place 0s
    int x = 1;
    while(x <= i && f(x) <= k) {

    }
  } else {
    // place 1s or 2s
    //cnt[1] * go(i + 1, 1, k);
    //cnt[2] * go(i + 1, 2, k);
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    V++;
    cin >> n >> K >> L >> R;
    cnt[0] = cnt[1] = cnt[2] =  R / 3  - L / 3;
    for (int i = 0; i < R % 3; ++i) cnt[i + 1]++;
    while (f(I + 1) <= 1L * K) I++;
    cout << "K: " << K << "\n";
    cout << "I: " << I << "\n";
    int ans = go(n, 0, K, true) + go(n, 0, K, false);
    cout << ans << "\n";
  }
  return 0;
}
