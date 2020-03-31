#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2 * 1e5 + 100;
ll s[N];
ll arr[N], ans[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  s[0] = arr[0];
  ans[0] = s[0];
  for (int i = 1; i < n; ++i) {
    s[i % m] += arr[i];
    ans[i] = ans[i - 1] + s[i % m];
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  return 0;
}
