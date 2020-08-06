#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma
//
const int N = 4 * 1e5 + 10;
int cnt[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int q, x;
  cin >> q >> x;
  int MEX = 0;
  for (int i = 0; i < q; ++i) {
    int v;
    cin >> v;
    cnt[v % x]++;
    while (cnt[MEX % x] >= MEX / x + 1) {
      MEX++;
    }
    cout << MEX << "\n";
  }
  return 0;
}
