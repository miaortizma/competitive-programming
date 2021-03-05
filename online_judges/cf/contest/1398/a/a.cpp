#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

const int N = 5 * 1e4 + 10;
int arr[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
     cin >> n;
     for (int i = 0; i < n; ++i) {
       cin >> arr[i];
     }
     if (arr[0] + arr[1] <= arr[n - 1]) {
       cout << "1 2 " << n << "\n";
     } else {
       cout << -1 << "\n";
     }

  }
  return 0;
}
