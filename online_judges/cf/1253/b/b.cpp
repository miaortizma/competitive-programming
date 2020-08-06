#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100, M = 1e6 + 100;
int arr[N], in[M], out[M];
int flag = 0;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
  bool ok = true;
  if (n % 2 == 1)
    ok = false;
  int i = 0;
  vector<int> ans;
  while (i < n && ok) {
    if (arr[i] < 0) {
      ok = false;
      break;
    }
    ++flag;
    in[arr[i]] = flag;
    int sum = arr[i];
    int left = 1;
    int cnt = 0;
    while (i < n && sum != 0 && left != 0) {
      ++i;
      int val = abs(arr[i]);
      if (arr[i] < 0) {
        if (in[val] == flag && out[val] != flag) {
          ++cnt;
          out[val] = flag;
          sum += arr[i];
          --left;
        } else {
          ok = false;
          i = n;
          break;
        }
      } else {
        if (in[val] != flag) {
          in[val] = flag;
          ++left;
          sum += arr[i];
        } else {
          ok = false;
          i = n;
          break;
        }
      }
    }
    if (sum != 0)
      ok = false;
    ans.push_back(cnt * 2);
    ++i;
  }
  if (ok) {
    cout << ans.size() << "\n";
    for (int v : ans) {
      cout << v << " ";
    }
  } else {
    cout << -1;
  }
  return 0;
}
