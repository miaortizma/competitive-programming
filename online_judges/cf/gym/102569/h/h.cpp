#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n;
  cin >> n;
  int u, v;
  vector<int> in(n + 1);
  for (int i = 0; i < n - 1; ++i) {
    cin >> u >> v;
    in[u] += 1;
    in[v] += 1;
  }
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (in[i] == 1) {
      cnt++;
    }
  }
  cout << (cnt + 1) / 2;

  return 0;
}
