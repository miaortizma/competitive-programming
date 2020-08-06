#include<bits/stdc++.h>
using namespace std;

const int N = 1000, mod = 1e9 + 7;

int C[N+1][N+1];
int arr[N+1];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  C[0][0] = 1;
  for (int n = 1; n <= N; ++n) {
    C[n][0] = C[n][n] = 1;
    for (int k = 1; k < n; ++k)
      C[n][k] = (C[n - 1][k - 1] + C[n - 1][k]) % mod;
  }

  int n, tmp;
  long long ans = 1;
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];

  int s = arr[0];

  for (int i = 1; i < n; ++i) {
    if (arr[i] > 1) {
      int k = arr[i] - 1;
      ans = (ans * C[s + k][k]) % mod;
    }
    s += arr[i];
  }
  
  cout << ans; 
  return 0;
}
