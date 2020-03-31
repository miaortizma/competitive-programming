#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

const int N = 2005;
int n, h, l, r;
int arr[N];
int dp[N][N];
int t[2];

int p(int x) {
  if (l <= x && x <= r) return 1;
  return 0;
}

int go(int i, int t) {
  //cerr << "@@@@@@@\n";
  //cerr << i << " " << t << "\n";
  if (i == n) return 0;
  int &ret = dp[i][t];
  //cerr << ret << " :ret\n";
  if (ret != -1) return ret;
  ret = 0;
  //cerr << arr[i] << " :arr[i]\n";
  int th[] = {arr[i], (arr[i] - 1 + h) % h};
  //cerr << th[0] << " | " << th[1] << "\n";
  for (int j = 0; j < 2; ++j) {
    int thi = (t + th[j]) % h;
    //cerr << thi << " " << p(thi) << "\n";
    ret = max(ret, p(thi) + go(i + 1, thi));
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> h >> l >> r;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  memset(dp, -1, sizeof dp);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < h; ++j) {
      dp[i][j] = -1;
    }
  }
  int ans = go(0, 0);
  cout << ans;
  return 0;
}
