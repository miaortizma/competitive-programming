#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll GCD(ll a, ll b) { return (b == 0) ? a : GCD(b, a % b); }
inline ll LCM(ll a, ll b) { return a / GCD(a, b) * b; }
inline ll normalize(ll x, ll mod) { x %= mod; if (x < 0) x += mod; return x; }
struct GCD_type { ll x, y, d; };


ll exgcd(ll a, ll b, ll & x, ll & y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  ll x0, y0, g = exgcd(b, a % b, x0, y0);
  x = y0;
  y = x0 - a / b * y0;
  return g;
}

ll n, m, x, y, vx, vy;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m >> x >> y >> vx >> vy;  
  if (vx == 0) {
    if (x == 0 || x == n) {
      if (vy > 0)
        cout << x << " " << m;
      else
        cout << x << " " << 0;
    } else {
      cout << -1;
    }
  } else if (vy == 0) {
    if (y == 0 || y == m) {
      if (vx > 0)
        cout << n << ' ' << y;
      else
        cout << 0 << ' ' << y;
    } else {
      cout << -1;
    }
  } else {
    ll x0, y0, g = exgcd(n, m, x0, y0);
    ll a0 = normalize(- x * vx, n), a1 = normalize(- y * vy, m);
    if ((a0 - a1) % g != 0) {
      cout << -1;
    } else {
      //ll ans = a0 + x0 * (a1 - a0) / g * n;
      //cout << x0 << " * " << n  << " + " << y0 << " * " << m << " = " << g << "\n";
      ll ans = a0 + (((x0 * (a1 - a0) / g) % (m / g)) * n) % (m / g * n);
      ans = normalize(ans, m / g * n);
      /*cout << ans << "\n";
      cout << ans % n << " " << a0 << "\n";
      cout << ans % m << " " << a1 << "\n";
      */
      x = abs(x + ans * vx);
      y = y + ans * vy;

      //cout << x % n << " " << y % m << "\n";
      cout << (abs(x / n) % 2) * n << " " << (abs(y / m) % 2) * m;
    }
  } 
  return 0;
}
