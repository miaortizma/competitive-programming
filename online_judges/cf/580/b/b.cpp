#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma
//
typedef long long ll;
typedef pair<ll, ll> pll;
const int N = 1e5 + 10;
ll pre[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  ll n, d, m, s;
  cin >> n >> d;
  vector<pll> v;
  for (int i = 0; i < n; ++i) {
    cin >> m >> s;
    v.push_back({m, s});
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; ++i) {
    pre[i] = v[i].second;
  }
  for (int i = 0; i < n - 1; ++i) {
    pre[i + 1] += pre[i];
  }
  ll ans = 0;
  int l = 0, r = 0;
  while (r < n) {
    while (v[r].first >= v[l].first + d) {
      l++;
    }
    //cerr << l << " " << r << "\n";
    ll sr = pre[r], sl = (l - 1) >= 0 ? pre[l - 1] : 0;
    //cerr << sr << " " << sl << "\n";
    ans = max(ans, sr - sl);
    r++;
  }
  cout << ans << "\n";
  return 0;
}
