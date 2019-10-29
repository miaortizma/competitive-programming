#include<bits/stdc++.h>
using namespace std;

const int N = 30;

struct Vector {
  int v[N];
  int n;

  Vector (int n) : n(n) {}
};

struct Matrix {
  double M[N][N];
  int n, m;

  Matrix (int n, int m) : n(n), m(m) {}

  Matrix augment(Vector v) {
    assert (v.n == m);
    Matrix ret(n, m + 1);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        ret.M[i][j] = M[i][j];
      }
      ret.M[i][m] = v.v[i];
    }
    return ret;
  }

};

const double EPS = 1e-9;
const int INF = 2;

int GaussJordan(Matrix &A) {
  int n = A.n, m = A.m;
  double (*a)[N][N] = &A.M;
  /*for (int col = 0, row = 0; col < m && row < n; ++col) {
    int sel = row;
    for (int i = row; i < n; ++i) 
      if (abs(a[i][col]) > abs(a[sel][col]))
        sel = i;
    if (abs (a[sel][col] < EPS))
      continue
    //for (int i = col ; i <= m; ++i) {

    //}
  }*/
  return 0;
}

// Minimize c^Tx subject to Ax <= b and x >= 0
int simplex(Matrix A, Vector c, Vector b) {
  int n = A.n, m = A.m;
  Matrix aug = A.augment(b);
  GaussJordan(aug);
  while (true) {
    for (int i = 0; i < n; ++i) {

    }
  }
  return  0;
}


int main() {
  freopen("in1.txt", "r", stdin);
  int n, m; // n variables y m ecuaciones
  cin >> n >> m;
  Matrix A(m, n);
  Vector c(n), b(m);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> A.M[i][j];
    }
    cin >> b.v[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> c.v[i];
  }

  return 0;
}

