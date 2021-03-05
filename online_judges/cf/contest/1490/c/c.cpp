#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

typedef long long ll;
const int N = 1e4 + 10;
ll cube[N];
unordered_set<ll> cubes;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;

  for (int i = 1; i < N; ++i) {
    cube[i] = i * 1LL * i * i;
    cubes.insert(cube[i]);
  }

  while(t--) {
    ll x;
    bool ok = false;
    cin >> x;

    for (int i = 1 ; i < 1e4; ++i) {
      ll rest = x - cube[i];
      if (cubes.count(rest)) {
        ok = true;
        break;
      }
    }
    if (ok) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
