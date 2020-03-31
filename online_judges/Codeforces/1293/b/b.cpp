#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout << fixed << setprecision(12);
  int n;
  cin >> n;
  double ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += 1.0 / i;
  }
  cout << ans << "\n";
  return 0;
}
