#include<bits/stdc++.h>
using namespace std;

int n, m;
const int N = 1000008;

bool reach[N], vis[N];
int arr[2][N];
string isl[N];

int idd(int i, int j) {
  return i  * m + j;
}

bool dfs1(int a, int b) {
  int id_ = idd(a, b);
  if (vis[id_])
    return reach[id_];
  vis[id_] = true;

  if (a == n - 1 && b == m - 1)
    reach[id_] = true;
  
  int dx[] = {0, 1};
  int dy[] = {1, 0};
 
  for (int i = 0; i < 2; ++i) {
    int x = a + dx[i], y = b + dy[i];
    if (x < n && y < m && isl[x][y] != '#')
      reach[id_] |= dfs1(x, y);
  }
  if (reach[id_]) {
    arr[0][a] = min(arr[0][a], b);
    arr[1][a] = max(arr[1][a], b);
  } 
  return reach[id_];
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> isl[i];
    arr[0][i] = m + 5;
    arr[1][i] = -5;
  }
  dfs1(0, 0);
  int ans = min(2, min(n, m));
  if (!reach[idd(0, 0)])
    ans = 0;

  if (!reach[idd(0, 1)] || !reach[idd(1, 0)] || !reach[idd(n - 1, m - 2)]  || !reach[idd(n - 2, m - 1)] ) {
    ans = min(ans, 1);
  }
 
  for (int i = 0; i < n; ++i) {
    //cout << arr[0][i] << ' ' << arr[1][i] << '\n';
    for (int j = -2; j <= 2; ++j) {
      if (i + j < 0 || i + j >= n)
        break;
      if (abs(arr[0][i] - arr[1][i+j] - 2) <= 2) {
        ans = min(ans, 1);
        //cout << "wat: " << abs(arr[0][i] - arr[1][i+j] + 1) <<i << ' ' << i + j << '\n';
      }
    }
  }
  cout << ans;
  return 0;
}
