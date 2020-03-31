#include<bits/stdc++.h>
using namespace std;
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

int n, t, a, b, tmp;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> t >> a >> b;
    int ans = 0;
    int ca, cb, ala, alb;
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
    /*
    for (int i = 0; i < n; ++i) {
      cerr << problems[i].time << " " << problems[i].diff << "\n";
    }
    */
    if (problems[0].time - 1 > 0) {
      int time = problems[0].time - 1;
      if (time >= ca * a + cb * b) {
        // grab greedily a's and b's
        int left = time - (ca * a + cb * b);
        //cerr << "left: " << left << "\n";
        int willa = 0, willb = 0;
        int la = ala - ca, lb = alb - cb;
        if (ala > 0) willa = min(left / ala, la);
        left -= willa * a;
        if (alb > 0) willb = min(left / alb, lb);
        //cerr << "willa: " << willa << " willb: " << willb << "\n";
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
        //cerr << i << "\n";
      }
      if (i + 1 < n) {
        // last moment till next compulsory problem
        time = max(time, problems[i + 1].time - 1);
      } else {
        // exam end
        time = max(time, t);
      }
      //cerr << "time: " << time << "\n";
      //cerr << "ca: " << ca << " cb:" << cb << "\n";
      // problems can be solved 
      if (time >= ca * a + cb * b) {
        // grab greedily a's and b's
        int left = time - (ca * a + cb * b);
        //cerr << "left: " << left << "\n";
        int willa = 0, willb = 0;
        int la = ala - ca, lb = alb - cb;
        if (ala > 0) willa = min(left / ala, la);
        left -= willa * a;
        if (alb > 0) willb = min(left / alb, lb);
        //cerr << "willa: " << willa << " willb: " << willb << "\n";
        ans = max(ans, ca + cb + willa + willb);
      }
      //cerr << "safe\n";
    }
    //cerr << "@@@@\n";
    cout << ans << "\n";
  }
  return 0;
}
