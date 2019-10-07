#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

struct pt {
  int a, b;
  pt (int a, int b) : a(a), b(b) {}
};

ostream & operator << (ostream &out, const pt &p) {
  out << p.a << ' ' << p.b << '\n';
  return out;
}

const int N = 250;
vector<pt> v;
bool used[N], assignment[N];
int comp[N];
vector<int> order, g[N], gt[N];

void dfs1(int v) {
  used[v] = true;
  for (int u : g[v]) {
    if (!used[u])
      dfs1(u);
  }
  order.push_back(v);
}

void dfs2(int v, int cl) {
  comp[v] = cl;
  for (int u : gt[v]) {
    //cout << "gt[v]: " << v << " " << u << "\n";
    if (comp[u] == 0)
      dfs2(u, cl);
  }
}

bool solve_2SAT(int n) {
  for (int i = 0; i < n; ++i) {
    if (!used[i]) {
      dfs1(i);
    }
  }

  for (int i = 0, j = 0; i < n; ++i) {
    int v = order[n - i - 1];
    if (comp[v] == 0)
      dfs2(v, ++j);
    //cout << "v: " << v << "\n";
    //cout << comp[v] << "\n";
  }


  for (int i = 0; i < n; i += 2) {
    if (comp[i] == comp[i + 1])
      return false;
    assignment[i / 2] = comp[i] > comp[i + 1];
  }
  return true;
}

bool inside(int x1, int x2, int y) {
  if (x1 < x2)
    return x1 < y && y < x2;
  if (x1 > x2)
    return x1 < y || y < x2;
  return false;
}

bool inter(pt A, pt B) {
  if (inside(B.a, B.b, A.a))
    return inside(B.b, B.a, A.b);
  if (inside(B.a, B.b, A.b))
    return inside(B.b, B.a, A.a);
  return false;
}

void addEdge(int i, bool I, int j, bool J) {
  g[i * 2 | I].push_back(j * 2 | !J);
  g[j * 2 | J].push_back(i * 2 | !I);
  gt[j * 2 | !J].push_back(i * 2 | I);
  gt[i * 2 | !I].push_back(j * 2 | J);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, m, a, b;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    v.push_back({a, b});
  }
  for (int i = 0; i < m; ++i) {
    for (int j = i + 1; j < m; ++j) {
      if (inter(v[i], v[j])) {
        addEdge(i, true, j, true);
        addEdge(i, false, j, false);
      }
    }
  }
  /*
  for (int i = 0; i < 4; ++i) {
    cout << "i: " << i << '\n';
    for (int v : gt[i]) {
      cout << v <<  ' ';
    }
    cout << '\n';
  }
  */
  if (solve_2SAT(m * 2)) {
    for (int i = 0; i < m; ++i) {
      if (assignment[i])
        cout << "i";
      else
        cout << "o";
    }
  } else {
    cout << "Impossible\n";
  }
  return 0;
}
