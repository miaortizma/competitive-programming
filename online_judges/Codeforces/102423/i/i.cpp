#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int N = 1e6 + 100;
vector<string> mat;
vector<int> adj[N];
int r, c, n, we, wo;

int sz[N], arr[N];


pii idd(int i, int j) {
  if ((i + j) % 2 == 0) {
    if (j < 0)
      --j;
    return {i, j / 2};
  } else {
   --j;
    if (j < 0)
      --j;
    return {i, j / 2};
  }
}

int idd2(int i, int j) {
  if (i < 0 || i >= r)
    return 0;
  pii aux = idd(i, j);
  if (i % 2 == 0) {
    if (aux.second < 0 || aux.second >= we)
      return 0;
    return 1 + (i / 2) * (we + wo) + aux.second;
  } else {
    if (aux.second < 0 || aux.second >= wo) {
      return 0;
    }
    return -1;
  }
  return -1;
}

int root(int i) {
  while (arr[i] != i) {
    arr[i] = arr[arr[i]];
    i = arr[i];
  }
  return i;
}

void un(int x, int y) {
  x = root(x), y = root(y);
  if (x == y) return;
  if (sz[x] < sz[y]) swap(x, y);
  arr[y] = x;
  sz[x] += sz[y];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  string s;
  cin >> r >> c;
  vector<string> mmat;
  for (int i = 0; i < r; ++i) {
    cin >> s;
    mmat.push_back(s);
  }
  if (r == 1 || c == 1) {
    cout << 0;
    return 0;
  }
  // even := / at 0 0  parity 0
  bool even = true;
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j)
      if ((i + j) % 2 == 0 && mmat[i][j] == '\\')
        even = false;
  if (!even) {
    s = "";
    for (int i = 0 ; i < c; ++i)
      s += '.';
    mat.push_back(s);
    for (string ss : mmat)
      mat.push_back(ss);
    ++r;
  } else {
    mat = mmat;
  }
  we = c / 2;
  wo = (c - 1) / 2;
  
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      pii a, b;
      if ((i + j) % 2 == 0) {
        a = idd(i, j);
        b = idd(i - 1, j - 1);
        cout << idd2(i, j) <<  " " << idd2(i - 1, j - 1) << "\n";
      } else {
        a = idd(i, j);
        b = idd(i - 1, j + 1);
        cout << idd2(i, j) <<  " " << idd2(i - 1, j + 1) << "\n";
      }
      cout << "connects: " << a.first << " " << a.second << " with: " << b.first << " " << b.second << "\n";
    }
  }
  
  return 0;
}
