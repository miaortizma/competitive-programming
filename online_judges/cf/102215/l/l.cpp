#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma


typedef long long ll;

int sq(int x) { return x * x; }

typedef long double T;
struct pt {
  T x, y;
  pt (T x, T y) : x(x), y(y) {}

  pt operator+ (pt p) {
    return {x + p.x, y + p.y};
  }

  pt operator- (pt p) {
    return {x - p.x, y - p.y};
  }

  pt operator* (T d) {
    return {x * d, y * d};
  }

  pt operator/ (T d) {
    return {x / d, y / d};
  }
};

T sq(T x) {
  return x * x;
}

T sq(pt p) {
  return sq(p.x) + sq(p.y);
}

long double abs(pt p) {
  return sqrt(sq(p));
}



int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  cout << fixed << setprecision(15);

  int x1, y1, r1;
  int x2, y2, r2;

  cin >> x1 >> y1 >> r1;
  cin >> x2 >> y2 >> r2;

  pt p1{x1, y1}, p2{x2, y2};

  if (r1 < r2) {
    swap(p1, p2);
    swap(r1, r2);
  }

  pt dir = p2 - p1;
  dir = dir / abs(dir);

  T d = abs(p2 - p1);
  T a1 = d - r2, a2 = r1;
  T r3 = a2 - (a1 + a2) / 2.0;

  dir = p1 + dir * ((a1 + a2) / 2.0) ;

  cout << dir.x << " " << dir.y << " " << r3;
  return 0;
}
