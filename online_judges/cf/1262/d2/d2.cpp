#include<bits/stdc++.h>
using namespace std;

const int N = 2 * 1e5 + 100;

int arr[N], ans[N], bit[N];
int n, m, k, ki, pi, nn;

int get(int i) {
  int ret = 0;
  for (++i; i > 0; i -= i & -i) ret += bit[i];
  return ret;
}

void add(int i, int v) {
  for(++i; i <= n; i += i & -i) bit[i] += v;
}

int find_(int x) {
  int l = 0, h = n - 1;
  while (l < h) {
    int m = l + (h - l) / 2;
    int xm = get(m);
    if (xm < x)
      l = m + 1;
    else
      h = m;
  }
  return l;
}

vector<int> poss[N];
struct query {
  int k, p, i; 
  query() : k(0), p(0), i(0) {}
  query(int k, int p, int i) : k(k), p(p), i(i) {}
} queries[N];

struct dta {
  int v, i; 
  dta() : v(0), i(0) {}
  dta(int v, int i) : v(v), i(i) {}
} arr2[N];

bool cmp(query lh, query rh) {
  if (lh.k == rh.k)
    return lh.p < rh.p;
  return lh.k < rh.k;
}

bool cmp1(dta lh, dta rh) {
  if (lh.v == rh.v)
    return lh.i < rh.i;
  return lh.v > rh.v;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    arr2[i] = {arr[i], i};
  }
  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> ki >> pi;
    queries[i] = {ki, pi, i};
  }
  sort(queries, queries + m, cmp);
  sort(arr2, arr2 + n, cmp1);
  vector<int> fposs;
  for (int i = 0; i < n; ++i) {
    fposs.push_back(arr2[i].i);
  }
  int Iq = 0;
  k = 0;
  for (int i = 0; i < n; ++i) {
    ++k;
    int idx = fposs[i];
    add(idx, 1);
    if (queries[Iq].k != k)
      continue;
    int p = 0, fp;
    while (Iq < m && queries[Iq].k == k) {
      if (queries[Iq].p != p) {
        fp = find_(queries[Iq].p);
        p = queries[Iq].p;
      }
      ans[queries[Iq].i] = fp;
      ++Iq;
    }
    if (Iq == m)
      break;
  }
  for (int i = 0; i < m; ++i) {
    cout << arr[ans[i]] << "\n";
  }
  return 0;
}
