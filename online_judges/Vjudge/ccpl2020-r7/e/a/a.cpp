#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma
typedef long long ll;
typedef vector<ll> vi;
#define PB push_back
#define F first
#define S second

__int128 gcd(__int128 a, __int128 b) {
  while (a && b) a > b ? a %= b : b %= a;
  return a + b;
}

__int128 lcm(__int128 a, __int128 b) {
  return (a / gcd(a, b)) * b;
}

vector<int> getPrimes(ll N) {
  vector<int> primes;
  vector<bool> isPrime(int(sqrt(N)) / 2 + 10, true);
  primes.PB(2);
  for (ll i = 3; i * i <= N; i += 2) {
    ll iid = i / 2 - 1;
    if (isPrime[iid]) {
      primes.PB(i);
      ll j = 3 * i;
      while (j * j <= N) {
        ll jid = j / 2 - 1;
        isPrime[jid] = false;
        j += 2 * i;
      }
    }
  }
  return primes;
}

vector<vi> fib_mat{{0, 1}, {1, 1}};
__int128 temp[2][2];

vector<vi> mult(vector<vi> A, vector<vi> B, ll mod) {
  vector<vi> ret = A;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      temp[i][j] = 0;
    }
  }
  __int128 one = 1;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k < 2; ++k) {
        temp[i][j] = (temp[i][j] + (A[i][k] * one * B[k][j]));
      }
      ret[i][j] = temp[i][j] % mod;
    }
  }
  return ret;
}

vector<ll> fastFib(ll N, ll m) {
  if (N == 0) {
    return {0, 0};
  }
  if (N == 1) {
    return {0, 1};
  }
  vector<vi> mat = fib_mat;
  vector<vi> I{{1, 0}, {0, 1}};
  N -= 1;
  while (N) {
    if (N & 1) {
      I = mult(I, mat, m);
    }
    mat = mult(mat, mat, m);
    N >>= 1;
  }
  return {I[1][0], I[1][1]};
}

ll NN = 1e12;
vector<int> primes = getPrimes(NN);

vector<pair<ll, ll>> factorize(ll N) {
  vector<pair<ll, ll>> factorization;
  for (auto p : primes) {
    if (p * p > N) {
      break;
    }
    if (N % p == 0) {
      N /= p;
      pair<ll, ll> pa{p, 1};
      while (N % p == 0) {
        pa.S += 1;
        N /= p;
      }
      factorization.PB(pa);
    }
  }
  if (N != 1) {
    factorization.PB({N, 1});
  }
  return factorization;
}


ll isPrimePeriod(ll p, ll r) {
  vector<ll> v = fastFib(r, p);
  ll a = v[0];
  ll b = v[1];
  return a == 1 && b == 0;
}

unordered_map<ll, ll> primePeriod;
ll getPrimePeriod(ll p) {
  if (p == 2) return 3;
  if (p == 5) return 20;
  if (primePeriod.count(p)) {
    return primePeriod[p];
  }

  vector<pair<ll, ll>> factorization;
  ll X;

  if (p % 10 == 1 || p % 10 == 9) {
    factorization = factorize(p - 1);
    X = p - 1;
  } else {
    factorization = factorize(2 * (p + 1));
    X = 2 * (p + 1);
  }
  for (auto pa : factorization) {
    //cout << pa.F << " " << pa.S << "\n";
    //cout << isPrimePeriod(p, X / pa.F) << "\n";

    //vi vv = fastFib(X / pa.F, p);
    //cout << vv[0] << " " << vv[1] << "\n";

    while (X % pa.F == 0 && isPrimePeriod(p, X / pa.F)) {
      X /= pa.F;
    }
  }
  primePeriod[p] = X;
  return X;
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  ll T, M;
  cin >> T;
  /*
  for (int i = 1; i <= 25; ++i) {
    vi vv = fastFib(i, 1000000);
    cout << vv[0] << " " << vv[1] << "\n";
  }
  cout << "\n";
  for (int i = 1; i <= 100; ++i) {
    cout << primes[i] << "\n";
  }
  */

  while (T--) {
  //for (int j = 1; j <= (int) 300; ++j) {
    cin >> M;
    //M = j;
    if (M == 1) {
      cout << 1 << "\n";
      continue;
    }
    vector<pair<ll, ll>> factorization = factorize(M);
    vector<__int128> periods(factorization.size());
    __int128 res = 1;
    for (auto pa : factorization) {
      __int128 cur = getPrimePeriod(pa.F);
      for (int j = 1; j < pa.S; ++j) {
        cur *= pa.F;
      }
      res = lcm(res, cur);
    }
    //cout << M << " " << periods[0] << "\n";
    vector<int> digits;
    while (res) {
      digits.PB(res % 10);
      res /= 10;
    }
    //cout << M << " ";
    reverse(digits.begin(), digits.end());
    for (auto x : digits) {
      cout << x;
    }
    cout << "\n";
  }
  return 0;
}
