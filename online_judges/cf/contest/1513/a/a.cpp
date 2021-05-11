/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: mia_ortizma
 * Time: 2021-04-11 09:35:02
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--)
  {
    int N, K;
    cin >> N >> K;
    stack<int> vals;
    for (int i = 1; i <= N; ++i)
      vals.push(i);

    int posb = (N - 2 + 1) / 2;
    if (K > posb)
    {
      cout << -1;
    }
    else
    {
      vector<int> ans(N);
      for (int i = 0; i < K; ++i)
      {
        ans[1 + 2 * i] = vals.top();
        vals.pop();
      }
      for (int i = 0; i < N; ++i)
      {
        if (ans[i] == 0)
        {
          ans[i] = vals.top();
          vals.pop();
        }

        cout << ans[i] << " ";
      }
    }
    cout << "\n";
  }
  return 0;
}