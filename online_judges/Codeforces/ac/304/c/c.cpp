#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n;
  cin >> n;
  if (n % 2 == 0) {
    cout << -1;
  } else {
    for (int i = 0; i < n; ++i)
      cout << i << ' ';
    cout << '\n';
    for (int i = 0; i < n; ++i)
      cout << i << ' ';
    cout << '\n';
    for (int i = 0; i < n; ++i)
      cout << (2 * i % n) << ' ';
  }
  return 0;
}
