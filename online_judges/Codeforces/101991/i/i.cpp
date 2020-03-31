#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

bool cmp(pii lh, pii rh) {
  if (lh.first == rh.first) {
    return lh.second > rh.second;
  }
  return lh.first < rh.first;
}

const int N = 1e5 + 100;
pii arr[N];

int main() {
  freopen("icecream.in", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    long long n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> arr[i].first;
    for (int i = 0; i < n; ++i) cin >> arr[i].second;
    sort(arr, arr + n, cmp);
    ll a = 0;
    priority_queue<ll> pq;
    for (int i = 0; i < k; ++i) a = max(a, arr[i].first);
    for (int i = 0; i < n; ++i) {
      if (arr[i].first > a) break;
      pq.push(arr[i].second);
    }
    ll b = 0;
    for (int i = 0; i < k; ++i) {
      b += pq.top(); pq.pop();
    }
    cout << a << " " << b << "\n";
  }
  return 0;
}
