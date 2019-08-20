#include<bits/stdc++.h>
#define ll long long
using namespace std;

void printmat(vector< vector<ll> > mat) {
  cout << "mat: \n";
  for (vector<ll> row : mat) {
    for (ll elem : row)
      cout << elem << ' ';
    cout << '\n';
  }
}

vector< vector<ll> > matmul(vector< vector<ll> > A, vector< vector<ll> > B) {
  int n = A.size();
  int m = B[0].size();
  int k = B.size();
  vector< vector<ll> > mat(n, vector<ll>(m));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      for (int kk = 0; kk < k; ++kk)
        mat[i][j] += A[i][kk] * B[kk][j];
  return mat;
}

ll shift(int n) {
  //cout << "n:" << n << '\n';
  vector< vector<ll> > x = {{2, 3}},
    A = {{0, 1}, {1, 1}},
    I = {{1, 0}, {0, 1}};
  while (n) {
    if (n & 1)
      I = matmul(I, A);
    n >>= 1;
    A = matmul(A, A);
  }
  //printmat(matmul(x, I));
  return matmul(x, I)[0][1];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  ll n;
  cin >> n;

  if (n == 2) {
    cout << 1;
  } else if (n == 3 || n == 4) {
    cout << 2;
  } else {
    ll l = 3, h = 85;
    while(l < h) {
      ll m = l + (h - l + 1) / 2;
      if (shift(m - 2) <= n)
        l = m;
      else
        h = m - 1;
    }

    cout << l;
  }   
  return 0;
}
