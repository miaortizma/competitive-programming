#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

const int N = 2 * 1e5 + 10;
int arr[N];
int n, k;

bool can(int m) {
  int need = 0;
  for (int i = 0; i < n; ++i) {
    if (arr[i] > m) need += arr[i] / m;
  }
  return need <= k;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> k;
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
  }
  int lo = 0, hi = 1e9 + 1;
  while (lo < hi) {
    int m = (lo + hi) / 2;
    if (can(m)) {
      hi = m;
    } else {
      lo = m + 1;
    }
  }
  if (can(lo)) {
    cout << lo;
  } else {
    cout << lo - 1;
  }

  return 0;
}
