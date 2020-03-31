#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  long long u, v;
  cin >> u >> v;
  if (v < u || (v - u) % 2 != 0) {
    cout << -1;
  } else {
    long long diff = (v - u) >> 1;
    if (diff == 0) {
      if (u == 0) {
        cout << 0;
      } else {
        cout << 1 << "\n";
        cout << u;
      }
    } else {
      if (diff & u) {
        cout << 3 << "\n";
        cout << u << " " << diff << " " << diff;
      } else {
        cout << 2 << "\n";
        cout << (u ^ diff) << " " << diff;
      }
    }
  }
  return 0;
}
