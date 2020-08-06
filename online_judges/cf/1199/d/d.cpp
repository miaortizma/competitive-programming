#include<bits/stdc++.h>
using namespace std;
int n, m, v, t, p, x;

const int N = 4 * 1e5 + 100;

struct query {
  int t, p, x;
  query() : t(0), p(0), x(0) {}
  query(int t, int p, int x) : t(t), p(p), x(x) {}
} queries[N];


const int NN = 2 * 1e5 + 100;
int ans[NN];
bool vis[NN];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &v);
    queries[i] = {1, i + 1, v};
  }
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &t); 
    if (t == 1) {
      scanf("%d %d", &p, &x);
      queries[i + n] = {1, p, x};
    } else {
      scanf("%d", &x);
      queries[i + n] = {2, 0, x};
    }
  }
  int up = 0;
  for (int i = n + m - 1; i >= 0; --i) {
    query q = queries[i];
    t = q.t;
    if (t == 1) {
      if (!vis[q.p]) {
        vis[q.p] = true;
        ans[q.p] = max(q.x, up);
      }
    } else {
      up = max(up, q.x);
    }
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d ", ans[i]);
  }
  return 0;
}
