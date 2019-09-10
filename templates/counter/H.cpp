#include <bits/stdc++.h>

using namespace std;


long n1, n2, n3;
long yI, yII, yIII;

long fastPow(long x, long mod) {
  long ans = 1;
  long n = 3;
  while (n > 0) {
    if (n % 2 == 1)
        ans = ((ans % mod) *( x % mod)) % mod;
    x = ((x % mod) * (x % mod)) % mod;
    n /= 2;
  }
  return ans;
}

void solve() {
  for (long x = 0; x < (1 << 21) + 1; x++) {
    if (fastPow(x, n1) == yI
        && fastPow(x, n2) == yII
        && fastPow(x, n3) == yIII) {
        printf("%ld\n", x);
        return;
    }
  }
}

int main() {
 int t;
 scanf("%d", &t);
  while(t--) {
    scanf("%ld %ld %ld", &n1, &n2, &n3);
    scanf("%ld %ld %ld", &yI, &yII, &yIII);
    solve();
  }
}
