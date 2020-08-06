#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

typedef pair<int, int> pii;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, S, Smi = 0, Sma = 0;
  cin >> n >> S;
  int mi, ma;
  vector<pii> v;
  for (int i = 0; i < n; ++i) {
    cin >> mi >> ma;
    Smi += mi;
    Sma += ma;
    v.push_back({mi, ma});
  }
  if (Smi <= S && S <= Sma) {
    cout << "YES\n";
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
      ans[i] = v[i].first;
    }
    S -= Smi;
    for (int i = 0; i < n; ++i) {
      int add = min(S, v[i].second - v[i].first);
      S -= add;
      ans[i] += add;
    }
    for (int i = 0; i < n; ++i) {
      cout << ans[i] << " ";
    }
  } else {
    cout << "NO\n";
  }
  return 0;
}
