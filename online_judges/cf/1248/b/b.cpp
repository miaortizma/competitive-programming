#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  ll a = 0, b = 0;
  for (int i = 0; i < n; ++i) {
    if (i < n / 2)
      a += arr[i];
    else
      b += arr[i];
  }
  ll ans = a * a + b * b;
  cout << ans;
  return 0;
}
