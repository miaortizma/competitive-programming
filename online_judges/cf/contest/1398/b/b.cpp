#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

#define PB push_back

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> v;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
        cur += 1;
      } else {
        if (cur) {
          v.PB(cur);
          cur = 0;
        }
      }
    }
    if (cur) {
      v.PB(cur);
    }
    sort(v.rbegin(), v.rend());
    int ans = 0;
    for (size_t i = 0; i < v.size(); ++i) {
      if (i % 2 == 0) {
        ans += v[i];
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
