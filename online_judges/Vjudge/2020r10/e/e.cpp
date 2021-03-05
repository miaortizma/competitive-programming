#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int co = 0, cz = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'z') {
      cz++;
    } else if (s[i] == 'n'){
      co++;
    }
  }
  for (int i = 0; i < co; ++i) {
    cout << 1 << " ";
  }
  for (int i = 0; i < cz; ++i) {
    cout << 0 << " ";
  }
  return 0;
}
