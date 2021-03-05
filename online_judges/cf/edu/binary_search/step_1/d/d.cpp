#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> v(n + 2);
  v[0] = -1e9 - 1;
  v[n + 1] = 1e9 + 1;
  for (int i = 1; i <= n; ++i) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  int q, l, r;
  cin >> q;
  while (q--) {
    cin >> l >> r;
    int lo = 0, hi = n + 1;
    while (lo < hi) {
      int m = (lo + hi) / 2;
      if (v[m] < l) {
        lo = m + 1;
      } else {
        hi = m;
      }
    }
    int ll = lo;
    lo = 0, hi = n + 1;
    while (lo < hi) {
      int m = (lo + hi + 1) / 2;
      if (v[m] > r) {
        hi = m - 1;
      } else {
        lo = m;
      }
    }
    int rr = lo;
    if (ll <= rr) {
      cout << rr - ll + 1;
    } else {
      cout << 0;
    }
    cout << " ";
  }
  return 0;
}
