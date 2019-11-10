#include<bits/stdc++.h>
using namespace std;


// find f1(p) = f2(q)
// (a^(np)) = (b * a ^ q)
// 
int solve(int a, int b, int m) {
  int n = (int) sqrt (m + .0) + 1;
  int an = 1;
  for (int i = 0; i < n; ++i)
    an = (an * 1ll * a) % m;
  map<int, vector<int>> vals;
  for (int p = 1, cur = an; p <= n; ++p) {
    vals[cur].push_back(p);
    cur = (cur * 1ll * an) % m;
  }

  for (int q = 0, cur = b; q <= n; ++q) {
    if (vals[cur].size() > 0) {
      for (int i = 0, s = vals[cur].size(); i < s; ++i) {
        int ans = vals[cur][i] * n - q;
        cout << ans << "\n";
      }
    }
    cur = (cur * 1ll * a) % m;
  }
  return -1;
}

int main() {
  solve(2, 9, 13);
  return 0;
}

