#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

constexpr int MAXN = 5 + 100000;
constexpr int MOD = 7 + 1000000000;

struct E{int v, c;};

vector<E> t[MAXN];
int memo[MAXN][7][32];

int add(int a, int b) {
  int ans = a + b;
  if (ans >= MOD) ans -= MOD;
  return ans;
}

int mul(int a, int b) {
  return (1LL * a * b) % MOD;
}

int dp(int u, int pref, int bm, int p) {
  int& ans = memo[u][pref][bm];
  if (ans != -1) return ans;
  if (pref == (int) t[u].size()) return ans = 1;
  if (pref >= 5) return ans = 0;
  if (t[u][pref].v == p) return ans = dp(u, 1 + pref, bm, p);
  ans = 0;
  if (t[u][pref].c == -1) {
    for (int i = 0; i <= 4; ++i) {
      if ((bm & (1 << i)) != 0) continue;
      ans = add(ans, mul(dp(u, 1 + pref, bm | (1 << i), p), dp(t[u][pref].v, 0, 1 << i, u)));
    }
  } else {
    if ((bm & (1 << t[u][pref].c)) != 0) return ans = 0;
    return ans = mul(dp(u, 1 + pref, bm | (1 << t[u][pref].c), p), dp(t[u][pref].v, 0, 1 << t[u][pref].c, u));
  }
  return ans;
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n; cin >> n;
  for (int i = 1; i < n; ++i) {
    int u,v,c; cin >> u >> v >> c; --c;
    t[u].push_back(E{v, c});
    t[v].push_back(E{u, c});
  }
  memset(memo, -1, sizeof memo);
  cout << dp(1, 0, 0, 0) << '\n';
  return 0;
}
