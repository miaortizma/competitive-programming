#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

typedef long long ll;

map<ll, ll> factorize(ll n) {
  ll c = n;
  map<ll, ll> f;
  while (n % 2 == 0) {
    f[2]++;
    n >>= 1;
  }
  for (ll i = 3; i * i <= c; i += 2) {
    if (i > n) break;
    while (n % i == 0) {
      n /= i;
      f[i]++;
    }
  }
  if (n != 1) {
    f[n]++;
  }
  return f;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    ll x;
    cin >> x;
    map<ll, ll> f = factorize(x);
    vector<ll> v;

    //cout << x << "\n";
    for (auto const& [k, m] : f) {
      //cout << k << " " << m << "\n";
      v.push_back(k);
    }
    ll a = 0, b = 0, c = 0;
    if (f.size() >= 2) {
      a = v[0];
      b = v[1];
      c = x / (a * b);
    } else if (f.size() == 1) {
      if (f[v[0]] >= 6) {
        a = v[0];
        b = v[0] * v[0];
        c = x / (a * b);
      } 
    }
    if (a != b && a != c && b != c && a >= 2 && b >= 2 && c >= 2) {
      cout << "YES\n";
      cout << a << " " << b << " " << c << "\n"; 
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
