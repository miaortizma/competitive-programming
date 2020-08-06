#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1, M = 36000;

int n, nn, di, c, a, b, x, y, h;
int t[2 * N + 10], d[N + 10];
vector<int> arr[M];

void apply(int p, int value) {
  t[p] += value;
  if (p < n) d[p] += value;
}

void build(int p) {
  while (p > 1) p >>= 1, t[p] = max(t[p<<1], t[p<<1|1]) + d[p];
}

void push(int p) {
  for (int s = h; s > 0; --s) {
    int i = p >> s;
    if (d[i] != 0) {
      apply(i<<1, d[i]);
      apply(i<<1|1, d[i]);
      d[i] = 0;
    }
  }
}

void inc(int l, int r, int value) {
  l += n; r += n;
  int l0 = l, r0 = r;
  for (; l < r; l >>= 1, r >>= 1) {
    if (l&1) apply(l++, value);
    if (r&1) apply(--r, value);
  }
  build(l0);
  build(r0 - 1);
}

int query(int l, int r) {
  l += n, r += n;
  push(l);
  push(r - 1);
  int res = -2e9;
  for (; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = max(res, t[l++]);
    if (r&1) res = max(t[--r], res);
  }
  return res;
}


int main() {
  scanf("%d %d %d.%d", &nn, &di, &a, &b);
  c = a * 100 + b;
  for (int i = 0; i < nn; ++i) {
    scanf("%d %d.%d", &x, &a, &b);
    y = a * 100 + b;
    arr[y].push_back(x);
    n = max(n, x + 1);
  }
  h = sizeof(int) * 8 - __builtin_clz(n);
  for (int i = 0; i <= c; ++i) {
    for (int j = 0, m = arr[i].size(); j < m; ++j) {
      x = arr[i][j];
      inc(x, min(n, x + di + 1), 1);
    } 
  }
  int l = 0, r = c;
  int ans = 0;
  for (int i = 0; i < M; ++i) {
    ans = max(ans, query(1, n));
    for (int j = 0, m = arr[l].size(); j < m; ++j) {
      x = arr[l][j];
      inc(x, min(n, x + di + 1), -1);
    }
    l = (l + 1) % M;
    r = (r + 1) % M;
    for (int j = 0, m = arr[r].size(); j < m; ++j) {
      x = arr[r][j];
      inc(x, min(n, x + di + 1), 1);
    }
  }
  cout << ans;
  return 0;
}
