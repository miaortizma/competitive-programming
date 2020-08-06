#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  ll n, nn;
  cin >> n;
  nn = n;
  map<ll, ll> factors;
  for (ll i = 2; i * i <= nn; ++i) {
    if (i > n)
      break;
    if (n % i == 0) {
      while (n % i == 0) {
        factors[i]++;
        n /= i;
      }
    }
  }
  if (n != 1)
    factors[n]++;
  if (factors.size() == 1) {
    ll factor = (*factors.begin()).first;
    cout << factor;
  } else {
    cout << 1;
  }
  return 0;
}
