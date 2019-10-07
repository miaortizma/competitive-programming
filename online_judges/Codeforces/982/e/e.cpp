#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll GCD(ll a, ll b) { return (b == 0) ? a : GCD(b, a % b); }
inline ll LCM(ll a, ll b) { return a / GCD(a, b) * b; }
inline ll normalize(ll x, ll mod) { x %= mod; if (x < 0) x += mod; return x; }
struct GCD_type { ll x, y, d; };
GCD_type ex_GCD(ll a, ll b) {
  if (b == 0) return {1, 0, a};
  GCD_type pom = ex_GCD(b, a % b);
  return {pom.y, pom.x - a / b * pom.y, pom.d};
}


int CRT(ll a[2], ll n[2]) {
  for (int i = 0; i < 2; ++i) normalize(a[i], n[i]);
  ll ans = a[0], lcm = n[0];
  auto pom = ex_GCD(lcm, n[1]);
  int x1 = pom.x;
  int d = pom.d;
  if ((a[1] - ans) % d != 0) return -1;
  ans = normalize(ans + x1 * (a[1] - ans) / d % (n[1] / d) * lcm, lcm * n[1] / d);
  lcm = lcm * n[1] / d; // lcm = LCM(lcm, n[i])
  return ans;
}

void updateAns(int & ans, int & xa, int & ya, int x) {
  if (x != -1) {
    
  }
}

ll n, m, x, y, vx, vy;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m >> x >> y >> vx >> vy;  
  if (vx == 0) {
    if (x == 0 || x == n) {
      if (vy)
        cout << x << ' ' << m;
      else
        cout << x << ' ' << 0;
    } else {
      cout << -1;
    }
  } else if (vy == 0) {
    if (y == 0 || y == m) {
      if (vx)
        cout << n << ' ' << y;
      else
        cout << 0 << ' ' << y;
    } else {
      cout << -1;
    }
  } else {
    ll mods[] = {n, m};
    int ans = -1, xa, ya;
    
    
  } 
  return 0;
}
