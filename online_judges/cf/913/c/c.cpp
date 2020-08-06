#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 31;
ll b[N], c[N];
int n;

ll get(ll x) {
  //cerr << x << "  ";
  ll ans = 0;
  ll i = 0;
  while (x) {
    if (x & 1)
      ans += c[i];
    x >>= 1;
    ++i;
  }
  //cerr << ans << "\n";
  return ans;
}

ll cost(ll L) {
  //cerr << L << "\n";
  ll ans = get(L);
  for (int i = 0; i < n; ++i) {
    //cerr << "cost: " << i << "\n";
    if (!(L & (1 << i))) {
      int x = ((L >> (i)) | 1) << (i);
      ans = min(ans, get(x));
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int L;
  cin >> n >> L;
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
    b[i] = (1 << i);
  }
  for (int i = 1; i < n; ++i) {
    if (c[i - 1] * 2 < c[i])
      c[i] = c[i - 1] * 2;
  }
  int i = n - 1;
  ll ans = 0;
  ll q = L / b[i];
  L -= q * b[i];
  ans += q * c[i];
  //cerr << L << "<>" << b[i] << "\n";
  ans = ans + cost(L);
  cout << ans;
  return 0;
}
