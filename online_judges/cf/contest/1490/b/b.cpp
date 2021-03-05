#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

const int N = 3 * 1e4;
//int arr[N];
int arr[3];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, t;
    cin >> n;
    int goal = n / 3;
    for (int i = 0; i < n; ++i) {
      int t;
      cin >> t;
      arr[t % 3]++;
    }
    int ans = 0;
    /*
    for (int i = 0; i < 3; ++i) {
      cerr << arr[i] << " ";
    }
    cerr << "\n";
    */
    for (int i = 0; i < 6; ++i) {
      if (arr[i % 3] > goal) {
        ans += arr[i % 3] - goal;
        arr[(i + 1) % 3] += arr[i % 3] - goal;
        arr[i % 3] = goal;
      }
      for (int i = 0; i < 3; ++i) {
        //cerr << arr[i] << " ";
      }
      //cerr << "\n";
    }
    for (int i = 0; i < 3; ++i) {
      arr[i] = 0;
    }

    cout << ans << "\n";
  }
  return 0;
}
