#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// By Miguel Ortiz https://github.com/miaortizma

ll ans;
ll ba, bb;

ll lcm(ll x, ll y) {
  return x / __gcd(x, y) * y;
}

void factors(ll X) {
  for (ll i = 2; i * i <= X; ++i) {
    if (X % i == 0) {
      ll A = i, B = X / A;
      if (lcm(A, B) == X) {
        if (max(A, B) < ans) {
          ans = bb = max(A, B);
          ba = min(A, B);
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  ll X;
  cin >> X;
  ans = bb = X;
  ba = 1;
  factors(X);
  cout << ba << " " << bb << "\n";
  return 0;
}
