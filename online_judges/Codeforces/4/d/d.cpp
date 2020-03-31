#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

const int N = 5 * 1e3 + 100;

struct dta {
  int w, h, i;
  dta() : w(0), h(0), i(0) {}
  dta(int w, int h, int i) : w(w), h(h), i(i) {}
};

dta arr[N];

bool cmp(dta lh, dta rh) {
  if (lh.w == rh.w)
    return lh.h < rh.h;
  return lh.w < rh.w;
}

int dp[N], par[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, w, h;
  cin >> n >> w >> h;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    arr[i] = {a, b, i + 1};
  }
  memset(par, -1, sizeof par);
  sort(arr, arr + n, cmp);
  int ans = 0, b = -1;
  for (int i = n - 1; i >= 0; --i) {
    for (int j = i + 1; j < n; ++j) {
      if (arr[j].w > arr[i].w && arr[j].h > arr[i].h) {
        if (dp[j] + 1 > dp[i]) {
          par[arr[i].i] = arr[j].i;
          dp[i] = dp[j] + 1;
        }
      }
    }
    if (arr[i].w > w && arr[i].h > h) {
      if (dp[i] + 1 > ans) {
        ans = dp[i] + 1;
        b = arr[i].i;
      }
    }
  }
  if (b == -1) {
    cout << 0;
  } else {
    cout << ans << "\n";
    while (b != -1) {
      cout << b << " ";
      b = par[b];
    }
  }
  return 0;
}
