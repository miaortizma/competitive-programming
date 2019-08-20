#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 501;

int d[N][N];

int n, tmp;


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
 
  cin >> n;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      cin >> d[i][j];

  vector<int> v;
  
  for (int i = 0; i < n; ++i) {
    cin >> tmp;
    v.push_back(tmp);
  }

  vector<ll> ans;
  for (int k = n - 1; k >= 0; --k) {
    ll curr = 0;
    for (int i = n - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        int ii = v[i], jj = v[j], kk = v[k];
        if (d[ii][jj] > d[ii][kk] + d[kk][jj])
          d[ii][jj] = d[ii][kk] + d[kk][jj];

        if (i >= k && j >= k)
          curr += d[ii][jj];
      }
    }
    ans.push_back(curr);
  }
  
  for (int i = n - 1; i >= 0; --i)
    cout << ans[i] << ' ';

  return 0;
}
