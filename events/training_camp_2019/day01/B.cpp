#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

const int N = 50, NN = 1e4 + 100;
int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
string mat[N];
pii next[N][N][4];
int arr[NN];

void precalc() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++i) {
      for (int k = 0; k < 4; ++k) {
        bool found = false;
        int x = i, y = j;
        char c = mat[i][j];
        while (x < n && y < m && mat[x][y] == c) {
          x += dx[k];
          y += dy[k];
        }
        next[i][j][k] = pii({x, y});
      }
    }
  }
}

int main() {
  string s;
  while (cin >> n >> m) {
    for (int i = 0; i < n; ++i) {
      cin >> mat[i];
    }
    cin >> s;
    for (int i = 0, nn = s.size(); i < nn; ++i) {
      arr[i] = s[i];
    }
    queue<int> q;
    precalc();
    q.push(0);
    q.push(0);
    q.push(mat[0][0]);
    while (q.size()) {
      int x = q.pop(), y = q.pop(), p = q.pop();

    }
  }

  return 0;
}

