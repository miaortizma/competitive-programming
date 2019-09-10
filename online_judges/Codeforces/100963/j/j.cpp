#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b, ll & x, ll & y){
	if (a == 0) {
		x = 0;
		y = 1;
		return b;
	}
	ll x1, y1, g = gcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return g;
}

bool find_any_solution(ll a, ll b, ll c, ll & x0, ll & y0) {
  ll g = gcd(abs(a), abs(b), x0, y0);
  if (c % g)
    return false;
 
  x0 *= c / g;
  y0 *= c / g;
  if (a < 0) x0 = -x0;
  if (b < 0) y0 = -y0;
  return true;
}

void shift_solution(ll & x, ll & y, ll a, ll b, ll cnt) {
  printf("Solution %lld %lld Shift: %lld\n", x, y, cnt);
  x += cnt * b;
  y -= cnt * a;
  printf("Shifted Solution %lld %lld\n", x, y);
}

ll x, y;

void update_ans(ll & ans, ll val) {
  if (ans == 0) { 
    ans = val;
    cout << x << ' ' << y << '\n';
    cout << ans << ' ' << val << '\n';
  } else if (val < ans){
    ans = val;
    cout << x << ' ' << y << '\n';
    cout << ans << ' ' << val << '\n';
  }
}

void solve (ll n, ll m, ll a, ll k) {
  ll ans = 0;
  if (find_any_solution(-m, a, n - k, x, y)) {
    printf("Any solution\n");
    printf("%lld %lld\n", x, y);
    int sign_a = -1;
    int sign_b = 1;
    shift_solution(x, y, m, a, -(1 - y) / m);
    
    if (y < 0)
      shift_solution(x, y, m, a, -1);
    ll bx = x, by = y;
    cout << bx << ' ' << by << "@\n";
    for (int i = 0; i < 5; ++i) {
      shift_solution(x, y, m, a, 1);
      if (abs(y) > 0)
        update_ans(ans, k + abs(y) * abs(a));
    }
    x = bx;
    y = by;
    for (int i = 0; i < 5; ++i) {
      shift_solution(x, y, m, a, -1);
      if (abs(y) > 0)
        update_ans(ans, k + abs(y) * abs(a));
    }
    printf("Ans: %lld\n", ans);
  } else {
    printf("Impossible\n");
  }
}

int main() {
	ll n, m, a, k;
	while (scanf("%lld %lld %lld %lld\n", &n, &m, &a, &k) == 4) {
		if (n == 0 && m == 0 && a == 0 && k == 0) break;
    solve(n, m, a, k);
	}
  return 0;
}
