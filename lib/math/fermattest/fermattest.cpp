#include<bits/stdc++.h>
using namespace std;

int modpow(int a, int b, int m) {
  int res = 1;
  while (b) {
    if (b & 1) {
      res = (res * 1ll * a) % m;
    }
    a = (a * 1ll * a) % m;
    b >>= 1;
  }
  return res;
}

bool fermatTest(int p) {
  bool ok = true;
  for (int i = 1; i < p; ++i) {
    int pow = modpow(i, p - 1, p);
    cout << i << ' ' << pow << '\n';
    if (pow != 1)
      ok = false;
  }
  return ok;
}

int main() {
  int n;
  cin >> n;
  fermatTest(n);
  return 0;
}

