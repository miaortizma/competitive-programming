#include<bits/stdc++.h>
using namespace std;

const int N = 10000000;
int lp[N+1];
vector<int> pr;

struct FenwickTree {
  vector<int> bit;
  int n;

  FenwickTree(int n) {
    this-> n = n + 1;
    bit.assign(n + 1, 0);
  }

  FenwickTree(vector<int> a) : FenwickTree(a.size()) {
    for (size_t i = 0; i < a.size(); ++i)
      add(i, a[i]);
  }

  int sum(int idx) {
    int ret = 0;
    for (++idx; idx > 0; idx -= idx & -idx)
      ret += bit[idx];
    
    return ret;
  }

  int sum(int l, int r) {
    return sum(r) - sum(l - 1);
  }

  void add(int idx, int delta) {
    for (++idx; idx < n; idx += idx & -idx)
      bit[idx] += delta;
  }

};


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, x;
  cin >> n;

  FenwickTree BIT(N + 1);
  
  for (int i = 2; i <= N; ++i) {
      if (lp[i] == 0) {
          lp[i] = i;
          pr.push_back (i);
      }
      for (int j = 0; j < (int) pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
          lp[i * pr[j]] = pr[j];
  }
  
  for (int i = 0; i < n; ++i) {
    cin >> x;
    int last = lp[x];
    BIT.add(last, 1);
    while (lp[x] != x) {
      x /= lp[x];
      if (lp[x] != last)
        last = lp[x], BIT.add(last, 1);
    }
  }
  
  int q;
  cin >> q;
  
  while(q--) {
    int l, r;
    cin >> l >> r;
    if (l > N) {
       cout << 0 << '\n';
    } else {
      cout << BIT.sum(l, min(r, N)) << '\n';
    }
  }

  return 0;
}
