#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 1;
int n, S;
int arr[N];

ll simul(int m) {
  if (m == 0)
    return 0;
  priority_queue<ll> pq;
  ll Ss = 0;
  for (int i = 1; i <= n; ++i) {
    ll val = arr[i] + i * 1LL * m;
    if (pq.size() < m) {
      Ss += val;
      pq.push(val);
    } else if (val < pq.top()){
      Ss -= pq.top();
      pq.pop();
      pq.push(val);
      Ss += val;
    }
  } 

  return Ss;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  cin >> n >> S;
  for (int i = 1; i <= n; ++i)
    cin >> arr[i];

  int l = 0, h = n;
  while (l < h) {
    int m = l + (h - l + 1) / 2;
    if (simul(m) <= S)
      l = m;
    else
      h = m - 1;
  }
  
  cout << l << ' ' << simul(l);
  return 0;
}
