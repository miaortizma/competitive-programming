#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// By Miguel Ortiz https://github.com/miaortizma

ll ans;
ll ba, bb;

vector<ll> factors(ll X) {
  vector<ll> ret;
  ll B = X;
  for (ll i = 2; i * i <= X; ++i) {
    if (B % i == 0) {
      while (B % i == 0) {
        ret.push_back(i);
        B /= i;
      }
    }
  }
  // prime
  if (ret.size() == 0) {
    return ret;
  } 
  // left prime factor
  if (B > 1) {
    ret.push_back(B);
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  ll X;
  cin >> X;
  ans = X;
  ba = 1;
  bb = X;
  factors(X);
  cout << ba << " " << bb << "\n";
  return 0;
}
