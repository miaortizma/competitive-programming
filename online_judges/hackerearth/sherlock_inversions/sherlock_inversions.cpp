#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e5 + 100;
pii uncompressed[N];
int arr[N];
struct query { int a, b; } queries[N];
bool cmp (query lh, query rh) { return lh.a < rh.a; }

int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, q, a, b;
  cin >> n >> q;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    uncompressed[i] = {arr[i], i};
  }
  sort(uncompressed, uncompressed + n);
  for (int i = 0; i < q; ++i) {
    cin >> a >> b;
    queries[i] = {a, b};
  }
  sort(queries, queries + q, cmp);
  int l = n;
  for (int i = 0; i < q; ++i) {
    cout << queries[i].a << ' ' << queries[i].b << '\n';
  }
  return 0;
}
