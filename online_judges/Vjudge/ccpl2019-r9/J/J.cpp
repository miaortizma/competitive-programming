#include<bits/stdc++.h>
using namespace std;
struct pt {
  int x, y;
  pt(int x, int y) : x(x), y(y) {}
  pt operator+(pt p) {return {x+p.x, y+p.y};}
  pt operator-(pt p) {return {x-p.x, y-p.y};}
};

const int N = 41;
int sz[N], arr[N];
vector<pt> polys[N];

int ori(pt p, pt q, pt r) {
  long long val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
  if (val == 0) return 0; //colinear
  return (val > 0) ? 1 : -1; //clock or counterclock wise
}

long long dot(pt v, pt w) {return v.x*w.x + v.y*w.y;}
bool inDisk(pt a, pt b, pt p) {return dot(a-p, b-p) <= 0;}
bool above(pt a, pt p) {return p.y >= a.y;}
bool onSegment(pt a, pt b, pt p) {return ori(a, b, p) == 0 && inDisk(a, b, p);}
bool crossesRay(pt a, pt p, pt q) { return (above(a,q) - above(a,p)) * ori(a, p, q) > 0;}

bool segInter(pt a, pt b, pt x, pt y) {
  int o1 = ori(a, b, x), o2 = ori(a, b, y), o3 = ori(x, y, a), o4 = ori(x, y, b);
  if (o1 != o2 && o3 != o4)
    return true;
  if (o1 == 0 && onSegment(a, b, x)) return true;
  if (o2 == 0 && onSegment(a, b, y)) return true;
  if (o3 == 0 && onSegment(x, y, a)) return true;
  if (o4 == 0 && onSegment(x, y, b)) return true;
  return false;
}

bool inPolygon(vector<pt> p, pt a) {
  int numCrossings = 0;
  for (int i = 0, n = p.size(); i < n; ++i)
    numCrossings += crossesRay(a, p[i], p[(i+1)%n]);
  return numCrossings & 1;
}

bool polyInter(vector<pt> A, vector<pt> B) {
  int n = A.size(), m = B.size();
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (segInter(A[i], A[(i+1)%n], B[j], B[(j+1)%m]))
        return true;
  if (inPolygon(B, A[0]) || inPolygon(A, B[0]))
    return true;
  return false;
}

//DSU
int root(int i) {
  while (arr[i] != i) {
    arr[i] = arr[arr[i]];
    i = arr[i];
  }
  return i;
}

void merge(int x, int y) {
  x = root(x), y = root(y);
  if (x == y)
    return;
  if (sz[x] < sz[y])
    swap(x, y);
  if (sz[x] == sz[y])
    ++sz[x];
  arr[y] = x;
}


int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, x, y;
  string s;
  while(cin >> n) {
    if (n == 0) break;
    for (int i = 0; i < n; ++i)
      arr[i] = i;

    getline(cin, s);
    for (int i = 0; i < n; ++i) {
      getline(cin, s);
      vector<pt> poly;
      stringstream ss(s);
      while (ss >> x >> y) {
        pt point{x, y};
        poly.push_back(point);
        //cerr << point.x << ' ' << point.y << ' ';
      }
      //cerr << '\n';
      polys[i] = poly;
    }
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (polyInter(polys[i], polys[j])) {
          //cerr << "merge:\n";
          //cerr << i << ' ' << j << '\n';
          merge(i, j);
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
      if (arr[i] == i)
        ++ans;
    cout << ans << '\n';
  }
  
  return 0;
}
