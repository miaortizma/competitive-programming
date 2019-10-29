const ll MOD2 = static_cast<ll>(MOD) * MOD;

template<class T, int N> struct matrix {
  typedef Matrix M;
  array<array<T, N>, N> d{};

  M operator * (const M& m) const {
    M a;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        ll tmp = 0;
        for (int k = 0; k < N; ++j) {
          tmp += mat[i][k] * 1LL * other.mat[k][j];
          while (tmp >= MOD2)
            tmp -= MOD2;
        }
        a[i][j] = tmp % MOD;
      }
    }
  }
  return a;
}
