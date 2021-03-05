#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

typedef long long ll;
const int N = 110;
const long double EPS = 1e-9;
int stops[N];

ll sq(ll x) {
  return x * x;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  ll n, vb, vs;
  ll x, y;
  cin >> n >> vb >> vs;
  int bstop = 1;
  ll bdist = 1e18;
  long double btime = 1e9;
  for (int i = 0; i < n; ++i) {
    cin >> stops[i];
  }
  cin >> x >> y;
  for (int i = 1; i < n; ++i) {
    ll d = sq(x - stops[i]) + sq(y);
    long double t = sqrt(d) * 1.0 / vs + stops[i] * 1.0 / vb;
    if (abs(t - btime) < EPS) {
      if (d < bdist) {
        bstop = i;
        bdist = d;
        btime = t;
      }
    } else if (t < btime) {
      bstop = i;
      bdist = d;
      btime = t;
    }
  }
  cout << bstop + 1;
  return 0;
}
