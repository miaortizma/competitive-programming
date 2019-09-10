#include<bits/stdc++.h>
using namespace std;

// 0 if unable to make 
// val if which coin was used to make
const int N = 1e6;
int n;
int coins[101], reconstruction[101];
int dp[N + 1];
int lastg = -10, lastr = -10;
vector<int> values;

void reconstruct(int m) {
  memset(reconstruction, 0, sizeof reconstruction);
  while (dp[m] != 0) {
    reconstruction[dp[m]]++;
    m -= coins[dp[m] - 1];
  }
  cout << 1 << '\n';
  for (int i = 1; i <= n; ++i)
    cout << reconstruction[i] << ' ';
  cout << '\n';
  fflush(stdout);
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> coins[i];
  values.push_back(0);
  for (int i = 1; i <= N; ++i) {
    for (int j = n - 1; j >= 0; --j) {
      if (coins[j] > i)
        continue;
      if (i == coins[j] || dp[i - coins[j]] != 0) {
        values.push_back(i);
        dp[i] = j + 1;
        break;
      }
    }
  }
  int l = 0, h = values.size() - 1;
  bool found = false;
  int i;
  string response;
  for (i = 0; l <= h && i < 30; ++i) {
    int m = l + (h - l) / 2;
    int val = values[m];
    reconstruct(val);
    cin >> response; 
    if ("green" == response) {
      lastg = m;
      l = m + 1;
    } else if ("red" == response) {
      lastr = m;
      h = m - 1;
    } else {
      found = true;
      cout << 2 << '\n';
      cout << val << '\n';
      fflush(stdout);
      break;
    }
  }
  if (!found) {
    cout << 2 << '\n';
    if (lastr - lastg == 1 && values[lastr] - values[lastg] == 2)
      cout << values[lastg] + 1; 
    else
      cout << -1;
    cout << '\n';
    fflush(stdout);
  }
  return 0;
}

