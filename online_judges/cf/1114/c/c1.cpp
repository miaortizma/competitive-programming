#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};

ll mult(ll a, ll b, ll mod) { 
    ll res = 0;
    while (b > 0) { 
        if (b & 1) 
            res = (res + a) % mod; 
        a = (a + a) % mod; 
        b >>= 1; 
    } 
    return res; 
} 

ll f(ll x, ll c, ll mod) {
  return (mult(x, x, mod) + c) % mod;
}

ll pollard_rho(ll n, ll c) {
  ll x = 2, y = 2, i = 1, k = 2, d;
  while (true) {
    x = (mult(x, x, n) + c);
    if (x >= n)	x -= n;
    d = __gcd(x - y, n);
    if (d > 1) return d;
    if (++i == k) y = x, k <<= 1;
  }
  return n;
}

ll binpower(ll base, ll e, ll mod) {
    ll result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = mult(result, base, mod);
        base = mult(base, base, mod);
        e >>= 1;
    }
    return result;
}

void factorize(ll n, vector<ll> &f) {
  if (n == 1) return;
  if (is_prime(n)) {
    f.push_back(n);
    return;
  }
  ll d = n;
  for (int i = 2; d == n; i++)
    d = pollard_rho(n, i);
  factorize(d, f);
  factorize(n/d, f);
}

bool check_composite(ll n, ll a, ll d, int s) {
    ll x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = mult(x, x, n);
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(ll n) { // returns true if n is prime, else returns false.
    if (n < 2)
        return false;

    int r = 0;
    ll d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}

map<ll, ll> factorize(ll n) {
  srand (time(NULL));
  map<ll, ll> factors;
  for (int i = 0; i < 20; ++i) {
    while (n % primes[i] == 0) {
      ll f = primes[i];
      n /= primes[i];
      ++factors[primes[i]];
    }  
  }
  if (MillerRabin(n)) {
    ++factors[n];
    n = 1;
  }
  while (n != 1) {
    ll f = pollard_rho(n);
    bool prime = MillerRabin(f);
    if (!prime) {
      map<ll, ll> others = factorize(f);
      for (const auto& [key, value] : others)
        factors[key] += value;
      n /= f;
      continue;
    }
    while (n % f == 0) {
      n /= f;
      ++factors[f];
    }
  }
  return factors;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  ll n, b;
  cin >> n >> b;
  //cerr << n << ' ' << b << '\n';
  map<ll, ll> factors = factorize(b);
  map<ll, unsigned long long> count;
  long long f;
  for (const auto& [key, t] : factors) {
    //cout << key << ' ' << t << '\n';
    f = key;
    unsigned long long p = 1, c = n / f;
    count[f] = c;
    while (c) {
      //cout << count[f] << '\n';
      c /= f;
      count[f] += c;
    }
    count[f] = count[f] / t;
  }
  
  unsigned long long ans = count[f];
  for (const auto& [key, value] : count) {
    ans = min(ans, value);
  }

  cout << ans;
  
  return 0;
}
