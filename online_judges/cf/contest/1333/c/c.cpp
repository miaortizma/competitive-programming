#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

const int MAXN = 2 * 1e5 + 100;
typedef long long ll;
ll pre[MAXN];
map<ll, int> counts;
int N, tmp;

ll solve(vector<int> arr) {
  int n = arr.size();
  for (int i = 1; i <= n; ++i) {
    //cerr << arr[i - 1] << " "; 
    pre[i] = arr[i - 1] + pre[i - 1];
  }
  //cerr << "\n";
  ll ret = 0;
  int l = 0;
  counts[pre[l]] = 1;
  // (l, r]
  for (int r = 1; r <= n; ++r) {
    ll val = pre[r];
    while(counts[val] != 0) counts[pre[l++]]--;
    //cerr << pre[r] << "\n";
    //cerr << l << " " << r << "\n";
    ret += r - l;
    counts[val]++;
  }
  while(l <= n) counts[pre[l++]]--;
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> N;
  vector<int> arr;
  ll ans = 0;
  for (int i = 1; i <= N; ++i) {
    cin >> tmp;
    if (tmp == 0) {
      if (!arr.empty()) {
        ans += solve(arr);
        arr.clear();
      }
    } else {
      arr.push_back(tmp);
    }
  }
  if (!arr.empty()) {
    ans += solve(arr);
  }

  cout << ans;


  return 0;
}
