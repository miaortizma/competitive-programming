#include<bits/stdc++.h>
using namespace std;
constexpr int MAXN = 5 + 1000*1000;

pair<int,int> p[MAXN];
int d[MAXN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int r,s,n; cin >> r >> s >> n;
  for (int i = 0; i < n; ++i) {
    cin >> p[i].first >> p[i].second;
  }
  for (int i = 0; i < n; ++i) {
    d[i] = 1 + r - p[i].first;
    if (p[i].second <= s) {
      d[i] += 1 + abs(s - p[i].second);
    } else {
      d[i] += 1 + abs(s + 1 - p[i].second);
    }
  }
  sort(d, d + n);
  reverse(d, d + n);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans = max(ans, i + d[i]);
  }
  cout << ans << '\n';
  return 0;
}
