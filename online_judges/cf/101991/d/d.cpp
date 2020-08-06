#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, k, x, y;
ll ans;

ll get(ll x, ll y) {
  return (n - x + 1) * (m - y + 1);
}

void add(ll x, ll y, ll sgn, bool ad) {
  ll multp = 1;
  if (ad) multp = 2;
  cerr << x << " " << y << " " << (sgn ? ('+') : ('-')) << get(x, y) <<  "\n";
  if (sgn == 1) ans += multp * get(x, y);
  else ans -= multp * get(x, y);
}


int main() {
  freopen("dull.in", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    map<ll, vector<ll>> rows;
    cin >> n >> m >> k;
    ll mnx = n;
    for (int i = 0; i < k; ++i) {
      cin >> x >> y;
      rows[x].push_back(y);
      mnx = min(mnx, x);
    }
    for (auto &p : rows) {
      sort(p.second.begin(), p.second.end());
    }
    vector<pair<ll, ll>> cur;
    ans = 0;
    ll sgn = 1;
    for (ll v : rows[mnx]) {
      add(mnx, v, sgn, 0);
      cur.push_back({v, sgn});
      sgn ^= 1;
    }
    ll pre, last;
    for (auto &p : rows) {
      if (p.first == mnx) continue;
      vector<pair<ll, ll>> nex;
      vector<ll> v = p.second;
      size_t i = 0, j = 0;
      pre = last = 0;
      bool ad = false;
      while (i < cur.size() && j < v.size()) {
        if (cur[i].first < v[j]) {
          last = cur[i].second;
          if (ad) {
            nex.push_back({cur[i].first, pre ^ last});
            add(p.first, cur[i].first, pre ^ last, ad);
          } else {
            nex.push_back(cur[i]);
          }
          ++i;
        } else if (v[j] < cur[i].first) {
          pre ^= 1;
          nex.push_back({v[j], pre ^ last});
          add(p.first, v[j], pre ^ last, ad);
          ad = true;
          ++j;
        } else {
          last = cur[i].second;
          pre ^= 1;
          nex.push_back({cur[i].first, pre ^ last});
          add(p.first, cur[i].first, pre ^ last, ad);
          ad = true;
          ++i;
          ++j;
        }
      }
      while (i < cur.size()) {
        last = cur[i].second;
        if (ad) {
          nex.push_back({cur[i].first, pre ^ last});
          add(p.first, cur[i].first, pre ^ last, ad);
        } else {
          nex.push_back(cur[i]);
        }
        ++i;
      }
      while (j < v.size()) {
        pre ^= 1;
        nex.push_back({cur[i].first, pre ^ last});
        add(p.first, cur[i].first, pre ^ last, ad);
        ad = true;
        ++j;
      }
      cur = nex;
    }
    ll other = n * m  - ans;
    cerr << "@@@@@@@@\n";
    cout << ans << " " << other <<  "\n";
  }
  return 0;
}
