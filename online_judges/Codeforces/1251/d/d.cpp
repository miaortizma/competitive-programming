#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const int N = 2 * 1e5 + 100;
int n;
ll s;
pii arr[N];

bool can(ll median) {
  int c = 0;
  ll ss = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (c <= n / 2 && arr[i].second >= median) {
      ss += max(arr[i].first, median);
      ++c;
    } else {
      ss += arr[i].first;
    }
  }
  return c * 2 > n && ss <= s;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int T, a, b;
  cin >> T;
  while (T--) {
    cin >> n >> s;
    int l = 0, h = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a >> b;
      arr[i] = {a, b};
      h = max(h, b);
    }
    sort(arr, arr + n);
    l = arr[n / 2].first;
    while (l < h) {
      int m = l + (h - l + 1) / 2;
      if (can(m))
        l = m;
      else
        h = m - 1;
    }
    cout << l << "\n";
  }
  return 0;
}
