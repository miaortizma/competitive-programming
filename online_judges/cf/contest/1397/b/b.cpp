#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

#define all(v) v.begin(), v.end()
typedef long long ll;
ll OO = 1e18;

bool isOverflow(ll a, ll b) {
  if (a == 0 || b == 0) {
    return false;
  }
  __int128 result = a * b;
  if (a == result / b) {
    return false;
  } else {
    return true;
  }
}

ll cost(vector<ll> &v, ll m) {
  ll cur = 1;
  ll ret = 0;
  for (size_t i = 0; i < v.size(); ++i) {
    ret += abs(cur - v[i]);
    if (isOverflow(cur, m)) {
      return OO;
    }
    cur *= m;
  }
  return ret;
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
  sort(all(v));
  auto fcost = [&v](ll m) {
    return cost(v, m);
  };
  ll lo = 2, hi = 1e9;
  while (lo < hi) {
    ll m = lo + (hi - lo + 1) / 2;
    cout << lo << " " << hi << "\n";
    if (fcost(m + 1) - fcost(m) < 0) {
      lo = m;
    } else {
      hi = m - 1;
    }
  }
  cout << lo << " " << fcost(lo) << " " << fcost(lo + 1) << "\n";
  cout << 1 << " " << fcost(1) << "\n";
  cout << min(fcost(1), min(fcost(lo), fcost(lo + 1)));
  return 0;
}
