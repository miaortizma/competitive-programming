#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

const int N = 131072 + 10;
const int C = 19;
int cnt[C][N];

int id(char c) {
  return c - 'a';
}

int cost(int l, int k, char c) {
  int ci = id(c);
  int r = l + k - 1;
  int have;
  if (l == 0) {
    have = cnt[ci][r];
  } else {
    have = cnt[ci][r] - cnt[ci][l - 1];
  }
  /*
  if (have < 0) {
    cerr << "@@@@@\n";
    cerr << l << " " << r << "\n";
    cerr << c << "\n";
    cerr << k << " " << have << "\n";
    cerr << "@@@@@\n";
  }
  */
  return k - have;
}

int solve(int l, int k, char c) {
  if (k == 1) {
    return cost(l, k, c);
  }
  int left = cost(l, k / 2, c) + solve(l + k / 2, k / 2, (c + 1));
  int right = cost(l + k / 2, k / 2, c) + solve(l, k / 2, (c + 1));
  return min(left, right);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t, n;
  string s;

  cin >> t;
  while (t--) {
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
      for (int c = 0; c < C; ++c) {
        cnt[c][i] = 0;
      }
    }
    for (int i = 0; i < n; ++i) {
      if (id(s[i]) >= C) continue;
      cnt[id(s[i])][i] += 1;
    }
    for (int i = 1; i < n; ++i) {
      for (int c = 0; c < C; ++c) {
        cnt[c][i] += cnt[c][i - 1];
      }
    }
    int ans = solve(0, n, 'a');
    cout << ans << "\n";
  }
  return 0;
}
