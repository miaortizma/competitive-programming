#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma
typedef long long ll;

const ll MAX_N = 100000;

vector<ll> factors;

ll countFS(ll n) {
  factors.clear();
  ll aux=n;
  for (ll i = 2; i * i <= aux; ++i) {
    while (n % i == 0) {
      factors.push_back(i);
      n /= i;
    }
  }
  if (n != 1) {
    factors.push_back(n);
  }
  ll S = 0;
  for (ll v : factors) {
    S += v;
  }
  return S;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  ll N;
  cin >> N;
  if (N == 1) {
    cout << 2 << "\n";
    cout << 1 << "\n";
    cout << 2 << " " << 1 << "\n";
  } else if (N == 2) {
    cout << "3\n";
    cout << "1 1\n";
    cout << "4 2 2\n";
  } else if (N <= 10) {
  //if (false) {
    cout << N << "\n";
    for (ll i = 0; i < N - 1; ++i) {
      cout << (i + 1) << " ";
    }
    cout << "\n";
    for (ll i = 0; i < N; ++i) {
      cout << 1 << " ";
    }
  } else {
    ll toAdd = 0;
    ll S = countFS(N);
    while (S + 1 + max(toAdd - 1, 0ll) > MAX_N) {
      N--;
      S = countFS(N);
      toAdd++;
    }
    cerr << "N: " << N << " S: " << S << " toAdd: " << toAdd << "\n";
    vector<ll> P;
    ll I = 1;
    for (ll i = 1; i < toAdd; ++i) {
      P.push_back(I++);
    }
    ll root = max(toAdd, 1ll);
    for (ll v : factors) {
      cerr << v << " ";
      P.push_back(root);
      ++I;
      for (ll i = 1; i < v; ++i) {
        P.push_back(I++);
      }
    }
    ll countNodes = S + 1 + max(toAdd - 1, 0ll);
    assert(countNodes <= MAX_N);
    if (countNodes >= MAX_N) {
      ll x = 10 / 0;
    }
    assert(P.size() + 1 >= 2);
    assert((int)(P.size() + 1) == countNodes);
    if (P.size() + 1 < 2) {
      ll x = 10 / 0;
    }
    cout << P.size() + 1 << "\n";
    for (ll p : P) {
      cout << p << " ";
    }
    cout << "\n";
    ll INF = 1e9;
    if (toAdd != 0) {
      for (ll i = 0; i < toAdd; ++i) {
        cout << factors.size() << " ";
      }
    } else {
      cout << INF << " ";
    }
    for (ll i = 0; i < S; ++i) {
      cout << 1 << " ";
    }
    cout << "\n";
  }
  return 0;
}
