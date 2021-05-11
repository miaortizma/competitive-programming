/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: mia_ortizma
 * Time: 2021-04-11 09:35:02
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll MOD = 1e9 + 7;

const int N_MAX = 2 * 1e5;
int arr[N_MAX];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--)
  {
    ll N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
      cin >> arr[i];
    }
    sort(arr, arr + N);

    ll mn = arr[0];
    ll cnt = 0;
    bool in = true;

    for (int i = 0; i < N; ++i)
    {
      ll x = arr[i];
      if (x == mn)
      {
        cnt++;
      }
      if ((mn & x) != mn)
      {
        in = false;
      }
      //in = ((mn & x) == mn);
    }
    if (in && cnt >= 2)
    {
      ll ans = cnt * (cnt - 1);
      ans %= MOD;
      for (ll i = 1; i <= N - 2; ++i)
      {
        ans = (ans * i) % MOD;
      }
      cout << ans << "\n";
    }
    else
    {
      cout << 0 << "\n";
    }
  }
  return 0;
}