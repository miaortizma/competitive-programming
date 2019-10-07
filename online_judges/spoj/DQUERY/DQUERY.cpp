#include<bits/stdc++.h>
using namespace std;

const int N = 3 * 1e4 + 100, Q = 4 * 1e5 + 100;
map<int, int> rightmost;
int arr[N], BIT[N], ans[Q];

struct query { int a, b, i; };
bool cmp(query lh, query rh) { return lh.b < rh.b; }

void add(int i, int x) {
  for (; i < N; i += i & -i)
    BIT[i] += x;
}

int sum(int i) {
  int ret = 0;
  for (; i > 0; i -= i & - i)
    ret += BIT[i];
  return ret;
}

int sum2(int a, int b) { return sum(b) - sum(a - 1); }

int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, q, a, b;
  cin >> n;

  for (int i = 1; i <= n; ++i)
    cin >> arr[i];

  cin >> q;
  vector<query> queries;
  for (int i = 0; i < q; ++i) {
    cin >> a >> b;
    query q{a, b, i};
    queries.push_back(q);
  }
  sort(queries.begin(), queries.end(), cmp);
  int r = 0;
  for (int i = 0; i < q; ++i) {
    while (r < queries[i].b) {
      ++r;
      int val = arr[r];
      if (rightmost.count(val)) {
        add(rightmost[val], -1);
        add(r, +1);
      } else {
        add(r, +1);
      }
      rightmost[val] = r;
    }
    ans[queries[i].i] = sum2(queries[i].a, queries[i].b);
  }
  for (int i = 0; i < q; ++i)
    cout << ans[i] << '\n';
  return 0;
}
