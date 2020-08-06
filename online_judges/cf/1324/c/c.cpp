#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int last = s.size() + 1, ans = 0;
    for (int i = s.size(); i > 0; --i) {
      ans = max(last - i, ans);
      if (s[i - 1] == 'R') {
        last = i;
      }
    }
    ans = max(ans, last);
    cout << ans << "\n";
  }
  return 0;
}
