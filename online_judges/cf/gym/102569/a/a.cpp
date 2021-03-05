#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

typedef long long ll;


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<ll> v(n);
  ll S = 0;
  auto sign = [n](int i) {
    if ((n - 1 - i) % 2 == 0) {
      return 1;
    } else {
      return -1;
    }
  };
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    S += sign(i) * v[i];
  }
  int q;
  ll l, r, vi;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    cin >> l >> r >> vi;
    if (l == r) {
      S += sign(l - 1) * vi;
    } else if ((r - l + 1) % 2 != 0) {
      S += sign(l - 1) * vi;
    }
    cout << S << "\n";
  }
  return 0;
}
