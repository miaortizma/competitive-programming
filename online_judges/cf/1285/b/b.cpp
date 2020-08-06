#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma
typedef long long ll;
const int N = 1e5 + 10;
int arr[N];
int n;

ll kadane(int l, int r) {
  ll ans = 0, cur = 0;
  for (int i = l; i <= r; ++i) {
    cur += arr[i];
    cur = max(0ll, cur);
    ans = max(ans, cur);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    ll S = 0;
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
      S += arr[i];
    }
    ll B = max(kadane(0, n - 2), kadane(1, n - 1));
    if (S > B) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
