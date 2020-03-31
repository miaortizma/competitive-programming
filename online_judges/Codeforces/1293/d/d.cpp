#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

typedef unsigned long long ll;
typedef pair<ll, ll> pll;
const ll inf = 1e16;

ll x00, y00, ax, ay, bx, by, xs, ys, t, x, y;

vector<pll> v;
bool used[70];

ll dist(pll lh, pll rh) {
  return max(lh.first, rh.first) - min(lh.first, rh.first) + max(lh.second, rh.second) - min(lh.second, rh.second);
}

int solve(size_t p, ll t) {
  pll cur{xs, ys};
  memset(used, false, sizeof used);
  //cerr << "solve: " << p << " " << t << "\n";
  int ret = 0;
  //cerr << "x: " << x << " y :" << y << "\n";
  //cerr << "first: " << v[p].first << " second" << v[p].second << "\n";
  ll d = dist(cur, v[p]);
  //cerr << d << " " << t << "\n";
  if (d > t) {
    return ret;
  } else {
    ret++;
    cur = v[p];
    used[p] = true;
    t -= d;
  }
  //cerr << "Here\n";
  while (p > 0) {
    p--;
    d = dist(cur, v[p]);
    if (d > t) {
      return ret;
    } else {
      ret++;
      t -= d;
      cur = v[p];
      used[p] = true;
    }
  }
  while (p + 1 < v.size()) {
    p++;
    d = dist(cur, v[p]);
    if (d > t) {
      return ret;
    } else {
      if (!used[p]) ret++;
      t -= d;
      cur = v[p];
    }
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> x00 >> y00 >> ax >> ay >> bx >> by >> xs >> ys >> t;
  x = x00;
  y = y00;
  while (x <= inf * 3 && y < inf * 3) {
    v.push_back({x, y});
    x = x * ax + bx;
    y = y * ay + by;
  }
  int ans = 0;
  for (size_t i = 0; i < v.size(); ++i) {
    ans = max(ans, solve(i, t));
  }
  cout << ans << "\n";
  return 0;
}
