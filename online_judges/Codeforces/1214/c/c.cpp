#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  int n;
  string s;
  cin >> n >> s;
  stack<int> st;
  int a = 0, b = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') {
      ++a;
      st.push(1);
    } else {
      ++b;
      if (st.size() && st.top() == 1) {
        st.pop();
      } else {
        st.push(0);
      }
    }
  }
  if (a == b && st.size() <= 2) {
    cout << "Yes";
  } else {
    cout << "No";
  }
  return 0;
}
