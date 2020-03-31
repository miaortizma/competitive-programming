#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int T, n;
  string s;
  cin >> T;
  while (T--) {
    cin >> n;
    int zeros = 0, ones = 0;
    vector<string> strs;
    vector<int> szs;
    for (int i = 0; i < n; ++i) {
      cin >> s;
      strs.push_back(s);
      szs.push_back(s.size());
      for (char c : s) {
        if (c == '0') {
          ++zeros;
        } else {
          ++ones;
        }
      }
    }
    sort(szs.begin(), szs.end());
    int pairs = zeros / 2 + ones / 2;
    int ans = 0;
    for (int sz : szs) {
      if (sz / 2 <= pairs) {
        pairs -= sz / 2;
        ++ans;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
