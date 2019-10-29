#include<bits/stdc++.h>
using namespace std;

vector<int> ans[101];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 1; i <= n / 2 * n; ++i) {
    ans[(i - 1) % n].push_back(i);
    ans[(i - 1) % n].push_back(n * n - i + 1);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << ans[i][j] << ' ';
    }
    cout << "\n";
  }
  return 0;
}
