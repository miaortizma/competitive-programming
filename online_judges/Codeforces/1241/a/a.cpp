#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int q, n;
  cin >> q;

  while (q--) {
    cin >> n;
    if (n <= 2) {
      cout << 2;
    } else {
      if (n % 2 == 0) {
        cout << 0;
      } else {
        cout << 1;
      }
    }
    cout << "\n";
  }
  return 0;
}
