#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while(t--) {
    int l, r, m;
    int a, b, c;
    cin >> l >> r >> m;
    int beta = r - l;
    int n = max(1, m / l);
    if (l / 2 <= beta) {
      for (int i = 0; i < 2; ++i) {
        int diff = m - (n + i) * l;
        if (abs(diff) <= beta) {
          a = l;
          b = l;
          c = l;
          if (diff > 0) {
            b += diff;
          } else {
            c += abs(diff);
          }
          break;
        }
      }
    } else {
      for (int i = l; i <= r; ++i) {
        int diff = m - n * i;
        if (abs(diff) <= beta) {
          a = i;
          b = l;
          c = l;
          if (diff > 0) {
            b += diff;
          } else {
            c += abs(diff);
          }
          break;
        }
      }
    }
    cout << a << " " << b  << " " << c << " " << "\n";
    cerr << "n: " << n << " a:" << a << " b:" << b  << " c:" << c << "\n";
    cerr << "m: " << m << " n * a + b - c: " << n * a + b - c << "\n";
  }
  return 0;
}
