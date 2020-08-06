#include<bits/stdc++.h>
using namespace std;

void pprint(int x, int y) {
  cout << x << ' ' << y << '\n';
}

int main() {
  int q;
  cin >> q;
  while (q--) {
    int b, w, x, y;
    cin >> b >> w;
    int n = min(b, w), m = max(b, w);
    if (n * 3 + 1 < m) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      if (n == b) {
        x = 2;
        y = 3;
      } else {
        x = y = 2;
      }
      //pprint(x, y);
      //cout << "@@@@\n";
      for (int i = 0; i < n; ++i) {
        pprint(x + 2 * i, y);
        pprint(x + 2 * i + 1, y);
      }
      
      if (m - n)
        pprint(x - 1, y);
 
      for (int i = 0, j = 0; j < m - n - 1; ++i, ++j) {
        pprint(x + 2 * i, y - 1);
        ++j;
        if (j == m - n - 1)
            break;

        pprint(x + 2 * i, y + 1);
      }

    }
  }
  return 0;
}
