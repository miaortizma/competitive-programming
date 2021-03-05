#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma
typedef long long ll;

bool can(ll w, ll h, ll n, ll m) {
  ll ww = min(m / w, n);
  ll hh = min(m / h, n);
  bool c = ww * hh >= n;
  return c;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  ll w, h, n;
  cin >> w >> h >> n;
  ll lo = max(w, h), hi = n * max(w, h);
  auto f = [w, h, n](ll m) { return can(w, h, n, m); };
  while (lo < hi) {
    ll m = (lo + hi) / 2;
    if (f(m)) {
      hi = m;
    } else {
      lo = m + 1;
    }
  }
  cout << lo;
  return 0;
}
