#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

typedef long double ld;
typedef long long ll;

ld f(ll t, int h, int c) {
  ll h_c = t / 2 + t % 2;
  ll c_c = t / 2;
  ld denom = t;
  /*
  cout << "t : " << t << " h_c " << h_c << " c_c " << c_c << "\n";
  cout << (h_c * h + c_c * c) << "\n / ";
  cout << t << "\n";
  */
  return (h_c * h + c_c * c) / denom;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int C, H, D;
    cin >> H >> C >> D;
    ld avg = (H + C) / 2.0;
    if (D <= avg) {
      cout << 2 << "\n";
      continue;
    }
    if (D >= H) {
      cout << 1 << "\n";
      continue;
    }
    ll l = 0, h = 1e9;
    while (l < h) {
      ll m = (l + h + 1) / 2;
      ll mt = 2 * m + 1;
      if (f(mt, H, C) > D) {
        l = m;
      } else {
        h = m - 1;
      }
    }
    ld diff0 = abs(f(l * 2 + 1, H, C) - D);
    ld diff1 = abs(f(l * 2 + 3, H, C) - D);
    if (diff0 <= diff1) {
      cout << l * 2 + 1 << "\n";
    } else {
      cout << l * 2 + 3 << "\n";
    }

  }
  return 0;
}
