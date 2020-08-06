#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

const int N = 5 * 1e5 + 10;

int last[N], arr[N], ans[N];
int n;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  for (int i = 1; i <= n; ++i) {
    last[i] = n;
  }
  int last_cur = n, last_t;
  for (int i = n - 1; i >= 0; --i) {
    if (arr[i] > 0) {
      last[arr[i]] = i;
    } else {
      last_t = last[-arr[i]];
      if (last_t < last_cur) {
        last_cur = last_t;
      }
    }
    ans[i] = last_cur - i;
  }
  for (int i = 0 ; i < n; ++i) {
    cout << ans[i] << " ";
  }
  return 0;
}
