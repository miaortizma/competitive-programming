#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

#define PB push_back
#define F first
#define S second
const int N = 1e5 + 10;
int arr[N], cnt[N], ord[N], last[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }
    sort(arr, arr + n);
    int la = -1;
    vector<int> ve;
    for (int i = 0; i < n; ++i) {
      if (arr[i] != la) {
        ve.PB(1);
        la = arr[i];
      } else {
        ve[ve.size() - 1] += 1;
      }
    }
    sort(ve.rbegin(), ve.rend());
    int maxVe = ve[0];
    int c = 0;
    while (ve[c] == maxVe) {
      c++;
    }
    int ans = max(0, n - (c - 1) - maxVe) / (maxVe - 1);
    cout << ans << "\n";
  }
  return 0;
}
