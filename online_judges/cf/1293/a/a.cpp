#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma
const int N = 2 * 1e3 + 10;
bool arr[N];

int n, s, k, tmp;

int id(int x) {
  return x - s + 1000;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> s >> k;
    memset(arr, true, sizeof arr);
    for (int i = 0; i < k; ++i) {
      cin >> tmp;
      if (abs(s - tmp) <= 1000) {
        arr[id(tmp)] = false;
      }
    }
    int ans = 1000;
    for (int i = 0; i <= 1000; ++i) {
      if ((s - i > 0 && arr[id(s - i)]) || (i + s <= n && arr[id(i + s)])) {
        ans = i;
        break;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
