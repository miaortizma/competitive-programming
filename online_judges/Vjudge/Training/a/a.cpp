#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  string s;
  int zeros = 0, ones = 0, n;
  cin >> n >> s;
  for (int i = 0; i < n; ++i)
    if (s[i] == '0')
      zeros++;
  ones = n - zeros;
  if (ones)
    cout << 1;
  for (int i = 0; i < zeros; ++i)
    cout << 0;
  return 0;
}
