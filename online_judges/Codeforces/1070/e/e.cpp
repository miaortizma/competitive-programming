#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, t;
const int N = 2 * 1e5 + 100;

int arr[N], b = 0;

int f(int x) {
  int cur = 0;
  for (int i = 0; i < n; ++i) {

  }
  b = max(b, cur);
  return cur > 0;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m >> t;
    int mx = 0, mn = N;
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
      mx = max(mx, arr[i]);
      mn = min(mn, arr[i]);
    }
    if (mn > t) {
      cout << "0 0\n";
      continue;
    }
    int l = mn, h = mx;
    cout << f(l) << " " << l << "\n";
  }
  return 0;
}
