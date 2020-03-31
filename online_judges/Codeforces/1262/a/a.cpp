#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int a = 1e9 + 100, b = -1, l, r;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> l >> r;
      a = min(a, r);
      b = max(b, l);
    }
    cout << max(0, b - a) << "\n";
  }
  return 0;
}
