#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, pair<ll, ll> > pii;
const int N = 2 * 1e5 + 100;
int arr[N];
int n, a, da, db, b, dc;
ll k;

vector<pii> v;

ll f(int m) {
  pii cur = v[m];
  int ca = cur.second.first, cb = cur.second.second, cd = m + 1 - ca - cb;
  ll ks = 0;
  for (int i = 0; i <= m; ++i) {
    if (cd) {
      --cd;
      ks += arr[i] / 100 * dc;
    } else if (ca) {
      --ca;
      ks += arr[i] / 100 * da;
    } else if (cb) {
      --cb;
      ks += arr[i] / 100 * db;
    }
  }
  return ks;
}

bool cmp(int lh, int rh) { return lh > rh; }

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int q;
  cin >> q;
  while (q--) {
    cin >> n;
    for (int i = 0; i < n; ++i)
      cin >> arr[i];
    sort(arr, arr + n, cmp);
    cin >> da >> a >> db >> b >> k;
    if (da < db) {
      swap(da, db);
      swap(a, b);
    }
    dc = da + db;
    int ia = a, ib = b;
    int preA = 0, preB = 0;
    while (ia <= n || ib <= n) {
      if (ia < ib) {
        v.push_back({ia, {++preA, preB}});
        ia += a;
      } else if (ia > ib) {
        v.push_back({ib, {preA, ++preB}});
        ib += b;
      } else {
        v.push_back({ia, {preA, preB}});
        ia += a;
        ib += b;
      }
    }
    int l = 0, h = v.size() - 1;
    while (l < h) {
      int m = l + (h - l) / 2;
      if (f(m) < k)
        l = m + 1;
      else 
        h = m;
    }
    if (f(l) >= k)
      cout << v[l].first;
    else
      cout << -1;
    cout << "\n";
    v.clear();
  }
  return 0;
}
