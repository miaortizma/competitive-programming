#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    ll x, y;
    cin >> x >> y;
    if (x == 1) {
      if (y == 1)
        cout << "YES\n";
      else
        cout << "NO\n";
    } else if (x <= 3) {
        if (y <= 3)
          cout << "YES\n";
        else
          cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
  return 0;
}
