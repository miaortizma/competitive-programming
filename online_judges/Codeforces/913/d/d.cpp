#include<bits/stdc++.h>
using namespace std;

const int N = 2 * 1e5 + 100;
int n, k, ai, ti;

struct pr {
  int t, a, i;
  pr () : t(0), a(0), i(0) {}
  pr (int t, int a, int i) : t(t), a(a), i(i) {}
} arr[N];

bool f(int m) {
  int cnt = 0, left = k;
  for (int i = 0; i < n; ++i) {
    if (arr[i].a >= m) {
      if (arr[i].t <= left) {
        cnt++;
        left -= arr[i].t;
        if (cnt == m)
          break;
      } else {
        break;
      }
    }
  }
  return cnt == m;
}

bool cmp(pr lh, pr rh) {
  return lh.t < rh.t;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> ai >> ti;
    arr[i] = {ti, ai, i + 1};
  }
  sort(arr, arr + n, cmp);
  int l = 0, h = n;
  while (l < h) {
    int m = l + (h - l + 1) / 2;
    if (f(m))
      l = m;
    else
      h = m - 1;
  }
  cout << l << "\n";
  vector<int> pick;
  int cnt = 0, left = k;
  for (int i = 0; i < n; ++i) {
    if (arr[i].a >= l) {
      if (arr[i].t <= left) {
        cnt++;
        pick.push_back(arr[i].i);
        left -= arr[i].t;
        if (cnt == l)
          break;
      } else {
        break;
      }
    }
  }
  cout << pick.size() << "\n";
  for (int v : pick) {
    cout << v << " ";
  }
  return 0;
}
