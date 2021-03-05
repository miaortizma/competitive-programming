#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma
typedef long long ll;
typedef vector<ll> vi;
const int MOD = 1e6;

struct Matrix {
  int n, m;
  vector<vi> M;

  Matrix (int n, int m) : n(n), m(m), M(n, vi(m)) {}

  vector<ll> & operator[](int i) {
    return M[i];
  }

};

Matrix identity(int n) {
  Matrix C(n, n);
  for (int i = 0; i < n; ++i) {
    C[i][i] = 1;
  }
  return C;
}

ll sum(ll a, ll b) {
  return (a % MOD + b % MOD) % MOD;
}

ll mult(ll a, ll b) {
  return ((a % MOD) * (b % MOD)) % MOD;
}

Matrix operator*(Matrix A, Matrix B) {
  int n = A.n;
  int m = B.m;
  int K = A.m;
  Matrix C(n, m);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int k = 0; k < K; ++k) {
        C[i][j] = sum(C[i][j], mult(A[i][k], B[k][j]));
      }
    }
  }
  return C;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  ll N, K, L;
  cin >> N >> K >> L;

  ll ans = 0;
  ll ans5 = K % MOD, ans10 = sum(mult(K, K), L);
  if (N == 5) {
    ans = ans5;
  } else if (N == 10) {
    ans = ans10;
  } else {
    vector<vi> v{
      {0, 0, 0},
      {1, 0, L},
      {0, 1, K}
    };
    Matrix M(3, 3);
    M.M = v;
    ll n = (N / 5) - 2;

    v = {vi{1, ans5, ans10}};
    Matrix A(1, 3);
    A.M = v;
    /*
    for (int i = 0; i < 3; ++i) {
      cout << A[0][i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        cout << M[i][j] << "\t";
      }
      cout << "\n";
    }
    cout << "\n";
    cout << "n: " << n << "\n";
    */
    int i = 0;
    while (n) {
      if (n & 1) {
        //cout << i << " " << "here \n";
        A = A * M;
      }
      i += 1;
      M = M * M;
      n >>= 1;
    }
    /*
    for (int i = 0; i < 3; ++i) {
      cout << A[0][i] << " ";
    }
    cout << "\n";
    */
    ans = A[0][2];
  }
  int c = 0;
  ll ans1 = ans;
  while (ans1 > 0) {
    ans1 /= 10;
    c++;
  }
  while (6 - c > 0) {
    cout << 0;
    c++;
  }
  if (ans > 0) {
    cout << ans << "\n";
  }
  return 0;
}
