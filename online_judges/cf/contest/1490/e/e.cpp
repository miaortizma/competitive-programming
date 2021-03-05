#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

const int MAXN = 2 * 1e5;
typedef pair<int, int> pii;
typedef long long ll;
pii arr[MAXN];
bool ok[MAXN];
ll pre[MAXN];


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      int temp;
      cin >> temp;
      arr[i] = {temp, i};
      ok[i] = false;
    }
    sort(arr, arr + n);
    pre[0] = arr[0].first;
    for (int i = 1; i < n; ++i) {
      pre[i] = arr[i].first + pre[i - 1];
    }

    int last = arr[n - 1].first;
    int count = 1;
    ok[arr[n - 1].second] = true;

    for (int i = n - 2; i >= 0; --i) {
      if (pre[i] >= last) {
        count++;
        ok[arr[i].second] = true;
        last = arr[i].first;
      }
    }

    cout << count << "\n";
    for (int i = 0; i < n; ++i) {
      if (ok[i]) {
        cout << i + 1 << " ";
      }
    }
    cout << "\n";
  }
  return 0;
}
