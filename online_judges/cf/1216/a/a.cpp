#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  string s;
  int n;
  cin >> n >> s;
  int as = 0, bs = 0;
  int ans = 0;
  for (int i = 0; i < n; i += 2) {
    //cout << i << '\n';
    if (s[i] == 'a') {
      ++as;
    } else {
      ++bs;
    }
    if (s[i+1] == 'a') {
      ++as;
    } else {
      ++bs;
    }
    //cout << as << ' ' << bs << '\n';
    if (as < bs) {
      ++ans;
      s[i] = 'a';
      ++as;
      --bs;
    } else if (bs < as){
      ++ans;
      s[i] = 'b';
      ++bs;
      --as;
    }
  }
  cout << ans << '\n';
  cout << s;
  return 0;
}
