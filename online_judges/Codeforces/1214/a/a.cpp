#include<bits/stdc++.h>
using namespace std;

const int N = 1e8;
bool can[N+1];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, d, e, last = 0;
  cin >> n >> d >> e;
  e *= 5;
  can[0] = true;
  for (int i = min(d, e); i <= n; ++i) {
    if (i - d >= 0 && can[i - d]) {
      can[i] = true;
      last = i;
    } else if (i - e >= 0 && can[i - e]) {
      can[i] = true;
      last = i;
    }
  }
  cout << n - last;
  return 0;
}
