#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma
//
string p = "abacaba";
bool abacaba(string s, int pos) {
  if (pos < 0 || pos + p.length() - 1 >= s.length()) return false;
  for (size_t i = 0; i < p.length(); ++i) {
    if (s[i + pos] != '?' && s[i + pos] != p[i]) return false;
  }
  return true;
}

bool abacaba2(string s, int pos) {
  if (pos < 0 || pos + p.length() - 1 >= s.length()) return false;
  for (size_t i = 0; i < p.length(); ++i) {
    if (s[i + pos] != p[i]) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int T;
  cin >> T;
  int n;
  string s;
  while (cin >> n >> s) {
    bool ok = false;
    int c = 0;
    for (int i = 0; i < n; ++i) {
      if (abacaba2(s, i)) c++;
    }
    if (c == 1) {
      ok = true;
      for (size_t i = 0; i < s.length(); ++i) {
        if (s[i] == '?') s[i] = 'd';
      }
    } else if (c == 0) {
      for (int i = 0; i < (int) s.length(); ++i) {
        if (abacaba(s, i)) {
          int dx[] = {-6, -4, 4, 6};
          string s2 = s;
          for (size_t j = 0; j < p.length(); ++j) {
            s2[i + j] = p[j];
          }
          bool conflicts = false;
          for (auto x : dx) {
            if (abacaba2(s2, i + x)) {
              conflicts = true;
              break;
            }
          }
          if (conflicts) continue;
          ok = true;
          for (size_t j = 0; j < p.length(); ++j) {
            s[i + j] = p[j];
          }
          for (size_t j = 0; j < s.length(); ++j) {
            if (s[j] == '?') s[j] = 'd';
          }
          break;
        }
      }
    }
    if (ok) {
      cout << "Yes\n" << s << "\n";
    } else {
      cout << "No\n";
    }
  }
  return 0;
}
