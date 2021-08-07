/* Generated by powerful Codeforces Tool
 * You can download the binary file in here https://github.com/xalanq/cf-tool (Windows, macOS, Linux)
 * Author: mia_ortizma
 * Time: 2021-05-30 07:33:32
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int mat[800][800];

int main()
{
  cin.tie(0), cout.sync_with_stdio(0);
  int N, K;
  cin >> N >> K;
  // comp: (N - K) ** 2 log (K)
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> mat[i][j];
      ans = max(ans, mat[i][j]);
    }
  }
  int move = N - K + 1;
  int median_i = (K * K) - ((K * K) / 2 + 1);
  for (int i = 0; i < move; ++i) {
    multiset<int> g; // upper half of array
    multiset<int, greater<int>> s; // descending, lower half of array
    int med = mat[i][0];
    s.insert(med);
    for (int p = 0; p < K; ++p) {
      for (int q = 0; q < K; ++q) {
        if (p == 0 && q == 0) continue;
        int x = mat[i + p][q];
        // Only add elements to upper half if 
      // its size less then the size of the
      // lower half (maintain only difference
      // of 1)
        if (s.size() > g.size()) {
          if (x < med) {
            int temp = *s.begin();
            s.erase(s.begin());
            g.insert(temp);
            s.insert(x);
          }
          else
            g.insert(x);

          med = *s.begin() > *g.begin() ?
            *g.begin() : *s.begin();
        }

        // Only add elements to lower half if 
        // it's size less then the size of the 
        // upper half (maintain only difference
        // of 1)
        else if (s.size() < g.size()) {
          if (x > med) {
            int temp = *g.begin();
            g.erase(g.begin());
            s.insert(temp);
            g.insert(x);
          }
          else
            s.insert(x);

          med = *s.begin() > *g.begin() ?
            *g.begin() : *s.begin();
        }

        // If sizes are same
        else {
          if (x > med) {
            g.insert(x);
            med = *g.begin();
          }
          else {
            s.insert(x);
            med = *s.begin();
          }
        }

      }
    }

    for (int j = 0; j < move; ++j) {

    }
  }

  return 0;
}
