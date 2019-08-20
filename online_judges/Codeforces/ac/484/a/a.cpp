#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 63;

int A[N], B[N], C[N];

void parse(int arr[N], ll n) {
  for (int i = 0; i < N; ++i)
    arr[i] = 0;
  int i = 0;
  while(n) {
    arr[i] = n & 1;
    n >>= 1;
    ++i;
  }
}


int main() {
  int n;
  ll l, r;
  cin >> n;
  while(n--) {
    cin >> l >> r;  
    parse(A, l);
    parse(B, r);
    parse(C, r);
    int significant = 62;
    // significant bits
    while(significant >= 0 && B[significant] == 0)
      -- significant;
    
    // fixed bits

    while(significant >= 0 && B[significant] == A[significant]) {
      -- significant;
    }
    
    // greedy
    
    int i = 0;
    for (; i <= significant; ++i)
      if (B[i] == 0)
        break;
    
    if (i != significant + 1) {
      C[significant] = 0;
      for (i = 0; i < significant; ++i)
        C[i] = 1;
    }
   
    ll ans = 0;

    for (int i = 0; i < N; ++i) {
      if (C[i])
        ans += 1LL << i;
    }

    cout << ans << '\n';
  }
  return 0;
}
