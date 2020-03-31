#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

constexpr int MAXN = 2000005;

int sdiv[MAXN];
int p[MAXN];

void sieve() {
  for (int i = 1; i < MAXN; ++i) {
    for (int j = i; j < MAXN; j += i) {
      sdiv[j] += i;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  sieve();
  p[0] = -1;
  for (int i = 1; i < MAXN; ++i) {
    if (sdiv[i] - i == i) {
      p[i] = i;
    } else {
      p[i] = p[i - 1];
    }
  }
  int tc; cin >> tc;
  while (tc--) {
    int x; cin >> x;
    cout << p[x] << '\n';
  }
  return 0;
}
