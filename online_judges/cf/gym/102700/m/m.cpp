#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma
//
const int N = 2 * 1e5 + 10;
int last[26][N];

int cid(char c) {
  return c - 'a';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  string s, p;
  cin >> s;
  int m = s.size();
  for (int i = 0; i < 26; ++i) {
    last[i][m] = -1;
  }
  for (int i = m - 1; i >= 0; --i) {
    int cur = cid(s[i]);
    for (int j = 0; j < 26; ++j) {
      last[j][i] = last[j][i + 1];
    }
    last[cur][i] = i;
  }
  int t;
  cin >> t;
  while (t--) {
    cin >> p;
    int ans = 0;
    int n = p.size();
    int j = 0;
    for (int i = 0; i < n; ++i) {
      if (j >= m) break;
      int cur = cid(p[i]);
      int ne = last[cur][j];
      if (ne == -1) {
        break;
      } else {
        j = ne + 1;
        ans++;
      }
    }
    if (ans == 0) {
      cout << "IMPOSSIBLE\n";
    } else {
      for (int i = 0; i < ans; ++i) {
        cout << p[i];
      }
      cout << "\n";
    }
  }
  return 0;
}
