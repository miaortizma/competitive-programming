#include<bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(NULL);
  int n;
  cin >> n;
  int arr[2 * n];
  for (int i = 0; i < 2 * n; ++i) {
    cin >> arr[i];
  }
  sort(arr, arr + 2 * n);
  int ans = 0;
  for (int i = 2 * n - 1; i > 0; i -= 2) {
    ans += min(arr[i], arr[i - 1]);
  }
  cout << ans << '\n';
  return 0;
}

