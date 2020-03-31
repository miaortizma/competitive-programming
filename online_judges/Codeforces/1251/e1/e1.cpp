#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int N = 5100;
int n;
pii arr[N];
ll dp[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> a >> b;
      arr[i] = {a, b};
    }
    for (int i = 1; i <= n; ++i) {
      dp[i] = arr[0].second + dp[i - 1];
      for (int j = 0; j < n; ++j) {
        
      }
    }
  }
  return 0;
}
