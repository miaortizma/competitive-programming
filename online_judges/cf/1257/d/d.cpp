#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, m;
 
const int N = 2 * 1e5 + 100;
int arr[N];
pii heros[N];
int hero[N], heroc[N];
int mmonster = 0, mhero = 0;
 
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t, a, b;
  cin >> t;
  while (t--) {
    mmonster = mhero = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
      mmonster = max(mmonster, arr[i]);
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
      cin >> a >> b;
      heros[i] = {b, a};
      mhero = max(mhero, a);
    }
    if (mmonster > mhero) {
      cout << -1 << "\n";
      continue;
    }
    sort(heros, heros + m);
    vector<pii> hf;
    int last = 0;
    for (int i = m - 1; i >= 0; --i) {
      if (heros[i].second > last)
        hf.push_back(heros[i]);
      last = max(heros[i].second, last);
    }
 
    vector<int> to_compress;
    for (int i = 0; i < n; ++i) {
      to_compress.push_back(arr[i]);
    }
    for (int i = 0, mm = hf.size(); i < mm; ++i) {
      to_compress.push_back(hf[i].second);
    }
    sort(to_compress.begin(), to_compress.end());
    unordered_map<int, int> compressed;
    int I = 0;
    compressed[to_compress[0]] = ++I;
    for (int i = 1, mm = to_compress.size(); i < mm; ++i) {
      if (to_compress[i] != to_compress[i - 1]) {
        compressed[to_compress[i]] = ++I;
      }
    }
    for (int i = 0; i < n; ++i) {
      arr[i] = compressed[arr[i]];
    }
    for (int i = 0, mm = hf.size(); i < mm; ++i) {
      hf[i].second = compressed[hf[i].second];
    }
 
    hf.push_back({0, 0});
    
    for (int i = 0, mm = hf.size(); i < mm - 1; ++i) {
      int lim = 0;
      if (i > 0)
        lim = hf[i - 1].second;
      for (int j = hf[i].second; j > lim; --j)
        heroc[j] = hf[i].first;
      for (int j = hf[i].first; j > hf[i + 1].first; --j) {
        hero[j] = hf[i].second;
      }
    }
    int cur = 0;
    int ans = 0;
    while (cur < n) {
      int s = heroc[arr[cur]];
      int c = hero[s];
      int i = 0;
      while (i + cur < n && i < s) {
        if (arr[cur + i] > c) {
          if (heroc[arr[cur + i]] > i) {
            s = heroc[arr[cur + i]];
            c = hero[s];
            i++;
          } else {
            break;
          }
        } else {
          i++;
        }
      }
      cur = i + cur;
      ++ans;
    }
    cout << ans << "\n";
  }
  return 0;
}
