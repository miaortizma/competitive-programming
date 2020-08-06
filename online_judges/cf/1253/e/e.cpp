#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int n, m, x, s;

typedef pair<int, int> pii;
int arr[N];
bool vis[N];
pii antennas[90];

queue<pii> A, B;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> x >> s; 
    int l = max(1, x - s), r = min(m, x + s);
    arr[l] += 1;
    arr[r + 1] -= 1;
    antennas[i] = {l, r};
  }
  int left = 0;
  for (int i = 1; i <= m; ++i) {
    arr[i] += arr[i - 1];
    if (arr[i])
      vis[i] = true;
    else 
      left++;
  }
  vis[0] = vis[m + 1] = true;
  //cout << left;
  for (int i = 0; i < n; ++i) {
    int c = 2;
    int l = antennas[i].first, r = antennas[i].second;
    if (vis[l - 1]) c--;
    if (vis[r + 1]) c--;
    if (c == 2) {
      A.push(antennas[i]);
    } else if (c == 1) {
      B.push(antennas[i]);
    }
  }
  int ans = 0;
  while (left) {
    pii antenna;
    if (!A.empty()) {
      antenna = A.front();
      A.pop();
    } else {
      antenna = B.front();
      B.pop();
    }
    int l = antenna.first, r = antenna.second;
    cout << l << " " << r << "\n";
    if (!vis[l - 1] && !vis[r + 1]) {
      vis[l - 1] = true;
      vis[r + 1] = true;
      left -= 2;
      l = l - 1;
      r = r + 1;
      if (!vis[l - 1] && !vis[r + 1]) {
        A.push({l, r});
      } else if (!vis[l - 1]) {
        A.push({l, r - 1});
      } else if (!vis[r + 1]) {
        A.push({l + 1, r});
      }
    } else if (!vis[l - 1]) {
      vis[l - 1] = true;
      left--;
      l = l - 1;
      if (!vis[l - 1]) {
        B.push({l, r});
      }
    } else if (!vis[r + 1]) {
      vis[r + 1] = true;
      left--;
      r = r + 1;
      if (!vis[r + 1]) {
        B.push({l, r});
      }
    }
    ++ans;
  }
  cout << ans;
  return 0;
}
