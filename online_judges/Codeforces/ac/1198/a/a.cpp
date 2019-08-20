#include<bits/stdc++.h>
using namespace std;

const int N = 4 * 1e5;
int arr[N], cnt[N];
int n, I;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  cin >> n >> I;
  
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
  sort(arr, arr + n);

  int k;

  for (k = 0; k <= 19; ++k)
    if (n * (k + 1) > 8 * I)
      break;
  
  int K = (1 << k);
  
  vector<int> compressed;
  compressed.push_back(1);
  for (int i = 1; i < n; ++i) {
    if (arr[i] != arr[i - 1]) {
      compressed.push_back(1);
      compressed[compressed.size() - 1] += compressed[compressed.size() - 2];
    } else {
      ++compressed[compressed.size() - 1];
    }
  }
  int nn = compressed.size(); 
  if (K >= nn) {
    cout << 0;
  } else {
    int ans = n;
    for (int i = 0; i < nn - K + 1; ++i) {
      int changed = compressed[nn - 1] - compressed[i + K - 1] + (i > 0 ? compressed[i - 1] : 0);
      ans = min(ans, changed);
    }
    cout << ans;
  }
  return 0;
}
