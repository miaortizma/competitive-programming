#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2001;
int mat[N][N];
ll sdiagX[2 * N - 1], sdiagY[2 * N - 1];
int n;

int diagX(int i, int j) {
  return i + j;
}

int diagY(int i, int j) {
  return i + abs(n - 1 - j);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> mat[i][j];

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int x = diagX(i, j), y = diagY(i, j);
      sdiagX[x] += mat[i][j];
      sdiagY[y] += mat[i][j];
    }
  }

  ll ansA = 0, ansB = 0;
  int x1 = 0, y1 = 0, x2 = 0, y2 = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int x = diagX(i, j), y = diagY(i, j);
      ll val = sdiagX[x] + sdiagY[y] - mat[i][j];
      if (x & 1) {
        if (val > ansA) {
          x1 = i;
          y1 = j;
          ansA = val;
        }
      } else {
        if (val > ansB) {
          x2 = i;
          y2 = j;
          ansB = val;
        }
      }
    }
  }
  ll ans = ansA + ansB;
  cout << ans << '\n';
  cout << x1 + 1 << ' ' << y1 + 1 << ' '<< x2 + 1 << ' ' << y2 + 1 << '\n';
  return 0;
}
