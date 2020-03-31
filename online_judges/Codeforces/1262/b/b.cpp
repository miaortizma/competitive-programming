#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 100;
int arr[N];
bool used[N], lss[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    memset(lss, false, sizeof lss);
    memset(used, false, sizeof used);
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
      if (i > 0 && arr[i - 1] == arr[i]) {
        lss[i] = true;
      } else {
        used[arr[i]] = true;
      }
    }
    int I = 1;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      if (!lss[i])
        continue;
      while (used[I]) {
        I++;
      }
      if (I < arr[i]) {
        arr[i] = I;
        used[I] = true;
      } else {
        ok = false;
      }
    }
    if (ok) {
      for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
      }
    } else {
      cout << -1;
    }
    cout << "\n";
  }
  return 0;
}
