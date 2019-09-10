#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
int color[N];
set<int> neighbors[N];

int main() {
  int n, m, a, b;
  scanf("%d %d", &n, &m);

  for (int i = 1; i <= n; ++i)
    scanf("%d", color + i);
  for (int i = 0; i < m; ++i) {
    scanf("%d %d", & a, & b);
    if (color[a] != color[b]) {
      neighbors[color[a]].insert(color[b]);
      neighbors[color[b]].insert(color[a]);
    }
  }
  int ans = 0, cnt = -1;
  for (int i = 1; i <= n; ++i) {
    int c = color[i];
    int nn = neighbors[c].size();
    if (nn > cnt) {
      cnt = nn;
      ans = c;
    } else if (nn == cnt && c < ans) {
      cnt = nn;
      ans = c;
    }
  }
  cout << ans << '\n';
  return 0;
}
