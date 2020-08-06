#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// By Miguel Ortiz https://github.com/miaortizma

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int T;
  cin >> T;
  while(T--) {
    ll a, b, c, r;
    cin >> a >> b >> c >> r;
    if (a > b) swap(a, b);
    ll A = b - a;
    ll x0 = c - r, x1 = c + r;
    ll x = max(a, x0), y = min(b, x1);
    if (x <= y) {
      y = min(y, b);
      x = max(x, a);
      cout << A - (y - x) << "\n";
    } else {
      cout << A << "\n";
    }
  }
  return 0;
}
