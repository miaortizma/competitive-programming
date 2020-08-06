#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, x, a, b;
    cin >> n >> x >> a >> b;
    int ans = max(abs(a - b), min(n - 1, abs(a - b) + x));
    cout << ans << "\n";
  }
  return 0;
}
