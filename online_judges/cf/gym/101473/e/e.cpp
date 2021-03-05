#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

const int N = 1e4 + 10;
bool returned[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, r;
  cin >> n >> r;
  for (int i = 0; i < r; ++i) {
    int t;
    cin >> t;
    returned[t] = true;
  }
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (!returned[i]) {
      cout << i << " ";
      cnt += 1;
    }
  }
  if (cnt == 0) {
    cout << "*";
  }
  return 0;
}
