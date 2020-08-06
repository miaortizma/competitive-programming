#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma
//
typedef long long ll;

const int N = 2 * 1e5 + 100;
ll A[N], B[N], C[N], D[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  ll n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> B[i];
    C[i] = A[i] - B[i];
    D[i] = B[i] - A[i];
  }
  sort(C, C + n);
  sort(D, D + n);
  ll s = 0;
  for (int i = 0; i < n; ++i) {
    ll v = C[i];
    ll l = 0, h = n - 1;
    while (l < h) {
      ll m = l + (h - l + 1) / 2;
      if (D[m] >= v) {
        h = m - 1;
      } else {
        l = m;
      }
    }
    if (D[l] < v) {
      if (v > 0) l--;
      s += l + 1;
    }
  }
  ll ans = s / 2;
  cout << ans << "\n";
  return 0;
}
