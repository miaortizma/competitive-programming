#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

constexpr int MAXN = 5 + 100000;

int n;

struct P {
  int x,y,r;
  long double d;
} points[MAXN];

long double dist(const P& p, const P& q) {
  long double dx = p.x - q.x, dy = p.y - q.y;
  return sqrt(dx*dx + dy*dy);
}

bool ok(long double r) {
  for (int i = 0; i < n; ++i) {
    if (points[i].d <= r) {
      r += points[i].r;
    } else return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  P pcent;
  cin >> n >> pcent.x >> pcent.y;
  for (int i = 0; i < n; ++i) {
    cin >> points[i].x >> points[i].y >> points[i].r;
    points[i].d = dist(points[i], pcent) - points[i].r;
    //cout << "el radio debe ser minimo " << points[i].d << '\n';
  }
  sort(points, points + n, [](const P& p, const P& q)->bool{
      return p.d < q.d;
      });
  long double low = 0.0, high = 1e10;
  for (int i = 0; i < 500; ++i) {
    long double mid = (low + high) /  2.0;
    if (ok(mid)) {
      high = mid;
    } else {
      low = mid;
    }
  }
  cout << fixed << setprecision(10) << low << '\n';
  return 0;
}
