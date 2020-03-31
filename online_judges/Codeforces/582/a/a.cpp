#include<bits/stdc++.h>
using namespace std;
int n, tmp;
int main() {
  ios_base::sync_with_stdio(0);cin.tie(NULL);
  cin >> n;
  multiset<int> st;
  for (int i = 0; i < n * n; ++i) {
    cin >> tmp;
    st.insert(-tmp);
  }
  vector<int> arr;
  for (int i = 0; i < n - 1; ++i) {
    int a = *st.begin();
    for (int v : arr) {
      int g = __gcd(-a, v);
      st.erase(st.lower_bound(-g));
      st.erase(st.lower_bound(-g));
    }
    st.erase(st.lower_bound(a));
    arr.push_back(-a);

  }
  for (int v : arr)
    cout << v << " ";
  cout << -(*st.begin());
  return 0;
}
