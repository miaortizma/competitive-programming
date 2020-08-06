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

bool find_any_solution(ll a, ll b, ll c, ll & x0, ll & y0, ll & g) {
  g = gcd(abs(a), abs(b), x0, y0);
  if (c % g)
    return false;
 
  x0 *= c / g;
  y0 *= c / g;
  if (a < 0) x0 = -x0;
  if (b < 0) y0 = -y0;
  return true;
}

void shift_solution(ll & x, ll & y, ll a, ll b, ll cnt) {
  x += cnt * b;
  y -= cnt * a;
}

void upAns(ll &ans, ll val, ll n, ll m, ll a, ll k) {
  if ( (val - n) % m == 0 && (val - k) % a == 0 ) {
    if (ans == 0)
      ans = val;
    else
      ans = min(ans, val);
  }
}

void solve (ll n, ll m, ll a, ll k) {
  if (m == 0 || a == 0) {
    if (a == 0) {
      printf("Impossible\n"); 
      return;
    }
    if (m == 0) {
      if ((n - k) > 0 && (n - k) % a == 0) {
        printf("%lld\n", n);
      } else {
        printf("Impossible\n");
      }
    }
  }
    if (n - k > 0 && (n - k) % a == 0) {
    printf("%lld\n", n);
  } else {
    if (n < k) {
      swap(n, k);
      swap(m, a);
    }
    ll x, y, g, mm = m;
    //cerr << "m: " << m << " n: " << n << " x: " << x << " y:" << y << "\n";
    if (find_any_solution(m, a, n - k, x, y, g)) {
      m /= g;
      a /= g;
      ll ans = 0;

      if (abs(x) > 0 && abs(y) > 0) upAns(ans, n + mm * abs(x), n, m, a, k);
      /*cerr << "m: " << m << " n: " << n << " x: " << x << " y:" << y << "\n";
      cerr << m * x + a * y << "\n";
      cerr << "ans: " << ans << "\n\n";*/
      
      
      shift_solution(x, y, m, a, -(x + a - 1) / a);
      for (int i = 0; i < 3; ++i) {
        if (abs(x) > 0 && abs(y) > 0) upAns(ans, n + mm * abs(x), n, m, a, k);
        /*cerr << "m: " << m << " n: " << n << " x: " << x << " y:" << y << "\n";
        cerr << m * x + a * y << "\n";
        cerr << "ans: " << ans << "\n\n";*/
        
        shift_solution(x, y, m, a, -1);
      }
      find_any_solution(m, a, n - k, x, y, g);
      shift_solution(x, y, m, a, -(x + a - 1) / a);
      for (int i = 0; i < 3; ++i) {
        if (abs(x) > 0 && abs(y) > 0) upAns(ans, n + mm * abs(x), n, m, a, k);
        
        /*cerr << "m: " << m << " n: " << n << " x: " << x << " y:" << y << "\n";
        cerr << m * x + a * y << "\n";
        cerr << "ans: " << ans << "\n\n";*/
        
        
        shift_solution(x, y, m, a, 1);
      }
      if (ans == 0) {
        printf("Impossible\n");
      } else {
        printf("%lld\n", ans);
      }
    } else {
      printf("Impossible\n");
    }
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
