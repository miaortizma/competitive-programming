#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll C, HR, HB, WR, WB;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> C >> HR >> HB >> WR >> WB;
  if (HR * WB > HB * WR) {
    swap(HR, HB);
    swap(WR, WB);
  }
  ll ans = 0;
  if (WR * WR >= C || WB * WB >= C) {
    if (WR * WR >= C)
      for (ll i = 0; WR * i <= C; ++i) ans = max(ans, i * HR + (C - i * WR) / WB * HB);
    if (WB * WB >= C)
      for (ll i = 0; WB * i <= C; ++i) ans = max(ans, i * HB + (C - i * WB) / WR * HR);
  } else {
    for (ll i = 0; i < WB; ++i) ans = max(ans, i * HR + (C - i * WR) / WB * HB);
  }
  cout << ans;
  return 0;
}
