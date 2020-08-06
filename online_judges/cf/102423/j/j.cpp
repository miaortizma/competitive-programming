#include<bits/stdc++.h>
using namespace std;

const int N = 2 * 1e5 + 100;
int arr[N], cnt[N], t[2 * N];
vector<int> poss[N];
int n, k;

void build() {
  for (int i = n - 1; i > 0; --i) t[i] = min(t[i<<1], t[i<<1|1]);
}

void modify(int p, int value) {
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = min(t[p], t[p ^ 1]);
}

int query(int l, int r) {
  int res = N;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res = min(res, t[l++]);
    if (r & 1) res = min(res, t[--r]);
  }
  return res;
}


int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
    int v = arr[i];
    t[n + i] = v;
    cnt[v] += 1;
    poss[v].push_back(i);
  }
  build();
  vector<int> ans, lastp;
  for (int i = 0; i < n; ++i) {
    int v = arr[i];
    --cnt[v];
    if (cnt[v] == 0)
      lastp.push_back(i);
  }
  int r = 0;
  for (int i = 0; i < n; ++i) {
    int v = arr[i];
    if (query(i, lastp[r] + 1) == v) {
      ans.push_back(v);
      if ((int) ans.size() == k)
        break;
      for (int p : poss[v])
        modify(p, N);
    }
    while (r < k && query(lastp[r], lastp[r] + 1) == N) {
      r++;
    }
  }
  for (int v : ans)
    cout << v << " ";
  return 0;
}
