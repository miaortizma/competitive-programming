#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll exgcd(ll a, ll b, ll & x, ll & y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  ll x0, y0, g = exgcd(b, a % b, x0, y0);
  x = y0, y = x0 - a / b * y0; 
  return g;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  ll A, B, C;
  cin >> A >> B >> C;
  C = - C;
  ll x, y, g = exgcd(A, B, x, y);
  if (C % g == 0) {
    ll c = C / g;
    cout << x * c << ' ' << y * c << '\n';
  } else {
    cout << -1;
  }
  return 0;
}
