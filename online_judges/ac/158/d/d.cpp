#include<bits/stdc++.h>
using namespace std;

const int N = 20010;

int arr[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, ans = 0;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    ans += arr[i];
  }
  
  int lim = n / 3;
  for (int i = 2; i <= lim; ++i) {
    if (n % i == 0) {
      for (int j = 0; j < i; ++j) {
        int cur = 0;
        int elem = n / i;
        for (int k = 0; k < elem; ++k) {
          int idx = (j + k * i) % n;
          cur += arr[idx];
        }

        ans = max(ans, cur);
      }
    }
  }

  cout << ans;

  return 0;
}
