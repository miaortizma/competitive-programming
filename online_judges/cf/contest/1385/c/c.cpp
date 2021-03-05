#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

const int N = 2 * 1e5 + 10;
int arr[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> arr[i];
    int i = n, r = 0, l = 0;
    while(i > 0 && arr[i] >= arr[i + 1]) {
      i -= 1;
      r += 1;
    }
    while(i > 0 && arr[i] <= arr[i + 1]) {
      i -= 1;
      l += 1;
    }
    cout << n - (r + l) << "\n";


  }
  return 0;
}
