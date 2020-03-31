#include<bits/stdc++.h>
using namespace std;

int v(char c) {
  return c - '0';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int p = 0, o = 0, n = s.size();
    while (p < n && o < n) {
      while (p < n && v(s[p]) % 2 == 1)
        ++p;
      while (o < n && v(s[o]) % 2 == 0)
        ++o;
      if (p == n || o == n)
        break;
      if (v(s[p]) < v(s[o])) {
        cout << s[p];
        ++p; 
      } else {
        cout << s[o];
        ++o;
      }
    }
    while (p < n) {
      if (v(s[p]) % 2 == 0)
        cout << s[p];
      ++p;
    }
    while (o < n) {
      if (v(s[o]) % 2 == 1)
        cout << s[o];
      ++o;
    }
    cout << "\n";
  }
  return 0;
}
