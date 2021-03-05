#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

vector<int> d, coord;
map<int, bool> ok;


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n;
  cin >> n;
  d.resize(n);
  coord.resize(n);
  int s = 0;
  for (int i = 0; i < n; ++i) {
    cin >> d[i];
    coord[i] = s;
    ok[coord[i]] = true;
    s += d[i];
  }
  if (s % 3 != 0) {
    cout << 0;
    return 0;
  }
  int r = s / 3;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int cur = coord[i];
    if (ok[(cur + r) % s] && ok[(cur + r * 2) % s]) {
      //cout << cur << " " <<  ((cur + r) % s) << " " << ((cur + r * 2) % s) << "\n";
      ans += 1;
    }
  }
  cout << ans / 3 << "\n";
  return 0;
}
