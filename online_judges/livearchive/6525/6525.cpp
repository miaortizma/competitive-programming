#include<bits/stdc++.h>
using namespace std;

const int N = 101;
bool pawn[N][N], rook[N][N];
int nextPawn[N][N];
string row;
int n;

bool isValid(int x, int y) {
  if (!(0 <= x && x < n && 0 <= y && y < n && !pawn[x][y]))
    return false;
  for (int i = x - 1; i >= 0; --i) {
    if (pawn[i][y])
      return true;
    if (rook[i][y])
      return false;
  }
  return true;
}

int lim = 0;

void displayBoard() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (pawn[i][j]) {
        cerr << 'X';
      } else if (rook[i][j]) {
        cerr << 'R';
      } else {
        cerr << '.';
      }
    }
    cerr << '\n';
  }
  cerr << '\n';
}

int max_ = 0;

int maxRooks(int x, int y, int c) {
  rook[x][y] = true;
  int ret = c;
  int next = 1 + nextPawn[x][y];
  if (c > max_) {
    cerr << c << '\n';
    max_ = c;
  }
  if (isValid(x, next)) // place in same column
    ret = max(ret, maxRooks(x, next, c + 1));
  for (int i = 0; i < n; ++i) {
    if (isValid(x + 1, i))
      ret = max(ret, maxRooks(x + 1, i, c + 1));  // place on next row
  }
  if (c == 5) {
    displayBoard();
  }
  rook[x][y] = false;
  return ret;
}



int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);

  while (cin >> n) {
    memset(pawn, false, sizeof pawn);
    memset(rook, false, sizeof rook);
    lim = 0;
    for (int i = 0; i < n; ++i) {
      cin >> row;
      for (int j = 0; j < n; ++j) {
        if (row[j] == 'X') {
          pawn[i][j] = true;
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      int next = n;
      for (int j = n - 1; j >= 0; --j) {
        nextPawn[i][j] = next;
        if (pawn[i][j]) {
          next = j;
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (isValid(0, i))
        ans = max(ans, maxRooks(0, i, 1));
    }
    cout << ans << '\n';
  }
  return 0;
}
