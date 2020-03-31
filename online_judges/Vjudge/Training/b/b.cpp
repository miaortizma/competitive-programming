#include<bits/stdc++.h>
using namespace std;

const int N = 1001;
int n;
int par[N], vis[N];
bool cycle[N], inCycle = false;
int cC;

void dfs(int u) {
  vis[u] = 1;
  if (vis[par[u]] == 1) {
    cC = par[u];
    inCycle = true;
  } else {
    dfs(par[u]);
  }
  if (inCycle) {
    cycle[u] = true;
    if (u == cC) {
      inCycle = false;
    }
  }
  vis[u] = 2;
}

int find(int u) {
  while(!cycle[u])
    u = par[u];
  return u;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> par[i];
  for (int i = 1; i <= n; ++i)
    if (vis[i] != 2)
      dfs(i);
  for (int i = 1; i <= n; ++i) {
    if (cycle[i]) {
      cout << i << " ";
    } else {
      cout << find(i) << " ";
    }
  }
  return 0;
}
