#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n;
  cin >> n;
  if (n & 1) {
    cout << (n + 1) / 2 << "\n";
    for (int i = 1; i <= n; i += 2) {
      cout << i << " ";
    }
  } else {
    cout << n / 2 + 1 << "\n";
    for (int i = 1; i <= n - 1; i += 2) {
      cout << i << " ";
    }
    cout << n;
  }
  return 0;
}
