#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma


const int N = 1e5 + 10;
int arr[N], dp[N], zero[N];
int n;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i <= n; ++i) {
      dp[i] = 0;
    }
    string s;
    cin >> s;
    for (int i = 1; i <= n; ++i) {
      arr[i] = atoi("" + s[i - 1]);
    }

    for (int i = 1; i <= n; ++i) {
      if (arr[i] == 1) {
        dp[i] += 1;
      }
    }

  }
  return 0;
}
