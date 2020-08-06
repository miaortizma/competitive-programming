#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  string s;
  cin >> s;
  int n = s.size(), balance = 0;
  int b = 0, cur = 0;
  set<pii> st;
  for (int i = 0; i < n; ++i) {
    cur++;
    if (s[i] == '(') balance++;
    else balance--;
    if (balance == 0) {
      if (cur > b) st.clear();
      b = max(b, cur);
      if (cur == b) st.insert({i - cur + 1, i});
    } 
    if (balance < 0) {
      balance = 0;
      cur = 0;
    }
  }
  cur = 0;
  balance = 0;
  for (int i = n - 1; i >= 0; --i) {
    cur++;
    if (s[i] == '(') balance--;
    else balance++;
    if (balance == 0) {
      if (cur > b) st.clear();
      b = max(b, cur);
      if (cur == b) st.insert({i, i + cur - 1});
    } 
    if (balance < 0) {
      balance = 0;
      cur = 0;
    }
  }


  if (st.size() == 0)
    cout << b << " " << 1 << "\n";
  else
    cout << b << " " << st.size() << "\n";
  return 0;
}
