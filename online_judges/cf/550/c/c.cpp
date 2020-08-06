#include<bits/stdc++.h>
using namespace std;

const int N = 110;
bool dp[N][8];
int par[N][8];
char re[N][8];
int p[N];

int toi(char x) {
  return x - '0';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  string s;
  cin >> s;
  int n = s.size();
  p[0] = 1;
  for (int i = 1; i < n; ++i) p[i] = (10 * p[i - 1]) % 8; 

  for (int i = 0; i < n; ++i) {
    char c = s[n - 1 - i];
    int val = toi(c) % 8;
    for (int j = i; j > 0; --j) {
      for (int k = 0; k < 8; ++k) {
        int res = (k + val * p[j]) % 8; 
        if (dp[j - 1][k] && !dp[j][res]) {
          dp[j][res] = true;
          re[j][res] = c;
          par[j][res] = k;
        }
      }
    }
    if (!dp[0][val]) {
      dp[0][val] = true;
      re[0][val] = c;
    }
  }
  bool y = false;
  for (int i = 0; i < n; ++i) {
    if (dp[i][0]) {
      y = true;
      cout << "YES\n";
      int v = 0;
      //cerr << "i\tv\n";
      while (i > 0) {
        //cerr << i << " " << v << "\n";
        cout << re[i][v];
        v = par[i][v];
        --i;
      }
      cout << re[i][v] << "\n";
      i = n;
      break;
    }
  }
  if (!y) cout << "NO\n";
  return 0;
}
