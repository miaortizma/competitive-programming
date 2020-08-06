#include<bits/stdc++.h>
using namespace std;

const int N = 101, M = 1e6 + 1;
int d[N][N];
int sub[M];
bool in[M];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, tmp;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    string s;
    cin >> s;
    for (int j = 1; j <= n; ++j)
      d[i][j] = s[j - 1] == '1' ? 1 : 10000;
  }
  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        if (d[i][j] > d[i][k] + d[k][j])
          d[i][j] = d[i][k] + d[k][j];

  int m;
  cin >> m;
  for (int i = 0; i < m; ++i)
    cin >> sub[i];
  int last = 0;
  int ans = 0;
  for (int i = 1; i < m; ++i) {
    /*cout << "@@@@@@@@@@@@@\n";
    cout << last << ' ' << i << '\n';
    cout << d[sub[last]][sub[i]] << ' ' << i - last << '\n';
    */
    while(i < m && sub[last] != sub[i] && d[sub[last]][sub[i]] == i - last) {
      ++i;
    }
    in[i - 1] = true;
    last = i - 1;
  }
  in[0] = in[m - 1] = true;
  for (int i = 0; i < m; ++i)
    if (in[i])
      ++ans;
  cout << ans << '\n';
  for (int i = 0; i < m; ++i)
    if (in[i])
      cout << sub[i] << ' ';

  return 0;
}
