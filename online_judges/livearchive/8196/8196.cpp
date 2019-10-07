#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10, l = 18;

struct edge {
  int u, v, c;
  
  edge (int u, int v, int c) : u(u), v(v), c(c) {}
};

bool compare(edge lh, edge rh) { return lh.c < rh.c; }

int n, r, q;
vector<int> adj[N];
unordered_map<int, int> adjc[N];
vector<edge> edges;
int timer, arr[N], sz[N], tin[N], tout[N], up[N][l+1], upm[N][l+1];

int other(edge e, int u) {
  if (e.u == u) return e.v;
  return e.u;
}

void dfs(int v, int p, int c) {
  //printf("DFS: v: %d, p: %d, c: %d\n", v, p, c);
  tin[v] = ++timer;
  up[v][0] = p;
  upm[v][0] = c;
  //printf("up[%d][0]: %d\n", v, up[v][0]);
  for (int i = 1; i <= l; ++i) {
    up[v][i] = up[up[v][i-1]][i-1];
    upm[v][i] = max(upm[v][i-1], upm[up[v][i-1]][i-1]);
  }
  for (int i : adj[v]) {
    int u = other(edges[i], v);
    if (u != p)
      dfs(u, v, edges[i].c);
  }
  tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
  if (is_ancestor(u, v))
    return u;
  if (is_ancestor(v, u))
    return v;
  for (int i = l; i >= 0; --i) {
    if (!is_ancestor(up[u][i], v))
      u = up[u][i];
  }
  return up[u][0];
}


int solve(int u, int v) {
  int LCA = lca(u, v), ret = 0;
  //printf("LCA: %d\n", LCA);
  for (int i = l; i >= 0; --i) {
    if (up[v][i] == LCA || !is_ancestor(up[v][i], LCA)) {
      ret = max(ret, upm[v][i]);
      v = up[v][i];
    }
  }
  for (int i = l; i >= 0; --i) {
    if (up[u][i] == LCA || !is_ancestor(up[u][i], LCA)) {
      ret = max(ret, upm[u][i]);
      u = up[u][i];
    }
  }
  return ret;
}

void preprocess(int root) {
    timer = 0;
    dfs(root, root, 0);
}

int root(int i) {
  while (arr[i] != i) {
    arr[i] = arr[arr[i]];
    i = arr[i];
  }
  return i;
}

void merge(int u, int v) {
  if (sz[u] < sz[v])
    swap(u, v);
  if (sz[u] == sz[v])
    ++sz[u];
  arr[v] = u;
}

int main() {
  //ios_base::sync_with_stdio(0); cin.tie(NULL);
  int u, v, c;
  while (scanf("%d %d", &n, &r) == 2) {
    edges.clear();
    for (int i = 1; i <= n; ++i) {
      arr[i] = i;
      sz[i] = 0;
      adj[i].clear();
      adjc[i].clear();
    }
    for (int i = 0; i < r; ++i) {
      scanf("%d %d %d", &u, &v, &c);
      adjc[min(u, v)][max(u, v)] = c;
      edges.push_back(edge(u, v, c));
    }
    sort(edges.begin(), edges.end(), compare);
    ll spanning = 0;
    for (int i = 0; i < r; ++i) {
      edge e = edges[i];
      u = e.u, v = e.v, c = e.c;
      u = root(u), v = root(v);
      if (u != v) {
        //printf("spanning: %d %d %d\n", e.u, e.v, e.c);
        adj[e.u].push_back(i);
        adj[e.v].push_back(i);
        merge(u, v);
        spanning += 1LL * c;
      }
    }
    preprocess(1);
    scanf("%d", &q);
    /*for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= 3; ++j) {
        printf("up[%d][%d] = %d\n", i, j, up[i][j]);
      }
    }*/
    //printf("spanning: %lld\n", spanning);
    while (q--) {
      scanf("%d %d", &u, &v);
      //printf("%d %d\n", u, v);
      if (up[u][0] == v || up[v][0] == u) {
        //printf("%d %d\n", up[u][0], up[v][0]);
        printf("%lld\n", spanning);
      } else {
        ll ans = spanning - solve(u, v) + adjc[min(u, v)][max(u, v)];
        //printf("solve(u,v) = %d, adjc[%d][%d] = %d\n", solve(u,v), min(u,v), max(u,v), adjc[min(u,v)][max(u,v)]);
        printf("%lld\n", ans);
      }
    }
  }
  return 0;
}
