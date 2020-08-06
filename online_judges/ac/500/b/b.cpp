#include<bits/stdc++.h>
using namespace std;

const int N = 300;
int arr[N], vis[N];
string adj[N];

int n;

vector<int> vals, poss;

void dfs(int u) {
  vis[u] = 1;
  vals.push_back(arr[u]);
  poss.push_back(u);

  for (int i = 0; i < n; ++i)
    if (adj[u][i] == '1'  && !vis[i])
      dfs(i);
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
  
  for (int i = 0; i < n; ++i)
      cin >> adj[i];
  
  for (int i = 0; i < n; ++i) {
    vals.clear();
    poss.clear();
    if (!vis[i]) {
      dfs(i);
      sort(vals.begin(), vals.end());
      sort(poss.begin(), poss.end());
      int m = vals.size();
      for (int j = 0; j < m; ++j)
        arr[poss[j]] = vals[j];
    }
  }

  for (int i = 0; i < n; ++i)
    cout << arr[i] << ' ';

  cout << '\n';
  return 0;
}
