#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n / 2);
    vector<int> b(n / 2);
    for (int i = 0; i < n / 2; ++i) {
      cin >> a[i];
    }
    for (int i = 0; i < n / 2; ++i) {
      cin >> b[n / 2 - 1 - i];
    }

    int l = 2, r = k * 2;
    vector<int> counts(k * 2 + 1);
    vector<int> pre(k * 2 + 2);
    for (int i = 0; i < n / 2; ++i) {
      int ai = a[i];
      int bi = b[i];
      int xi = ai + bi;
      counts[xi]++;

      if (ai > bi) swap(ai, bi);

      pre[ai + 1]++;
      pre[bi + k + 1]--;
    }

    for (int i = 2; i <= k * 2; ++i) {
      pre[i] += pre[i - 1];
    }

    int ans = n;
    for (int i = 2; i <= k * 2; ++i) {
      int c = counts[i];
      int ones = pre[i] - c;
      int twos = n / 2 - pre[i];
      ans = min(ans, ones + 2 * twos);
    }
    cout << ans << "\n";
  }
  return 0;
}
