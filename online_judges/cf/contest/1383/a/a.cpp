#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

#define F first
#define S second
typedef pair<int, int> pi;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while(t--) {
    int n;
    string a, b;
    cin >> n >> a >> b;
    bool ok = true, eq = true;
    for (int i = 0; i < n; ++i) {
      if (a[i] != b[i]) eq = false;
      if (a[i] > b[i]) ok = false;
    }
    if (!ok) {
      cout << -1 << "\n";
    } else if (eq) {
      cout << 0 << "\n";
    } else {
      set<pi> mp;
      for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
          pi pa{a[i], b[i]};
          mp.insert(pa);
        }
      }
      int ans = 0;
      while (!mp.empty()) {
        pi pa = *mp.begin();
        int from = pa.F, to = pa.S;
        ans++;
        // move to the correct one
        mp.erase(mp.begin());
        // take some for free
        while (!mp.empty()) {
          pi freeloader = *mp.begin();
          if (freeloader.F == from) {
            pa = {to, freeloader.S};
            mp.insert(pa);
            mp.erase(mp.begin());
          } else {
            break;
          }
        }
      }
      cout << ans << "\n";
    }
  }
  return 0;
}
