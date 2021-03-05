#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  int q;
  while (k--) {
    cin >> q;
    int l = 0, h = n - 1;
    while (l < h) {
      int m = (l + h) / 2;
      if (arr[m] < q) {
        l = m + 1;
      } else {
        h = m;
      }
    }
    if (arr[l] < q) {
      cout << n + 1;
    } else {
      cout << l + 1;
    }
    cout << "\n";
  }
  return 0;
}
