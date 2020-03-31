#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2 * 1e5 + 100;
int arr[N];

priority_queue<ll, vector<ll>, greater<ll>> pq;

int main() {
	ios::sync_with_stdio(false);cin.tie(NULL);
	int n;
	cin >> n;
  for (int i = 0; i < n; ++i) cin >> arr[i];
  if (n % 2 == 0) ++n;
  for (int i = 0; i < n; ++i) pq.push(arr[i]);
  ll ans = 0;
  while (pq.size() > 1) {
    ll cur = 0;
    for (int i = 0; i < 3; ++i) {
      ll v = pq.top(); pq.pop();
      ans += v;
      cur += v;
    }
    pq.push(cur);
  }
  cout << ans;
	return 0;
}
