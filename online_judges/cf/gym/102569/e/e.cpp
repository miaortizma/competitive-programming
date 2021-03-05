#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

typedef long long ll;

bool can(vector<ll> v, ll m) {
  int n = v.size();
  for (int i = 0; i < n; ++i) { 
    m += v[i];
    if (m < 0) {
      return false;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<ll> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  ll l = 0, h = 500000 * 1e9 + 100;
  auto ccan = [v](ll m) {
    return can(v, m);
  };
  while (l < h) {
    ll m = l + (h - l) / 2;
    if (ccan(m)) {
      h = m;
    } else {
      l = m + 1;
    }
  }
  cout << l << "\n";
  return 0;
}
