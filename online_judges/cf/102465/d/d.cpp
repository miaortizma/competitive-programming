#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

typedef long long ll;
typedef pair<ll, ll> pll;
vector<pll> v, lines;
int X, Y, N;

ll d(ll y, pll line) {
  ll y0 = line.first, y1 = line.second;
  if (y < y0) {
    return y0 - y;
  } else if (y > y1) {
    return y - y1;
  } else {
    return 0;
  }
}

ll f(ll y) {
  ll S = X - 1;
  for (size_t i = 0; i < lines.size(); ++i) {
    S += 2 *(d(y, lines[i]) + lines[i].second - lines[i].first);
  }
  return S;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  ll x, y;
  cin >> X >> Y;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> x >> y;
    pll p{x, y};
    v.push_back(p);
  }
  sort(v.begin(), v.end());
  ll last_x = -1;
  for (int i = 0; i < N; ++i) {
    x = v[i].first, y = v[i].second;
    if (x != last_x) {
      lines.push_back({y, y});
    }
    int s = lines.size() - 1;
    ll y0 = lines[s].first, y1 = lines[s].second;
    lines[s].first = min(y0, y);
    lines[s].second = max(y1, y);
    last_x = x;
  }
  ll l = 0, h = Y - 1;
  while (l < h) {
    ll m = (l + h) >> 1;
    ll f0 = f(m), f1 = f(m + 1);
    if (f1 > f0) {
      h = m;
    } else if (f0 > f1) {
      l = m + 1;
    } else {
      l = m;
      break;
    }
  }
  cout << min(f(l), f(l - 1));
  return 0;
}
