#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 100, l = 18;
int up[N][l + 1], upm[N][l];
vector<int> adj[N];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, m, a, b;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  return 0;
}
