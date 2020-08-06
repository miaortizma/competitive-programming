#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma
//

const int N = 1e5 + 10;
int blockades = 0;

bool lava[2][N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, q, r, c;
  cin >> n >> q;
  for (int i = 0; i < q; ++i) {
    cin >> r >> c;
    //cerr << "OK\n";
    //cerr << r << " " << c << "\n";
    lava[r - 1][c] = !lava[r - 1][c];
    bool l = lava[r - 1][c];
    /*
     * if (i == 1) {
      cerr << l << "\n";
    }
    */
    int dy[] = {-1, 0, +1};
    for (int j = 0; j < 3; ++j) {
      int x = (r == 1) ? 1 : 0, y = c + dy[j];
      if (y <= 0 || y > n) continue;
      //cerr << x << " " << y << "\n";
      if (l && lava[x][y]) {
        ++blockades;
      } else if (!l && lava[x][y]) {
        --blockades;
      }
    }
    if (blockades > 0) {
      cout << "No\n";
    } else {
      cout << "Yes\n";
    }
  }
  return 0;
}
