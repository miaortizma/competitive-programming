#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

int mod = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n;
  cin >> n;
  int fact = 1, pow = 1;
  for (int i = 1; i <= n; ++i) {
    fact = (fact * 1ll *  i) % mod;
  }
  for (int i = 1; i < n; ++i) {
    pow = (pow * 1ll * 2) % mod;
  }
  int ans = (fact - pow + mod) % mod;
  cout << ans;
  return 0;
}
