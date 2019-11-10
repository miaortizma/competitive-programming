#include<bits/stdc++.h>
using namespace std;

int modpow(int x, int b, int m) {
  int ret = 1;
  while (b) {
    if (b & 1)
      ret = (ret * 1ll * x) % m;
    x = (x * 1ll * x) %m;
    b >>= 1;
  }
  return ret;
}

bool witness(int n, int a, int d, int s) {
  int x = modpow(a, d, n);
  if (x == 1 || x == n - 1)
    return false;
  for (int r = 1; r < s; ++r) {
    x = (x * 1ll * x) % n;
    if (x == n - 1)
      return false;
  }
  return true;
}

void MillerRabin(int n) {
  int s = 0, d = n - 1;
  while ((d & 1) == 0) {
    d >>= 1;
    ++s;
  }
  cout << s << " " << d << "\n";
  for (int i = 2; i <= n - 1; ++i ) {
    if (!witness(n, i, d, s)) {
      cout << n << " Pseudoprime base: " << i << "\n";
    } else {
      cout << n << " Fails MillerRabin test base: " << i << "\n";
      int x = modpow(i, d, n);
      printf("%d ^ (2^0 * %d) = %d\n", i, d, x);
      for (int r = 1; r < s; ++r) {
        x = (x * 1ll * x) % n;
        printf("%d ^ (2^%d * %d) = %d\n", i,  r, d, x);
      }
    }
  }
}

int main() {
  int n;
  cin >> n;
  MillerRabin(n);
  return 0;
}
