#include<bits/stdc++.h>
using namespace std;

typedef long long T;
struct pt{
  T x, y;
  pt () : x(0), y(0) {}
  pt (T x, T y) : x(x), y(y) {}
  pt operator-(pt p) {return {x-p.x, y-p.y};}
  bool operator==(pt p) {return x == p.x && y == p.y;}
  bool operator!=(pt p) {return x != p.x || y != p.y;}
};

ostream& operator<<(ostream& os, pt p) {return os << "(" << p.x << "," << p.y << ")";}

T dot(pt p, pt q) {return p.x*q.x + p.y*q.y;}
T cross(pt p, pt q) {return p.x*q.y - p.y*q.x;}
T sq(pt p) {return p.x*p.x + p.y*p.y;}

struct line {
  pt v; T c;
  // From direction vector v and offset c
  line(pt v, T c) : v(v), c(c) {}
  // From equation ax+by=c
  line(T a, T b, T c) : v(b, -a), c(c) {}
  // From points P and Q
  line(pt p, pt q) : v(q-p), c(cross(v,p)) {}
  T side(pt p) {return cross(v, p)-c;}
  T sqDist(pt p) {return side(p)*side(p)/sq(v);}
  bool cmpProj(pt p, pt q) {return dot(v,p) < dot(v,q);}
};

double segPoint(pt a, pt b, pt p) {
  if (a != b) {
    line l(a, b);
    if (l.cmpProj(a,p) && l.cmpProj(p,b)) return l.sqDist(p);
  }
  return min(sq(p-a), sq(p-b));
}

const int N = 1001;
pt poly[N];
int n, m, a, b, c, d, x, y;
int vis[N][N], can[N][N], mark;
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

bool in(pt x) {return 0 <= x.x && x.x <= N && 0 <= x.y && x.y <= N;}

void dfs(pt u) {
  vis[u.x][u.y] = mark;
  for (int i = 0; i < 8; ++i) {
    x = u.x + dx[i], y = u.y + dy[i];
    pt v{x, y};
    if (in(v) && vis[x][y] != mark && can[x][y] != mark)
      dfs(v);
  }
}

void fill(pt p, pt q, pt r) {
  can[r.x][r.y] = mark;
  for (int i = 0; i < 8; ++i) {
    x = r.x + dx[i], y = r.y + dy[i];
    pt u{x, y};
    T val = segPoint(p, q, r);
    if (in(u) && can[x][y] != mark && segPoint(p, q, u) <= m * m)
      fill(p, q, u);
  } 
}

int main() {
  ios_base::sync_with_stdio(0);cin.tie(NULL);
  while (cin >> n >> m) {
    if (n == 0 && m == 0) break;
    for (int i = 0; i < n; ++i) {
      cin >> x >> y;
      poly[i] = pt(x, y);
    }
    cin >> a >> b >> c >> d;
    ++mark;
    for (int i = 0; i < n; ++i) {
      pt p = poly[i], q = poly[(i+1)%n];
      if (p.x == q.x) {
        if (p.y > q.y)
          swap(p, q);
        for (int j = p.y; j <= q.y; ++j)
          fill(p, q, pt(p.x, j));
      } else {
        if(p.x > q.x)
          swap(p, q);
        for (int j = p.x; j <= q.x; ++j)
          fill(p, q, pt(j, p.y));
      }
    }
    dfs(pt(a, b));
    if (vis[c][d] == mark)
      cout << "Yes\n";
    else 
      cout << "No\n";
  }

  return 0;
}
