#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 100, S = 317;
vector<int> adj[N], euler;
int color[N], freq[2 * N + 100], tin[N], tout[N], answ[N], ans[2 * N + 100], t = 0;

struct Query {
  int l, r, id, k;
  Query(int l, int r, int id, int k) : l(l), r(r), id(id), k(k) {}
};

vector<Query> v;

bool cmp(Query A, Query B){
  if (A.l / S != B.l / S) return A.l < B.l;
  return A.l / S % 2 ? A.r > B.r : A.r < B.r;
}

void dfs(int u, int p) {
  euler.push_back(u);
  tin[u] = t;
  ++t;
  for (int v : adj[u])
    if (v != p)
      dfs(v, u);
  euler.push_back(u);
  tout[u] = t;
  ++t;
}

void add(int i) {
  int val = color[euler[i]];
  ++freq[val];
  ++ans[freq[val]];
}

void dlt(int i) {
  int val = color[euler[i]];
  --ans[freq[val]];
  --freq[val];
}

int main() {
  int n, m, a, b;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &color[i]);
  for (int i = 0; i < n - 1; ++i) {
    scanf("%d %d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1, 1);
  for (int i = 0; i < m; ++i) {
    scanf("%d %d", &a, &b);
    v.push_back(Query({tin[a], tout[a], i,  b}));
  }
  sort(v.begin(), v.end(), cmp);
  int l = 0, r = -1;
  for(int i = 0; i < m; i++){
    Query qe = v[i];
    while(r < qe.r){
      r++;
      add(r);
    }
    while(r > qe.r){
      dlt(r);
      r--;
    }
    while(l < qe.l){
      dlt(l);
      l++;
    }
    while(l > qe.l){
      l--;
      add(l);
    }
    answ[qe.id] = ans[2 * qe.k];
  }
  for (int i = 0; i < m; ++i) {
    printf("%d\n", answ[i]);
  }
  return 0;
}

