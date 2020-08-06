#include<bits/stdc++.h>
using namespace std;

const int N = 2 * 1e5 + 10;
typedef pair<int, int> pii;
pii dp[N];
int arr[N];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, b, a, amax, t;
  cin >> n >> b >> a;
  amax = a;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    a = min(a, amax);
    if (arr[i]) {
      if (a) {
        if (a != amax && b) {
          ++a;
          --b; 
        } else {
          --a;
        }
      } else if (b) {
        ++a;
        --b;
      } else {
        break;
      }
    } else {
      if (a) {
        --a;
      } else if (b) {
        --b;
      } else {
        break;
      }
    }
    ++ans;
  }

  cout << ans;
  return 0;
}
