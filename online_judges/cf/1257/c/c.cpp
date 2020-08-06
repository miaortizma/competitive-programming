#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 2 * 1e5 + 100;
int n;
int last[N];
pii latest;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int T, tmp;
  cin >> T;
  while (T--) {
    cin >> n;
    memset(last, -1, sizeof last);
    latest = {0, 0};
    int ans = -1;
    for (int i = 1; i <= n; ++i) {
      cin >> tmp;
      if (last[tmp] != -1)  {
        int j = last[tmp];
        if (latest.first < j) {
          if (ans == -1)
            ans = i - j + 1;
          else 
            ans = min(ans, i - j + 1);
        }
        latest = {j, i};
      }
      last[tmp] = i;
    }
    cout << ans << "\n";
  }
  return 0;
}
