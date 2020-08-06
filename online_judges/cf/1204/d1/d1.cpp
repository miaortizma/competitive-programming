#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e5;

int dp[N][2];

pair<int, int> calc(int i, int val) {
  pii ans;
  if (val == 0)
    ans = pii({dp[i - 1][0] + 1, dp[i - 1][1]});
  else
    ans = pii({dp[i - 1][0], max(dp[i - 1][0], dp[i - 1][1]) + 1});
  
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  string s;
  cin >> s;
  int n = s.size();
  for (int i = 1; i <= n; ++i) {
    if (s[i - 1] == '0') {
      dp[i][0] = dp[i - 1][0] + 1;
      dp[i][1] = dp[i - 1][1];
    } else {
      dp[i][0] = dp[i - 1][0];
      dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
    }
  }
  for (int i = 2; i <= n; ++i) {
    pii lis1 = pii({dp[i - 1][0], dp[i - 1][1]});
    int lis2 = max(dp[i][0], dp[i][1]);
    if (s[i - 2] == '1') {
      cout << i << '\n';
      pii test = calc(i - 1, 0);
      dp[i - 1][0] = test.first;
      dp[i - 1][1] = test.second;
      pii test2 = calc(i, s[i - 1] - '0');
      if (max(test2.first, test2.second) == lis2) {
        s[i - 2] = '0';
      }
    }
  } 
  cout << s;
  return 0;
}
