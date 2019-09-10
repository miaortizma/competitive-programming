#include<bits/stdc++.h>
using namespace std;

const itn N = 1000;
int mat[N][N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  
  int T;
  cin >> T;

  while(T--) {
    int R, C;
    cin >> R >> C;
    for (int i = 0; i < R; ++i)
      for (int j = 0; j < C; ++j)
        cin >> mat[i][j];
    
    for (int i = 0; i < R; ++i) {
      if (mat[i][0]) {
        dp[i][0] = 0;
        dp[i][1] = 1;
      } else {
        dp[i][0] = 1;
        dp[i][1] = 0;
      }
    }

    for (int i = 1; i < C; ++i) {
      if (mat[0][i]) {
         
      } else {

      }
    }
  }

  return 0;
}
