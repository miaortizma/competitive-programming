#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;
int n;

struct S {
  int longest, unmatched_left, unmatched_right;

  S() : longest(0), unmatched_left(0), unmatched_right(0) {}
  S(int l, int u_left, int u_right) : longest(l), unmatched_left(u_left), unmatched_right(u_right) {}
} t[2 * N];

S merge(S X, S Y) {
  int merged = min(X.unmatched_right, Y.unmatched_left);
  S res{X.longest + Y.longest + merged * 2,
    X.unmatched_left + Y.unmatched_left - merged,
    X.unmatched_right - merged + Y.unmatched_right};

  return res;
}

void build() {
  for (int i = n - 1; i > 0; --i) t[i] = merge(t[i<<1], t[i<<1|1]);
}

int query(int l, int r) {
  S resl, resr;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) resl = merge(resl, t[l++]);
    if (r&1) resr = merge(t[--r], resr);
  }

  return merge(resl, resr).longest;
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  
  string s;
  int q, l, r;
  cin >> s >> q;
  
  S a{0, 1, 1}, b{0, 1, 1};
  S x = merge(a, b);

  n = s.size();
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(')
      t[i + n].unmatched_right = 1;
    else
      t[i + n].unmatched_left = 1;
  }

  build();
  
  while(q--) {
    cin >> l >> r;
    cout << query(l - 1, r) << '\n';
  }

  return 0;
}
