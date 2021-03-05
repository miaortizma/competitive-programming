#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma
// Capitals are input or const

const int MAXN = 50;
typedef pair<int, int> pii;
string grid[MAXN];
int N, M;
bool vis[MAXN][MAXN];

bool valid(pii pos) {
  int x = pos.first, y = pos.second;
  return x >= 0 && y >= 0 && x < N && y < M;
}

bool good(pii pos) {
  int x = pos.first, y = pos.second;
  return grid[x][y] == 'G';
}

bool bad(pii pos) {
  int x = pos.first, y = pos.second;
  return grid[x][y] == 'B';
}

bool blocked(pii pos) {
  int x = pos.first, y = pos.second;
  return grid[x][y] == '#';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int T;
  cin >> T;

  //cerr << "here\n";
  while (T--) {
    cin >> N >> M;

    int goodCount = 0;

    for (int i = 0; i < N; ++i) {
      cin >> grid[i];
      for (int j = 0; j < M; ++j) {
        if (grid[i][j] == 'G') {
          goodCount++;
        }
        vis[i][j] = false;
      }
    }

    bool ok = true;
    queue<pii> q;
    q.push({N - 1, M - 1});
    while (!q.empty()) {
      // look left and up
      pii u = q.front(); q.pop();
      if (blocked(u)) continue;
      int x = u.first, y = u.second;
      if (vis[x][y]) continue;
      vis[x][y] = true;
      //cerr << x << " " << y << "\n";

      bool block = false;
      vector<pii> vec{{x - 1, y}, {x, y - 1}, {x + 1, y}, {x, y + 1}};

      for (auto v : vec) {
        if (!valid(v)) continue;
        if (bad(v)) {
          block = true;
        }
      }

      if (block && good(u)) {
        ok = false;
        break;
      }
      if (!block) {
        if (good(u)) goodCount--;
        for (auto v : vec) {
          if (valid(v)) q.push(v);
        }
      }
    }

    if (goodCount == 0 && ok) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }

  }
  return 0;
}
