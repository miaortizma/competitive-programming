#include<bits/stdc++.h>
using namespace std;

int k;
string s;

int main() {
  
  cin >> k >> s;

  int l = -1;
  int zeros = 0;
  int c = 0, n = s.size();
  long long ans = 0;
  
  // cout << "i\tc\tzeros\tans\n";

  for (int i = 0; i < n; ++i) {
    c += s[i] == '1' ? 1 : 0;
    
    if (c > k) {
      zeros = 0;
      while (l + 1 < i && c > k) {
        ++ l;
        c += s[l] == '1' ? -1 : 0;
      }
    }
        
    if (c == k) {
      while (l + 1 < i && s[l + 1] == '0') {
        ++ l;
        ++ zeros;
      }
      ans += zeros + 1;
    }

    // cout << i << '\t' << c << '\t' << zeros << '\t' << ans << '\n';
  }

  cout << ans;
  return 0;
}
