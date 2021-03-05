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
      if (arr[m] >= q) {
        h = m;
      } else {
        l = m + 1;
      }
    }
    if (arr[l] == q) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
