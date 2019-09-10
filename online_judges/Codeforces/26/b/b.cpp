#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  string s;
  cin >> s;
  stack<int> st;
  int n = s.size();
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') {
      st.push(1);
    } else {
      if (st.size()) {
        st.pop();
        ++ans;
      }
    }   
  } 

  cout << ans * 2 << '\n';
  return 0;
}
