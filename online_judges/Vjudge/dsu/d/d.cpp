#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 510;
int arr[N], sz[N];

struct point {
  int x, y;
  point() : x(0), y(0) {}
  point(int x, int y) : x(x), y(y) {}
};

point points[N];

ll sq(int x) { return x * x; }

ll distsq(point a, point b) { return sq(a.x - b.x) + sq(a.y - b.y); }

double dist(point a, point b) { return sqrt(distsq(a, b)); }

int root(int i) {
  while (i != arr[i]) {
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

int s, n, x;

typedef pair<ll, pair<int, int>> edge;


bool MST1(ll D) {
  D /= 10000;
  //cout << "try MST with: " << sqrt(D) << "\n";
  for (int i = 0; i < n; ++i) {
    sz[i] = 0;
    arr[i] = i;
  }
  vector< edge > edges;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      ll d = distsq(points[i], points[j]);
      //cout << i << " " << j << " " << sqrt(d) << '\n';
      if (d <= D)
        edges.push_back(edge{d, {i, j}});
    }
  }
  sort(edges.begin(), edges.end());
  int left = n - 1; // tree edges
  for (int i = 0, m = edges.size(); i < m; ++i) {
    ll d = edges[i].first;
    int a = edges[i].second.first, b = edges[i].second.second;
    //cout << a << " " << b << " " << sqrt(d) << "\n";
    a = root(a), b = root(b);
    if (a != b) {
      //cout << "merge!\n";
      merge(a, b);
      --left;
    }
    if (left == s - 1) // free edges
      break;
  }
  //cout << left << ' ' << s - 1 << ":compare\n";
  return (s == 0 && left == 0) || left == s - 1;
}


ll MST() {
  for (int i = 0; i < n; ++i) {
    sz[i] = 0;
    arr[i] = i;
  }
  vector< edge > edges;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      ll d = distsq(points[i], points[j]);
      edges.push_back(edge{d, {i, j}});
    }
  }
  sort(edges.begin(), edges.end());
  int left = n - 1; // tree edges
  ll ret = 0;
  for (int i = 0, m = edges.size(); i < m; ++i) {
    ll d = edges[i].first;
    int a = edges[i].second.first, b = edges[i].second.second;
    a = root(a), b = root(b);
    if (a != b) {
      merge(a, b);
      ret = max(ret, d);
      --left;
    }
    if (left == s - 1) // free edges
      break;
  }
  return ret;
}

const double EPS = 1e-3;

void solve() {
  ll ans = round(sqrt(MST()) * 100);
  ll a = ans / 100, b = ans % 100;
  cout << a << ".";
  if (b < 10)
    cout << "0";
  cout << b << "\n";
}

void solve1() {
 ll l = 0, h = 1e12 + 10;
  while (l < h) {
    ll mid = l + (h - l) / 2;
    if (MST1(mid)) {
      h = mid;
    } else {
      l = mid + 1;
    }
  }
  ll ans = round(sqrt(l));
  ll a = ans / 100, b = ans % 100;
  cout << a << ".";
  if (b < 10)
    cout << "0";
  cout << b << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout << fixed << setprecision(2);
  int T; 
  cin >> T;
  while (T--) {
    cin >> s >> n;
    int x, y;
    for (int i = 0; i < n; ++i) {
      cin >> x >> y;
      points[i] = point(x, y);
    }
    solve();
  }
  return 0;
}
