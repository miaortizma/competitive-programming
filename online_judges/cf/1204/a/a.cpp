#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  string s;
  cin >> s;
  bool greater = false;
  int n = s.size();
  for (int i = 1; i < n; ++i) {
    if (s[i] == '1')
      greater = true;
  }
  
  int ans = (n + 1) / 2;
  if (n & 1 && !greater)
    --ans;

  cout << ans;
  return 0;
}
