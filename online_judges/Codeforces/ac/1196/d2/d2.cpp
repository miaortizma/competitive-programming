#include<bits/stdc++.h>
using namespace std;

int q;
int n, k;
string s;

int modSum(int x, int y, int m) {
  return (x%m + y%m + m)%m;
}

int main() {
  
  string S = "RGB";
  cin >> q;

  while (q--) {
    cin >> n >> k >> s;
    int A[3] = {0, 1, 2}, W[3] = {0, 0, 0};
    int ans = n;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 3; ++j) {
        int c = (S[A[j]] == s[i])?(0):(1);
        W[j] += c;
        if(i >= k - 1) {
          ans = min(ans, W[j]);
          int idx = modSum(A[j], -(k - 1), 3);
          W[j] -= (S[idx] == s[i - (k - 1)])?(0):(1);
        } 
        A[j] = modSum(A[j], 1, 3);
      }
    }

    cout << ans << '\n';
  }
}