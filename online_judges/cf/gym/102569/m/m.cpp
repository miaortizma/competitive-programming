#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

typedef long long ll;
typedef pair<ll, ll> pl;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, a, b;
  cin >> n;
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a >> b;
    if (a > ans) {
      ans = a + b;
    } else {
      ans += b;
    }
  }
  cout << ans;
  return 0;
}
