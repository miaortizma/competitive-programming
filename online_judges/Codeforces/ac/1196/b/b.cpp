#include<bits/stdc++.h>
using namespace std;

int main() {
  int q;
  cin >> q;
  while (q--) {
    int n, k, t;
    cin >> n >> k;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
      cin >> t;
      if (t&1)
        v.push_back(i + 1);
    }
    int nn = v.size();
    if (nn >= k && (k & 1) == (nn & 1) ) {
      cout << "YES\n";
      for (int i = nn - k; i < nn - 1; ++i) {
        cout << v[i] << ' ';
      }
      cout << n << '\n';
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}