#include<bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAXN = 5 + 100000;
int bit[MAXN];

int query(int x) {
  int ans = 0;
  for (; x > 0; x -= x&-x) ans += bit[x];
  return ans;
}

void update(int x, int add) {
  for (; x < MAXN; x += x&-x) bit[x] += add;
}

int query(int l, int r) {
  if (l > r) return 0;
  return query(r) - query(l - 1);
}

int v[MAXN], l[MAXN], r[MAXN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) {
    int x; cin >> x;
    v[i] = x;
  }

  for (int i = 1; i <= n; ++i) {
    l[i] = query(1 + v[i], MAXN);
    update(v[i], 1);
  }
  fill(bit, bit + MAXN, 0);
  for (int i = n; i >= 1; --i) {
    r[i] = query(1 + v[i], MAXN);
    update(v[i], 1);
  }
  ll ans = 0LL;
  for (int i = 1; i <= n; ++i) ans += 1LL * min(l[i], r[i]);
  cout << ans << '\n';
  return 0;
}
