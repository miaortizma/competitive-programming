#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma
#define PB push_back
#define F first
#define S second
typedef pair<int, int> pi;
vector<pair<pi, int>> v;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, m;
  int l, r;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> l >> r;
    v.PB({{l, r}, i + 1});
  }
  sort(v.begin(), v.end());
  int nex = 1;
  int i = 0;
  int ans = 0;
  vector<int> solution;
  while (nex <= m && i < n) {
    int rmax = 0, b = -1;
    while (i < n && v[i].F.F <= nex) {
      if (v[i].F.S >= nex && v[i].F.S > rmax) {
        rmax = v[i].F.S;
        b = v[i].S;
      }
      ++i;
    }
    if (b == -1) {
      break;
    } else {
      nex = rmax + 1;
      solution.PB(b);
      ans++;
    }
  }
  if (nex == m + 1) {
    cout << "YES\n";
    cout << ans << "\n";
    for (auto v : solution) {
      cout << v << " ";
    }
  } else {
    cout << "NO";
  }
  return 0;
}
