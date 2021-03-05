#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<ll> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  sort(v.rbegin(), v.rend());
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    ll cur = i + 1;
    if (v[i] > cur) {
      ans += v[i] - cur;
    }
  }
  cout << ans << "\n";
  return 0;
}
