#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int v[3], n;
    cin >> v[0] >> v[1] >> v[2] >> n;
    sort(v, v + 3);
    int need = v[2] - v[0] + v[2] - v[1];
    //cerr << need << "\n";
    if (need <= n) {
      v[0] = v[1] = v[2];
      n -= need;
    }
    if (n % 3 == 0 && v[0] == v[1] && v[0] == v[2]) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
