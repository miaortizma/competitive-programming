#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

const int N = 2 * 1e5 + 10;
int cnt[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  int coc = (n - 1) / k, rem = (n - 1) % k;
  for (int i = 2; i <= k + 1; ++i) {
    cnt[i] = coc - 1;
  }
  for (int i = 2; i <= rem + 1; ++i) {
    cnt[i] += 1;
  }
  int I = 1;
  int len;
  if (rem == 0) {
    len = coc * 2;
  } else if (rem == 1) {
    len = coc * 2 + 1;
  } else {
    len = coc * 2 + 2;
  }
  cout << len << "\n";
  for (int i = 0; i < k; ++i) {
    cout << 1 << " " << (I + 1) << "\n";
    ++I;
    for (int j = 0; j < cnt[2 + i]; ++j) {
      cout << (I) << " " << (I + 1) << "\n";
      ++I;
    }
  }
  return 0;
}
