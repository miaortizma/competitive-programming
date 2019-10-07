#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  set<int> st;
  int n, t;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> t;
    st.insert(t);
  }
  if (st.size() > 3) {
    cout << -1;
    return 0;
  }
  vector<int> v;
  for (auto n : st) {
    v.push_back(n);
  }
  sort(v.begin(), v.end());
  if (v.size() == 3) {
    if (abs(v[0] - v[1]) != abs(v[1] - v[2])) {
      cout << -1;
      return 0;
    }
    int ans = v[1] - v[0];
    cout << ans;
  } else if (v.size() == 2) {
    int ans = v[1] - v[0];
    if (ans % 2 == 0) {
      cout << ans / 2;
    } else {
      cout << ans;
    }
  } else {
    cout << 0;
  }
  return 0;
}
