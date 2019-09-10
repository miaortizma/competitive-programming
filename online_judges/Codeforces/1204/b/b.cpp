#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, l, r;
  cin >> n >> l >> r;
  int ans_min = 0;
  for (int i = 0; i < l; ++i)
    ans_min += 1 << i;
  ans_min += n - l;
  long long ans_max = 0;
  for (int i = 0; i < r; ++i)
    ans_max += 1 << i;
  ans_max += (n - r) * (1 << (r - 1));
  cout << ans_min << ' ' << ans_max;
  return 0;
}
