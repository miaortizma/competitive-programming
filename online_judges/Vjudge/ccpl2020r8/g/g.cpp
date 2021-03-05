#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

const int N = 8;
const int OO = 100000;
int M[N][N];

int n;

int dp[256 + 5][256 + 5];
bool vis[256 + 5][256 + 5];

int go(int alice, int bob) {
  if (!alice || !bob) return 0;
  if (vis[alice][bob]) {
    return dp[alice][bob];
  }
  vis[alice][bob] = true;


  int curA = - OO;
  for (int i = 0; i < n; ++i) {
    if ((1 << i) & alice) {
      int curB = OO;
      for (int j = 0; j < n; ++j) {
        if ((1 << j) & bob) {
          int na = alice & ~(1 << i);
          int nb = bob & ~(1 << j);

          curB = min(curB, M[i][j] + go(na, nb));
        }
      }
      curA = max(curA, curB);
    }
  }

  return dp[alice][bob] = curA;
}



void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> M[i][j];
    }
  }
  for (int i = 0; i < (1 << n); ++i) {
    for (int j = 0; j < (1 << n); ++j) {
      vis[i][j] = false;
    }
  }
  int full = (1 << n) - 1;
  //cout << full << "\n";
  cout << go(full, full) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
