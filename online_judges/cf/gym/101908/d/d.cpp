#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    if (t != 1) {
      ans += 1;
    }
  }
  cout << ans;
  return 0;
}
