#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPrime(ll n) {
  if (n < 2)
    return false;
  if (n != 2 && n % 2 == 0)
    return false;
  for (ll i = 3; i * i <= n; ++i) {
    if (n % i == 0)
      return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  ll n;
  cin >> n;
  ll p = n;
  while (!isPrime(p)) {
    p--;
  }
  if (p == n) {
    cout << 1 << "\n";
    cout << n;
  } else {
    ll p2 = n - p;
    if (isPrime(p2)) {
      cout << 2 << "\n";
      cout << p << " " << n - p << "\n";
    } else {
      while (!isPrime(p2) || !isPrime(n - p - p2)) {
        p2--;
      }
      cout << 3 << "\n";
      cout << p << " " << p2 << " " << n - p - p2;
    }
  }
  return 0;
}
