#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  string s, p;
  cin >> s >> p;
  int n = s.size(), m = p.size();
  int ans = 0;
  for (int i = 0; i < n - m + 1; ++i) {
    bool ok = true;
    for (int j = 0; j < m; ++j) {
      if (s[i + j] == p[j]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      ans += 1;
    }
  }
  cout << ans;
  return 0;
}
