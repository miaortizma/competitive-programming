#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int arr[3];
    for (int i = 0; i < 3; ++i) {
      cin >> arr[i];
    }
    sort(arr, arr + 3);
    if (arr[1] == arr[2]) {
      cout << "YES\n";
      cout << arr[0] << " " << arr[0] << " " << arr[1] << "\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
