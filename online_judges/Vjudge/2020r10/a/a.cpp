#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while(t--) {
    int a, b;
    cin >> a >> b;
    if (a == b) {
      cout << 0 << "\n";
    } else if(a > b) {
      if (a % 2 == b % 2) {
        cout << 1 << "\n";
      } else {
        cout << 2 << "\n";
      }
    } else {
      if (a % 2 == b % 2) {
        cout << 2 << "\n";
      } else {
        cout << 1 << "\n";
      }
    }
  }
  return 0;
}
