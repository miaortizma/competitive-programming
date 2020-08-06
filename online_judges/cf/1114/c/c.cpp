#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

ll brent(ll n, ll x0=2, ll c=1) {
    ll x = x0, g = 1, q = 1, xs, y;
    int m = 128, l = 1;
    while (g == 1) {
        y = x;
        for (int i = 1; i < l; i++) x = f(x, c, n);
        int k = 0;
        while (k < l && g == 1) {
            xs = x;
            for (int i = 0; i < m && i < l - k; i++) {
                x = f(x, c, n);
                q = mult(q, abs(y - x), n);
            }
            g = gcd(q, n);
            k += m;
        }
        l *= 2;
    }
    if (g == n) {
        do {
            xs = f(xs, c, n);
            g = gcd(abs(xs - y), n);
        } while (g == 1);
    }
    return g;
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
    if (n < 2) return false;
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

void reduce(ll &n, ll f, map<ll, ll> &factors) {
  while(n % f == 0) {
    n /= f;
    ++factors[f];
  }
}

void factorize(ll n, map<ll, ll> &factors) {
  for (int i = 0; i < 20; ++i) reduce(n, primes[i], factors);
  if (MillerRabin(n)) reduce(n, n, factors);
  while (n != 1) {
    ll f = brent(n);
    while (!MillerRabin(f)) {
      ll x0 = (rng()%(n-2))+2, c = (rng()%(n-1))+1;
      f = brent(n, x0, c);
    }  
    reduce(n, f, factors);
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  ll n, b;
  cin >> n >> b;
  map<ll, ll> factors;
  //cerr << n << ' ' << b << '\n';
  factorize(b, factors);
  map<ll, unsigned long long> count;
  long long f;
  for (const auto& [key, t] : factors) {
    //cerr << key << ' ' << t << '\n';
    f = key;
    unsigned long long p = 1, c = n / f;
    count[f] = c;
    while (c) {
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
