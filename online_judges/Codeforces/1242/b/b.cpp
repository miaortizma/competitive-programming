#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
vector<int> adj[N];
map<int, int> cnt[N];

int arr[N], sz[N];

int root(int i) {
  while (arr[i] != i) {
    arr[i] = arr[arr[i]];
    i = arr[i];
  }
  return i;
}

set<int> components;

void un(int a, int b) {
  a = root(a), b = root(b);
  if (a == b) 
    return;
  if (sz[a] < sz[b])
    swap(a, b);
  sz[a] += sz[b];
  arr[b] = arr[a];
  components.insert(a);
  components.erase(b);
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, m, a, b;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    sz[i] = 1;
    arr[i] = i;
  }
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 1; i <= n; ++i)
    sort(adj[i].begin(), adj[i].end());
  components.insert(1);
  for (int i = 2; i <= n; ++i) {
    for (int j : adj[i]) {
      if (j > i)
        break;
      cnt[root(j)][i]++;
    }
    bool insert = true;
    vector<int> check;
    for (int u : components) {
      check.push_back(u);
    }
    for (int u : check) {
      if (cnt[u][i] < sz[u]) {
        un(u, i);
        insert = false;
      }
    }
    if (insert)
      components.insert(i);
  }
  cout << components.size() - 1;
  return 0;
}
