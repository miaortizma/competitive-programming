#include<bits/stdc++.h>
using namespace std;

void no(){
  cout << "Just a legend\n";
  exit(0);
}

void password(string s) {
  int n = s.size();
  if (n < 3)
    no();

  const int p = 31;
  const int m = 1e9 + 9;
  
  vector<long long> p_pow(n);
  p_pow[0] = 1;
  for (int i = 1; i < n; ++i)
    p_pow[i] = (p_pow[i-1] * p) % m;

  vector<long long> h(n + 1, 0);
  for (int i = 0; i < n; ++i)
    h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;
  
  for (int l = n - 2; l >= 1; --l) {
    // check prefix and suffix of length l are equal
    long long suffix = (h[n] + m - h[n - l]) % m;
    long long prefix = (h[l] * p_pow[n - l]) % m;
    if (suffix == prefix) {
      // cout << l << '\n';
      for (int i = 0; i < n - l - 1; ++i) { // n - l + 1 substrings of length m
        long long cur_h = (h[l + 1 + i] + m - h[i+1]) % m;
        cur_h = (cur_h * p_pow[n - (l + 1 + i)]) % m;
        if (cur_h == suffix) {
          // cout << i << '\n';
          for (int j = 0; j < l; ++j) {
            cout << s[1 + i + j];
          }
          exit(0);
        } 
      }
    }
  }
  
  no ();
}

int main() {
  string s;
  cin >> s;
  password(s);
  return 0;
}
