#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 20;
ll GCD(ll a, ll b) { return (b == 0) ? a : GCD(b, a % b); }
inline ll LCM(ll a, ll b) { return a / GCD(a, b) * b; }
inline ll normalize(ll x, ll mod) { x %= mod; if (x < 0) x += mod; return x; }
ll exGCD(ll a, ll b, ll &x, ll &y) {
    if (b == 0)
      return x = 1, y = 0, a;
    ll x0, y0, g = exGCD(b, a % b, x0, y0);
    return x = y0, y = x0 - a / b * y0, g;
}

int t;
ll a[N], n[N], ans, lcm_;
int main() {
    cin >> t;
    for(int i = 1; i <= t; i++) cin >> a[i] >> n[i], normalize(a[i], n[i]);
    ans = a[1];
    lcm_ = n[1];
    for(int i = 2; i <= t; i++) {
        ll x1, y1, g = exGCD(lcm_, n[i], x1, y1);
        if((a[i] - ans) % g != 0) return cout << "No solutions" << endl, 0;
        ans = normalize(ans + x1 * (a[i] - ans) / g % (n[i] / g) * lcm_, lcm_ * n[i] / g);
        lcm_ = LCM(lcm_, n[i]); // you can save time by replacing above lcm * n[i] /d by lcm = lcm * n[i] / d
    }
    cout << ans << " " << lcm_ << endl;
    return 0;
}
