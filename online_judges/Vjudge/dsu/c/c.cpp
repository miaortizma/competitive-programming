#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 510;
string keys[N];
bool vis[N];

int n;

int dist(char a, char b) {
  int round = min(abs(a - '0') + abs(b - '9'), abs(a - '9') + abs(b - '0'));
  return min(abs(a - b), round);
}

int moves(string a, string b) {
  int ret = 0;
  for (int i = 0; i < 4; ++i)
    ret += dist(a[i], b[i]);
  return ret;
}

typedef pair<int, int> edge;

void MST() {
  priority_queue<edge> pq;
  pq.push({-0, 0});
  set<int> unvisited;
  visited.insert(0);
  for (int i = 1; i <= n; ++i)
    unvisited.insert(i);
  int ans = 0;
  while (visited.size() != n + 1) {
    for (int u )
  }
  cout << ans << "\n";
}



int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int T; 
  cin >> T;
  v[0] = "0000";
  while (T--) {
    cin >> n;
    string s;
    for (int i = 1; i <= n; ++i) {
      cin >> keys[i];
    }
    MST();
    memset(vis, false, sizeof vis);
  }
  return 0;
}
