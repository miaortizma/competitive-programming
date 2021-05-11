/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: mia_ortizma
 * Time: 2021-05-07 09:35:02
**/

#include <bits/stdc++.h>
using namespace std;

template<typename T> ostream& operator<<(ostream& os, vector<T>  v) { for (auto& i : v) os << i << ' '; return os; }
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;

    vector<pii> cands;
    int its = 0;
    auto ask = [&](int tp, int i, int j, int x) {
      cout << "? " << tp << ' ' << i << ' ' << j << ' ' << x << endl;
      ++its;
      assert(its <= N * 1.5 + 30);
      int ans;
      cin >> ans;
      return ans;
    };
    int q;
    for (int i = 1; i + 1 <= N; i += 2) {
      q = ask(1, i, i + 1, N - 1);
      if (q >= N - 1) {
        cands.push_back({ i , i + 1 });
      }
    }
    if (N % 2 == 1) {
      cands.push_back({ N - 1, N });
    }
    int pos = 0;
    for (auto [a, b] : cands) {
      if (ask(2, a, b, N - 1) == N) {
        pos = a;
        break;
      }
      if (ask(2, b, a, N - 1) == N) {
        pos = b;
        break;
      }
    }

    vector<int> ans(N);

    for (int i = 1; i <= N; ++i) {
      if (i != pos) {
        int q = ask(2, i, pos, 1);
        ans[i - 1] = q;
      }
      else {
        ans[i - 1] = N;
      }
    }
    cout << "! " << ans << endl;
  }

  return 0;
}
