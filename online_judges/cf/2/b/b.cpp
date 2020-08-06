#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

template<class F>
struct Point {
  F x, y;
  Point() : x(0), y(0) {}
  Point(const F& x, const F& y) : x(x), y(y) {}

  template <class F1> Point& operator += (const Point<F1>& other) {
    x += other.x; y += other.y; return *this; }

};


template <class F> ostream& operator << (ostream& os, Point<F>& point) {
 return os << point.x << ' ' << point.y;}

template <class F> inline Point<F> makePoint(const F& x, const F& y) { return Point<F>(x, y); }
template <class F> inline F min(Point<F>& point) { return min(point.x, point.y); }

#define FUNC1(name, arg, expr) \
template <class F> inline auto name(const arg) -> decltype(expr) { return expr; }
#define FUNC2(name, arg1, arg2, expr) \
template <class F1, class F2> \
inline auto name(const arg1, const arg2) -> decltype(expr) { return expr; } 


FUNC2(operator +, Point<F1>& lhs, Point<F2>& rhs, makePoint(lhs.x + rhs.x, lhs.y + rhs.y))
FUNC2(operator <, Point<F1>& lhs, Point<F2>& rhs,
  lhs.x < rhs.x || (lhs.x == rhs.x && lhs.y < rhs.y))
const int N = 1005;
int mat[N][N];
char rec[N][N][2];
Point<int> dp[N][N][2];


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> mat[i][j];

  
  int x0, y0;
  bool zero = false;
  
  for (int i = n - 1; i >= 0; --i) {
    for (int j = n - 1; j >= 0; --j) {
      int twos = 0, fives = 0;
      int x = mat[i][j];
      if (x == 0) {
        x0 = i;
        y0 = j;
        zero = true;
        dp[i][j][0] = dp[i][j][1] = makePoint(1, 1);
        continue;
      }
      while (x % 2 == 0) {
        ++twos;
        x /= 2;
      }
      while (x % 5 == 0) {
        ++fives;
        x /= 5;
      }

      if (i == n - 1 && j == n - 1) {
        dp[i][j][0] = makePoint(twos, fives);
        dp[i][j][1] = makePoint(fives, twos);
        continue;
      }

      if (i == n - 1) {
        dp[i][j][0] = makePoint(twos, fives) + dp[i][j+1][0];
        dp[i][j][1] = makePoint(fives, twos) + dp[i][j+1][1];
        continue;
      }

      if (j == n - 1) {
        dp[i][j][0] = makePoint(twos, fives) + dp[i+1][j][0];
        dp[i][j][1] = makePoint(fives, twos) + dp[i+1][j][1];
        continue;
      }
      
      if (dp[i][j+1][0] < dp[i+1][j][0] ) {
        Point<int> p{twos, fives};
        dp[i][j][0] = p + dp[i][j+1][0];
        rec[i][j][0] = 'R';
      } else {
        Point<int> p{twos, fives};
        dp[i][j][0] = p + dp[i+1][j][0];
        rec[i][j][0] = 'D';
      }
      
      if (dp[i][j+1][1] < dp[i+1][j][1]) {
        Point<int> p{fives, twos};
        dp[i][j][1] = p + dp[i][j+1][1];
        rec[i][j][1] = 'R';
      } else {
        Point<int> p{fives, twos};
        dp[i][j][1] = p + dp[i+1][j][1];
        rec[i][j][1] = 'D';
      }

      //cout << i << ' ' << j << ' '<< dp[i][j][0] << '\n';
    } 
  }

  Point<int> a = dp[0][0][0], b = dp[0][0][1];
  int path;
  if (min(a) < min(b))
    path = 0;
  else
    path = 1;
  if (min(dp[0][0][path]) > 1 && zero) {
    cout << 1 << '\n';
    for (int i = 0; i < x0; ++i)
      cout << 'D';
    for (int i = 0; i < y0; ++i)
      cout << 'R';
    for (int i = x0; i < n - 1; ++i)
      cout << 'D';
    for (int i = y0; i < n - 1; ++i)
      cout << 'R';
  } else {
    cout << min(dp[0][0][path]) << '\n';
    int x = 0, y = 0;
    while (x != n - 1 && y != n - 1) {
      char mov = rec[x][y][path];
      cout << mov;
      if (mov == 'R')
        ++y;
      else
        ++x;
      
      //cout << '\n' << x << ' ' << y << ':';
      //cout << dp[x][y][path] << '\n';
    }
    while (x != n - 1) {
      cout << 'D';
      ++x;
    }
    while (y != n - 1) {
      cout << 'R';
      ++y;
    }
  }
  
  return 0;
}
