#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma


#define F first
#define S second
typedef pair<int, int> pi;
const int N = 110;
bool dp[N][N];
bool vis[N][N];


bool go(int x, int y) {
  if (x > y) {
    swap(x, y);
  }
  if (x == 0 || x == y) {
    return true;
  }
  if (vis[x][y]) {
    return dp[x][y];
  }
  vis[x][y] = true;
  //cout << x << " " << y << "\n";
  // (x - u)
  bool winning = true;
  for (int i = 1; i <= x; ++i) {
    winning &= go(x - i, y); 
  }
  // (y - u)
  for (int i = 1; i <= y; ++i) {
    winning &= go(x, y - i); 
  }
  // (x - u), (y - u)
  for (int i = 1; i <= x; ++i) {
    winning &= go(x - i, y - i); 
  }
  // all movements lead to winning positions... then lose
  if (winning) {
    return dp[x][y] = false;
  }
  // at least one movement leads to a losing position (for the other player)
  return dp[x][y] = true;
}


bool immediate(int x, int y) {
  if (x > y) {
    swap(x, y);
  }
  if (x == 0 || x == y) {
    cout << "immediate!\n";
    return true;
  }
  return false;
}

void printmoves(int x, int y) {
  if (x > y) {
    swap(x, y);
  }
  if (immediate(x, y)) {
    return;
  }
  for (int i = 1; i <= x; ++i) {
    cout << x - i << " " << y << " winning:" << go(x - i, y) << "\n";
    immediate(x - i, y);
  }
  // (y - u)
  for (int i = 1; i <= y; ++i) {
    cout << x << " " << y - i << " winning:" << go(x, y - i) << "\n";
    immediate(x, y - i);
  }
  // (x - u), (y - u)
  for (int i = 1; i <= x; ++i) {
    cout << x - i << " " << y - i << " winning:" << go(x - i,  y - i) << "\n";
    immediate(x - i, y - i);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<pi> v(n);
  bool onemove = false;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    v[i] = {a, b};
    if (a == b) onemove = true;
  }
  for (int i = 1; i <= 4; ++i) {
    for (int j = i; j <= 4; ++j) {
      cout << "\n";
      cout << i << " " << j << " is winning:" << go(i, j) << "\n";
      printmoves(i, j);
    }
  }

  if (onemove) {
    cout << "Y";
  } else {
    int cnt = 0;
    for (auto pa : v) {
      if (go(pa.F, pa.S)) {
        cnt += 1;
      }
    }
    cout << cnt << "\n";
    if (cnt & 1) {
      cout << "Y";
    } else {
      cout << "N";
    }
  }
  return 0;
}
