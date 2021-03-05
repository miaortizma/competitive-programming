#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

#define PB push_back
const int N = 2 * 1e5 + 1;
vector<int> v[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, a, c;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a >> c;
    v[c].PB(a);
  }
  bool ok = true;
  for (int i = 1; ok && i < N; ++i) {
    int last = -1e9 - 1;
    for (auto x : v[i]) {
      if (x < last) {
        ok = false;
        break;
      }
      last = x;
    }
  }
  if (ok) {
    cout << "YES";
  } else {
    cout << "NO";
  }

  return 0;
}
