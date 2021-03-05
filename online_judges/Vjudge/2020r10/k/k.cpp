#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

typedef long long ll;
const int N = 2 * 1e5 + 100;

ll n, q, arr;
ll warr[N], strength[N];

ll sum(int l, int r) {
  if (l <= r) {
    return warr[r] - warr[l - 1];
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> warr[i];
    strength[i] = warr[i];
  }
  warr[n + 1] = 1e9;
  strength[n + 1] = 1e9 + 100;
  for (int i = 1; i <= n; ++i) {
    warr[i + 1] += warr[i];
    //cout << warr[i] << " ";
  }
  //cout << "\n";
  ll cur = 1, curHealth = strength[1];
  for (int i = 0; i < q; ++i) {
    cin >> arr;
    ll l = cur, h = n + 1;
    while (l < h) {
      ll m = (l + h + 1) / 2;
      ll sum = warr[m] - warr[cur] + curHealth;
      //cerr << l << ", " << h << "\n";
      //cerr << m << " " << sum << "\n";
      if (sum > arr) {
        h = m - 1;
      } else {
        l = m;
      }
    }
    if (cur == l && curHealth > arr) {
      curHealth -= arr;
    } else {
      arr -= curHealth;
      arr -= sum(cur + 1, l);
      cur = l + 1;
      curHealth = strength[cur] - arr;
    }
    if (cur >= n + 1) {
      cur = 1;
      curHealth = strength[cur];
    }
    //cout << l << ":l\n";
    //cout << n - cur + 1 << " cur:" << cur << " curHealth:" << curHealth << "\n";


    cout << n - cur + 1 << "\n";
  }


  return 0;
}
