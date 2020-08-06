#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
// By Miguel Ortiz https://github.com/miaortizma

const int N = 2 * 1e5 + 10;
pii arr[N];
int n, t, tmp;
ll a, b, ala, alb, ca, cb;

ll solve(ll time) {
  if (ca * a + cb * b <= time) {
    time -= ca * a + cb * b;
    ll willa = 0, willb = 0;
    willa = min(ala - ca, time / a);
    time -= willa * a;
    willb = min(alb - cb, time / b);
    time -= willb * b;
    return ca + cb + willa + willb;
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> t >> a >> b;
    ca = cb = ala = alb = 0;
    for (int i = 0; i < n; ++i) {
      cin >> tmp;
      arr[i].second = tmp;
      if (tmp == 0) ala++;
      else alb++;
    }
    for (int i = 0; i < n; ++i) {
      cin >> tmp;
      arr[i].first = tmp;
    }
    sort(arr, arr + n);
    ll ans = 0;
    int last = 0;
    for (int i = 0; i < n; ++i) {
      if (arr[i].first != last) {
        ans = max(ans, solve(arr[i].first - 1));
      }
      if (arr[i].second == 0) ca++;
      else cb++;
      last = arr[i].first;
    }
    ca = ala;
    cb = alb;
    ans = max(ans, solve(t));
    cout << ans << "\n";
  }
  return 0;
}
