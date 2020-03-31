#include<bits/stdc++.h>
using namespace std;

const int N = 1024;
int n, d, x, y, c;
int mat[N + 10][N + 10];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    cin >> d >> n;
    for (int i = 0; i < n; ++i) {
      cin >> x >> y >> c;
      mat[x + 1][y + 1] = c;
    }
    for (int i = 1; i <= N; ++i)
      for (int j = 1; j <= N; ++j)
        mat[i][j] += mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1];
    int x = 0, y = 0, b = -1;
    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= N; ++j) {
        int UR = mat[min(i + d, N)][min(j + d, N)];
        int DL = mat[max(i - d - 1, 0)][max(j - d - 1, 0)];
        int UL = mat[min(i + d, N)][max(j - d - 1, 0)];
        int DR = mat[max(i - d - 1, 0)][min(j + d, N)];
        int c = UR + DL - UL - DR;
        if (c > b) {
          //cout << UR << " " << DL << " " << UL << " " << DR << "\n";
          x = i - 1, y = j - 1, b = c;
          //cout << b << "\n";
        }
      }
    }
    cout << x << " " << y << " " << b << "\n";
    memset(mat, 0, sizeof mat);
  }
  return 0;
}
