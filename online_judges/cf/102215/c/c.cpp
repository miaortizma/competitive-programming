#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

const int N = 1e7 + 10;
bool found[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int p, n;
  cin >> p >> n;
  int bound = min(p, n);
  found[0] = true;
  int cur = 0;
  for (int i = 1; i <= bound; ++i) {
    cur = (cur + i) % p;
    found[cur] = true;
  }
  int ans = 0;
  for (int i = 0; i < p; ++i) {
    if (found[i]) {
      ans++;
    }
  }
  cout << ans;
  return 0;
}
