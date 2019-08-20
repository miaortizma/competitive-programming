#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll S[3], N[3], P[3], r;

int main() {
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); ++i)
    if(s[i] == 'B') {
      ++N[0];
    } else if(s[i] == 'S') {
      ++N[1];
    } else {
      ++N[2];
    }
  
  cin >> S[0] >> S[1] >> S[2];
  cin >> P[0] >> P[1] >> P[2];
  cin >> r;
  
  ll l = 0, h = 0;

  for (int i = 0; i < 3; ++i)
    h = max(h, (r / P[i] + S[i]) / max(1LL, N[i]));

  while(l < h) {
    ll m = l + (h - l + 1) / 2;
    ll c = 0;
    for (int i = 0; i < 3; ++i)
      c += max(0LL, P[i] * (m * N[i] - S[i]));
       
    if (c <= r) {
      l = m;
    } else {
      h  = m - 1;
    }
  }

  cout << l;
  

  return 0;
}
