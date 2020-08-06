#include<bits/stdc++.h>
using namespace std;

const int N = 2 * 1e5 + 10;
typedef pair<int, int> pii;

bool marked[N];
int leftmost[N], rightmost[N];
int arr[N], sz[N];
int ans[N];

int root(int i) {
  while (i != arr[i]) {
    arr[i] = arr[arr[i]];
    i = arr[i];
  }
  return i;
}

void merge(int u, int v) {
  u = root(u), v = root(v);
  if (u == v)
    return;
  if (sz[u] < sz[v])
    swap(u, v);
  if (sz[u] == sz[v])
    ++sz[u];
  arr[v] = u;
  leftmost[u] = min(leftmost[u], leftmost[v]);
  rightmost[u] = max(rightmost[u], rightmost[v]);
}

int n, k, t;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  cin >> n >> k;
  priority_queue<pii> pq;
  for (int i = 1; i <= n; ++i) {
    cin >> t;
    arr[i] = leftmost[i] = rightmost[i] = i;
    pq.push(pii({t, i}));
  }
  int change = 1 ^ 2;
  int turn = 2;
  while (pq.size()) {
    pii u = pq.top();
    pq.pop();
    if (marked[u.second])
      continue;
    turn ^= change;
    int v = u.second;
    ans[v] = turn;
    marked[v] = true;
    leftmost[v] = v - 1;
    rightmost[v] = v + 1;
    int i = 0;
    while (leftmost[v] != 0 && i < k) {
      if (!marked[leftmost[v]]) {
        leftmost[leftmost[v]] = leftmost[v] - 1;
        marked[leftmost[v]] = true;
        ans[leftmost[v]] = turn;
        ++i;
      }
      merge(leftmost[v], v);
      v = root(v);
    }
    i = 0;
    while (rightmost[v] != n + 1 && i < k) {
      if (!marked[rightmost[v]]) {
        rightmost[rightmost[v]] = rightmost[v] + 1;
        marked[rightmost[v]] = true;
        ans[rightmost[v]] = turn;
        ++i;
      }
      merge(rightmost[v], v);
      v = root(v);
    }
  }

  for (int i = 1; i <= n; ++i) {
    cout << ans[i];
  }
  return 0;
}
