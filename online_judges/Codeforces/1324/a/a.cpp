#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int s = 0, tmp;
    for (int i = 0; i < n; ++i) {
      cin >> tmp;
      s += tmp % 2;
    }
    if (s != 0 && s != n) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
  return 0;
}
