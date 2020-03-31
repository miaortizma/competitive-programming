#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    int c0 = 0, c1 = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      int p;
      cin >> p;
      if (p % 2 == 0)
        c0++;
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
      int q;
      cin >> q;
      if (q % 2 == 0)
        c1++;
    }
    ll ans = c0 * 1LL * c1 + (n - c0) * 1LL * (m - c1);
    cout << ans << "\n";
  }
  return 0;
}
