#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Point {
  ll x, y;
  
  Point() : x(0), y(0) {}
  Point(ll x, ll y) : x(x), y(y) {}
};

Point operator * (ll a, Point p) { return Point(a * p.x, a * p.y); }
Point operator + (Point lh, Point rh) { return Point(lh.x + rh.x, lh.y + rh.y); }
Point operator - (Point lh, Point rh) { return Point(lh.x - rh.x, lh.y - rh.y); }
ostream& operator << (ostream& os, Point p) { return os << p.x << " " << p.y << "\n"; }

Point zero{0, 0};

Point walk(Point pos, ll n, ll k, Point baseX, Point baseY) {
  if (n == 0)
    return pos;
  ll subsize = 1LL << (2 * n - 2), side = 1LL << (n - 1);
  if (k <= subsize) {
    return walk(pos, n - 1, k, baseY, baseX);
  } else if (k <= 2 * subsize) {
    return walk(pos + side * baseY, n - 1, k - subsize, baseX, baseY);
  } else if (k <= 3 * subsize) {
    return walk(pos + side * baseY + side * baseX, n - 1, k - subsize * 2, baseX, baseY);
  } else {
    return walk(pos + (2 * side - 1) * baseX + (side - 1) * baseY, n - 1, k - subsize * 3, zero - baseY, zero - baseX);
  }
}

int count(ll p) {
  int ret = 1;
  while (p) {
    p >>= 1;
    ++ret;
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  ll n, k;
  Point baseX{1, 0};
  Point baseY{0, 1};
  Point start{1, 1};
  while (cin >> n >> k) {
    Point ans = walk(start, count(n), k, baseX, baseY);
    cout << ans.x << " " << ans.y << "\n";
  }
  return 0;
}
