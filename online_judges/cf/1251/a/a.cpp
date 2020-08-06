#include<bits/stdc++.h>
using namespace std;
const char FIRST = 'a';
bool ok[256];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int n = s.size();
    s = "*" + s + "*";
    memset(ok, false, sizeof ok);
    for (int i = 1; i <= n; ++i) {
      int c = 1;
      while (i <= n && s[i + 1] == s[i]) {
        ++i;
        ++c;
      }
      if (c % 2 == 1) {
        ok[s[i]] = true;
      }

    }
    for (int i = 0; i < 26; ++i) {
      if (ok[FIRST + i]) {
        cout << char(FIRST + i);
      }
    }
    cout << "\n";
  }
  return 0;
}
