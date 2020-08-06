#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, t;
  cin >> n;
  pii arr[n];
  for (int i = 0; i < n; ++i) {
    cin >> t;
    arr[i] = pii({t, i});
  }
  sort(arr, arr + n);
  vector<int> order;
  long long ans = 0;
  for (int i = n - 1; i >= 0; --i) {
    ans += arr[i].first * 1LL * (n - 1 - i) + 1;
  }
  cout << ans << '\n';
  for (int i = n - 1; i >= 0; --i) {
    cout << arr[i].second  + 1<< ' ';
  }
  cout << '\n';
  return 0;
}
