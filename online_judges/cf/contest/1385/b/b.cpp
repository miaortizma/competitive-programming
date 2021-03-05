#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

bool past[51];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while(t--) {
    int n, t;
    cin >> n;
    memset(past, false, sizeof past);
    for (int i = 0; i < 2 * n; ++i) {
      cin >> t;
      if (past[t] == false) {
        cout << t << " ";
        past[t] = true;
      }
    }
    cout << "\n";
  }
  return 0;
}
