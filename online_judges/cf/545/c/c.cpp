#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define x first
#define h second
const int N = 1e5 + 10;
pii arr[N];
int X[2][2], dp[2][2];
int n;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  int _x, h;
  for (int i = 0; i < n; ++i) {
    cin >> _x >> h;
    arr[i] = {_x, h};
  }
  dp[0][0] = 1;
  X[0][0] = X[0][1] = arr[0].x;
  if (n == 1 || arr[0].x + arr[0].h < arr[1].x) {
    dp[0][1] = 1;
    X[0][1] = arr[0].x + arr[0].h;
  }
  for (int i = 1; i < n; ++i) {
    //left
    int e = i % 2, d = e ^ 1;
    //cerr << e << " " << d << "\n";
    X[e][0] = arr[i].x;
    for (int j = 0; j < 2; ++j) {
      if (X[d][j] < arr[i].x - arr[i].h) {
        dp[e][0] = max(dp[e][0], dp[d][j] + 1);
      } else {
        dp[e][0] = max(dp[e][0], dp[d][j]);
      }
    }
    //right
    X[e][1] = X[e][0];
    dp[e][1] = dp[e][0];
    if (i < n - 1 && arr[i].x + arr[i].h < arr[i + 1].x) {
      X[e][1] = arr[i].x + arr[i].h;
      for (int j = 0; j < 2; ++j) {
        dp[e][1] = max(dp[e][1], dp[d][j] + 1);
      }
    } else if(i == n - 1) {
      for (int j = 0; j < 2; ++j) {
        dp[e][1] = max(dp[e][1], dp[d][j] + 1);
      }
    }
  }
  int e = (n - 1) % 2;
  int ans = max(dp[e][0], dp[e][1]);
  cout << ans << "\n";
  return 0;
}
