#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, tmp;
    cin >> n;
    set<int> st;
    for (int i = 0; i < n; ++i) {
      cin >> tmp;
      st.insert(tmp);
    }
    cout << st.size() << "\n";
  }
  return 0;
}
