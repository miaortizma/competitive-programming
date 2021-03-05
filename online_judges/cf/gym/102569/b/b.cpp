#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, t;
  cin >> n >> t;
  vector<int> v(n + 1);
  v[n] = 1e9 + 100;
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  int l = 0, h = n;
  while (l < h) {
    int m = l + (h - l) / 2;
    if (v[m] <= 0) {
      l = m + 1;
    } else {
      h = m;
    }
  }
  int ans = 0;
  for (int i = 0; i < l; ++i) {
    if (abs(v[i]) > t) {
      continue;
    }
    int left = max(0, t - 2 * abs(v[i]));
    int cur = l - i;
    if (left) {
      int ll = l, hh = n;
      while (ll < hh) {
        int m = ll + (hh - ll + 1) / 2;
        if (v[m] > left) {
          hh = m - 1;;
        } else {
          ll = m;
        }
      }
      if (v[ll] <= left) {
        cur += ll - l + 1;
      }
    }
    ans = max(ans, cur);
  }
  for (int i = l; i < n; ++i) {
    if (v[i] > t) break;
    int left = max(0, t - 2 * v[i]);
    int cur = i - l + 1;
    if (left) {
      int ll = 0, hh = l;
      while (ll < hh) {
        int m = ll + (hh - ll) / 2;
        if (abs(v[m]) > left) {
          ll = m + 1;
        } else {
          hh = m;
        }
      }
      if (v[ll] <= left) {
        cur += l - ll;
      }
    }
    ans = max(ans, cur);
  }
  cout << ans;

  return 0;
}
