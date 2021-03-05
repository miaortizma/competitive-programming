#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

#define PB push_back
#define F first
#define S second
typedef pair<int, int> pi;

int n, mi, l, r, o, mx;
const int TIMES = 86400;
int nex[TIMES + 1];
map<pi, int> dp;
map<pi, bool> ok;
map<pi, bool> vis;


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
  pi cur{bit, i};
  if (vis[cur]) {
    return dp[cur];
  }
  vis[cur] = true;

  if (i != nex[i]) {
    int c = go(bit, nex[i]);
    pi ne{bit, nex[i]};
    if (ok[ne]) ok[cur] = true;
    return dp[cur] = c;
  }
  if (i == 86400) {
    if (full(bit)) {
      ok[cur] = true;
    }
    return dp[cur] = 0;
  }
  int c = go(bit, i + 1);
  pi ne{bit, i + 1};
  if (c > dp[cur] && ok[ne]) {
    dp[cur] = c;
    ok[cur] = true;
  }
  for (auto sh : mp[i]) {
    int nbit = bit | (1 << sh.stage);
    pi ne{nbit, sh.end};
    int c = sh.shared + go(nbit, sh.end);
    if (c > dp[cur] && ok[ne]) {
      ok[cur] = true;
      dp[cur] = c;
    }
  }
  return dp[cur];
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
  pi cur{0, 1};
  if (ok[cur]) {
    cout << ans;
  } else {
    cout << -1;
  }
  return 0;
}
