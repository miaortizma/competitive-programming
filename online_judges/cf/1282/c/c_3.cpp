#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// By Miguel Ortiz https://github.com/miaortizma

const int N = 2 * 1e5 + 10;
struct problem {
  int time, diff;
  problem() : time(0), diff(0) {}
  problem(int a, int b) : time(a), diff(b) {}
} problems[N];

bool cmp(problem lh, problem rh) {
  return lh.time < rh.time;
}

int n, t, tmp;
ll a, b;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> t >> a >> b;
    ll ca, cb, ala, alb;
    ca = cb = ala = alb = 0;
    for (int i = 0; i < n; ++i) {
      cin >> tmp;
      problems[i].diff = tmp;
      if (tmp == 0) ala++;
      else alb++;
    }
    for (int i = 0; i < n; ++i) {
      cin >> tmp;
      problems[i].time = tmp;
    }
    sort(problems, problems + n, cmp);
    ll ans = 0;
    if (problems[0].time - 1 > 0) {
      ll time = problems[0].time - 1;
      if (time >= ca * a + cb * b) {
        // grab greedily a's and b's
        ll left = time - (ca * a + cb * b);
        ll willa = 0, willb = 0;
        ll la = ala - ca, lb = alb - cb;
        willa = min(left / a, la);
        left -= willa * a;
        willb = min(left / b, lb);
        ans = max(ans, ca + cb + willa + willb);
      }
    }
    for (int i = 0; i < n; ++i) {
      int time = problems[i].time;
      if (problems[i].diff == 0) ca++;
      else cb++;
      while (i + 1 < n && problems[i + 1].time == problems[i].time) {
        if (problems[i + 1].diff == 0) ca++;
        else cb++;
        ++i;
      }
      if (i + 1 < n) {
        // last moment till next compulsory problem
        time = max(time, problems[i + 1].time - 1);
      } else {
        // exam end
        time = max(time, t);
      }
      // problems can be solved 
      if (time >= ca * a + cb * b) {
        // grab greedily a's and b's
        ll left = time - (ca * a + cb * b);
        ll willa = 0, willb = 0;
        ll la = ala - ca, lb = alb - cb;
        willa = min(left / a, la);
        left -= willa * a;
        willb = min(left / b, lb);
        ans = max(ans, ca + cb + willa + willb);
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
