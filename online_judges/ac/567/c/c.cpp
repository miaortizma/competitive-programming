#include<bits/stdc++.h>
using namespace std;

const int N = 2 * 1e5;

int n, k, tmp, dd;
long long ans;
map<int, long long> one, two;

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> tmp;
    if (tmp % k == 0) {
      dd = tmp / k;
      if (dd % k == 0)
        ans += two[dd];
      
      two[tmp] += one[dd];
    }
    ++ one[tmp];
  }

  cout << ans;

  return 0;
}
