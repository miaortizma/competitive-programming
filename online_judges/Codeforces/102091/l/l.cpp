#include<bits/stdc++.h>
using namespace std;

const int N = 1011;
int M[N][N], dp[N][N];

int sum(int x1, int y1, int x2, int y2) {
  return M[x2][y2] - M[x2][y1 - 1] - M[x1 - 1][y2] + M[x1 - 1][y1 - 1];
}

int T, R, C;
char c;

int main() {
  // to test
  scanf("%d", &T);
  while(T--) {
    scanf("%d %d", &R, &C);
    for (int i = 1; i <= R; ++i) {
      for (int j = 1; j <= C; ++j) {
        do{c=getchar();} while (c != '0' && c != '1');
        M[i][j] = c - '0' + M[i - 1][j] + M[i][j - 1] - M[i - 1][j - 1];
      }
    }
    int ans = 0;
    for (int i = 1; i <= R; ++i) {
      for (int j = 1; j <= C; ++j) {
        dp[i][j] = max({1, dp[i - 1][j -1] - 1, dp[i - 1][j] - 1, dp[i][j - 1] - 1});
        while(i + dp[i][j] <= R && j + dp[i][j] <= C && sum(i, j, i + dp[i][j], j + dp[i][j]) <= 1) dp[i][j]++;
        ans = max(ans, dp[i][j]);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
