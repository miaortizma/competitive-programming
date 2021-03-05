#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

typedef long long ll;
typedef pair<ll, ll> pii;
const int MAXN = 2 * 1e5;

ll arr[MAXN];
ll n, m, x, t;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    ll s = 0;
    vector<pii> st;

    int stN = st.size();
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
      s += arr[i];
      //cerr << arr[i] << " ";
      stN = st.size();
      if (s > 0 && (stN == 0 || s > st[stN - 1].first)) {
        st.push_back({s, i});
      }
    }
    //cerr << "\n";
    stN = st.size();

    for (int i = 0; i < m; ++i) {
      cin >> x;

      if (stN == 0 || (st[stN - 1].first < x && s <= 0)) {
        cout << -1 << " ";
      } else {
        ll j = 0;
        if (st[stN - 1].first < x) {
          j = max(0ll, x - st[stN - 1].first + s - 1) / s;
        }
        //cerr << "x: " << x << " j: " << j << "\n";
        int l = 0, h = stN - 1;
        while (l < h) {
          int m = (l + h) / 2;
          ll val = st[m].first + s * 1ll * j;
          if (val < x) {
            l = m + 1;
          } else {
            h = m;
          }
        }
        ll ans = n * 1ll * j + st[l].second;
        cout << n * j + st[l].second << " ";
      }
    }
    cout << "\n";
    //cerr << "\n";
    /*
    cerr << "s: " << s << "\n";
    for (auto [a, b] : st) {
      cerr << a << " " << b << "\n";
    }
    cerr << "------\n";
    */
  }


  return 0;
}
