#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

bool ok(int a, int b, int c, int d) {
  bool A = abs(a - b) == abs(c - d);
  bool B = abs(a - c) == abs(b - d);
  return A && B;
}

int left(int a, int b, int c) {
  bool in[4];
  memset(in, false, sizeof in);
  in[a] = true;
  in[b] = true;
  in[c] = true;
  for (int i = 0; i < 4; ++i) {
    if (!in[i]) {
      return i;
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  vector<int> v(4);
  for (int i = 0; i < 4; ++i) {
    cin >> v[i];
  }
  bool can = false;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (i == j) continue;
      for (int k = 0; k < 4; ++k) {
        if (k == i) continue;
        if (k == j) continue;
        int r = left(i, j, k);
        if (ok(v[i], v[j], v[k], v[r])) {
          can = true;
          i = 4;
          j = 4;
          k = 4;
          break;
        }
      }
    }
  }
  if (can) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}
