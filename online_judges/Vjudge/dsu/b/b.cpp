#include<bits/stdc++.h>
using namespace std;

map<string, int> ids;
const int N = 2 * 1e5 + 10;
int I = 0;
int arr[N], sz[N];

int root(int i) {
  while (arr[i] != i) {
    arr[i] = arr[arr[i]];
    i = arr[i];
  }
  return i;
}

int merge(int x, int y) {
  x = root(x), y = root(y);
  if (x == y)
    return sz[x];
  if (sz[x] < sz[y])
    swap(x, y);
  sz[x] += sz[y];
  arr[y] = x;
  return sz[x];
}

int getId(string x) {
  if (ids.count(x) == 0) {
    ids[x] = I++;
    return I - 1;
  } else {
    return ids[x];
  }
}

int main() {
  cin.tie(NULL); ios::sync_with_stdio(0);
  int T;
  cin >> T;

  while (T--) {
    ids.clear();
    int n;
    cin >> n;
    I = 0;
    for (int i = 0; i <= 2 * n + 10; ++i) {
      arr[i] = i;
      sz[i] = 1;
    }
    string a, b;
    for (int i = 0; i < n; ++i) {
      cin >> a >> b;
      int x = getId(a), y = getId(b);
      //cout << x <<  ' ' << y << '\n';
      cout << merge(x, y) << '\n';
    }
  }
  return 0;
}

