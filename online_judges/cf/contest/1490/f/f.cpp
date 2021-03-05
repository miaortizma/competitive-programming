#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

const int N = 2 * 1e5;
int arr[N], counts[N], ccounts[N];
int pre[N], up[N];


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }
    sort(arr, arr + n);
    counts[0] = 1;
    int I = 1;
    for (int i = 1; i < n; ++i) {
      //cerr << arr[i] << " ";
      if (arr[i] == arr[i - 1]) {
        counts[I - 1]++;
      } else {
        counts[I++] = 1;
      }
    }
    //cerr << "---\n";
    sort(counts, counts + I);
    vector<int> values;
    values.push_back(counts[0]);
    ccounts[counts[0]] = 1;
    for (int i = 1; i < I; ++i) {
      //cerr << counts[i] << " ";
      if (counts[i] != counts[i - 1]) {
        values.push_back(counts[i]);
        ccounts[counts[i]] = 1;
      } else {
        ccounts[counts[i]]++;
      }
    }
    int NN = values.size();
    //cerr << "\n values: \n";
    for (int i = 0; i < NN; ++i) {
      int x = values[i];
      //cerr << x << " " << ccounts[x] << "\n";
    }
    int uptot = ccounts[values[NN - 1]];
    //cerr << "\n up: \n";
    up[NN - 1] = 0;
    for (int i = NN - 2; i >= 0; --i) {
      int x = values[i], x1 = values[i + 1];
      up[i] = up[i + 1] + (x1 - x) * uptot;
      uptot += ccounts[x];
      //cerr << up[i] << " ";
    }

    int ans = 1e9;
    int pre = 0;
    for (int i = 0; i < NN; ++i) {
      int x = values[i];
      int cur = pre + up[i];
      //cerr << " testing: " << x << " " << cur << "\n";
      ans = min(ans, cur);
      pre += x * ccounts[x];
    }

    //cerr << "\n\n\n";
    cout << ans << "\n";

  }
  return 0;
}
