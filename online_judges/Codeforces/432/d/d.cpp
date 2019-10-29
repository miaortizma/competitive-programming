#include<bits/stdc++.h>
using namespace std;


typedef pair<int, int> pii;

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  string s;
  cin >> s;
  vector<int> z = z_function(s);
  int n = z.size();
  z[0] = n;
  int count[n + 1];
  memset(count, 0, sizeof count);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ++count[z[i]];
  }
  for (int i = n - 1; i > 0; --i) {
    count[i] += count[i+1];
    if (z[i] + i == n)
      ++ans;
  }
  ++ans;
  cout << ans << '\n';
  for (int i = n - 1; i >= 0; --i) {
    if (z[i] + i == n) {
      cout << z[i] << ' ' << count[z[i]] << '\n';
    }
  }
  return 0;
}
