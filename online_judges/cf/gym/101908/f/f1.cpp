#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

#define PB push_back
#define F first
#define S second
typedef pair<int, int> pi;

int n, mi, l, r, o, mx;
const int BITS = (1 << 10) + 1;
const int TIMES = 86400 + 1;
int nex[TIMES + 1];
int dp[BITS][TIMES];
bool ok[BITS][TIMES];
bool vis[BITS][TIMES];


struct show {
  int start, end, shared, stage;
};

vector<show> mp[TIMES];

bool full(int bit) {
  for (int i = 0; i < n; ++i) {
    if (! (bit & (1 << i))) {
      return false;
    }
  }
  return true;
}


int go(int bit, int i) {
  if (vis[bit][i]) {
    return dp[bit][i];
  }
  vis[bit][i] = true;
  int &v = dp[bit][i];
  bool &o = ok[bit][i];

  if (i != nex[i]) {
    int c = go(bit, nex[i]);
    if (ok[bit][nex[i]]) o = true;
    return v = c;
  }
  if (i == 86400) {
    if (full(bit)) {
      o = true;
    }
    return v = 0;
  }
  int c = go(bit, i + 1);
  if (c > v && ok[bit][i + 1]) {
    v = c;
    o = true;
  }
  for (auto sh : mp[i]) {
    int nbit = bit | (1 << sh.stage);
    int c = sh.shared + go(nbit, sh.end);
    if (c > v && ok[nbit][sh.end]) {
      o = true;
      v = c;
    }
  }
  return v;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> mi;
    for (int j = 0; j < mi; ++j) {
      cin >> l >> r >> o;
      mx = max(mx, r);
      show sh{l, r, o, i};
      mp[l].PB(sh);
    }
  }
  int lst = 86400;
  for (int i = 86400; i >= 1; --i) {
    if (mp[i].size() > 0) {
      lst = i;
    }
    nex[i] = lst;
  }
  int ans = 0;
  ans = go(0, 1);
  if (ok[0][1]) {
    cout << ans;
  } else {
    cout << -1;
  }
  return 0;
}
