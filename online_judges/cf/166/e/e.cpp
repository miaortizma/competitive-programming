#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7; 
ll MOD2 = MOD * 1ll * MOD; // reduces modulo operations to O(n^2)
int res[4][4];

struct Matrix {
  int M[4][4];

  Matrix (int O[4][4]) { memcpy(M, O, sizeof M); }
  Matrix () { 
    memset(M, 0, sizeof M);
    for (int i = 0; i < 4; ++i) M[i][i] = 1; 
  }
  int* operator[](int idx) { return M[idx]; }

  Matrix operator*(Matrix o) {
    memset(res, 0, sizeof res);
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        ll r = 0;
        for (int k = 0; k < 4; ++k) {
          r += M[i][k] * 1LL * o[k][j];
          while (r >= MOD2) r -= MOD2;
        }
        res[i][j] = r % MOD;
      }
    }
    return Matrix{res};
  }
};


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n;
  cin >> n;
  int O[4][4] = {{0, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 0, 1}, {1, 1, 1, 0}};
  Matrix M{O}, I{};
  while (n) {
    if (n & 1) {
      I = I * M;
    }
    M = M * M;
    n >>= 1;
  }
  int ans = I[0][0];
  cout << ans << "\n";
  return 0;
}
